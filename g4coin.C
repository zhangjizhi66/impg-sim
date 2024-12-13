
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* source activity, larger than 1Bq */
//const double activity = 13527.74/1e9;  //  per ns; 133Ba
const double activity = 1000/1e9;  //  per ns; 67Ga

const double window = 200;          // ns; coincidence window
const double deadtime = 6000;        // ns; deadtime

struct Hit{
    Hit(int id1, double e1, double e01): id(id1), e(e1), e0(e01) {}
    
    int id;
    double e;
    double e0;
};

int getid(char *VolName)  // get volume id: rid[1-5] gid[1-8] tid[1-3]
{
    stringstream ss(VolName);
    string s;
    int rid, gid, tid;
    
    getline(ss,s,'_');
    if (s=="Ge") tid = 1;
    else if (s=="BGO") tid = 2;
    else if (s=="CsI") tid = 3;
    else return 0;
    
    getline(ss,s,'_');
    rid = atoi(s.c_str());
    
    getline(ss,s,'_');
    gid = atoi(s.c_str());
    
    return rid*100 + gid*10 + tid;
}

// add timestamp according to time interval distribution
void g4coin(TString foldername = "root")
{
    TChain *tree = new TChain("tree");
    tree->Add(Form("%s/g4raw_t*.root",foldername.Data()));

    double EDep,Egamma;
    //double GlobalTime;
    char VolName[100];
    tree->SetBranchAddress("EDep",&EDep);
    tree->SetBranchAddress("Egamma",&Egamma);
    //tree->SetBranchAddress("GlobalTimePre",&GlobalTime);
    tree->SetBranchAddress("VolNamePre",&VolName);
    
    TFile *opf = new TFile(Form("%s/g4coin.root",foldername.Data()),"RECREATE");
    TTree *opt = new TTree("tree","tree");
    
    int gid[10000],ghit = 0;
    double ge0[10000],ge[10000],gt[10000];
    opt->Branch("ghit",&ghit,"ghit/I");
    opt->Branch("ge0",&ge0,"ge0[ghit]/D");
    opt->Branch("ge",&ge,"ge[ghit]/D");
    opt->Branch("gt",&gt,"gt[ghit]/D");    // ns, timestamp
    opt->Branch("gid",&gid,"gid[ghit]/I");  // id
    
    // time interval distribution
    TF1 *f1 = new TF1("f1",Form("%.9f*exp(-%.9f*x)",activity,activity),0,10/activity);  // due to limited binning, xmax can't be too large
    f1->SetNpx(1e3);
    gRandom->SetSeed(0);

    clock_t start=clock(),stop=clock();
    
    Long64_t nentries = tree->GetEntries();
    Long64_t ts_trig = 0, ts_decay = 0;  // ns
    //double GlobalTime0 = 0;        // ns
    std::multimap<Long64_t, Hit> hitmap;
    
    for (Long64_t jentry=0; jentry<nentries; jentry++){
        tree->GetEntry(jentry);
        int id_this = getid(VolName);
        EDep *= 1000;
        Egamma *= 1000;
        
        if (id_this == 0) {
            ts_decay += f1->GetRandom();
            //GlobalTime0 = GlobalTime;
        }
        else {
            //Long64_t ts_this = ts_decay + Long64_t(GlobalTime - GlobalTime0);
            Long64_t ts_this = ts_decay;

            for (auto im=hitmap.begin(); im!=hitmap.end(); ) {
                if (ts_this - im->first > deadtime) {
                    if (im->first - ts_trig > window || ts_trig == 0) {
                        if (ts_trig > 0) opt->Fill();
                        ts_trig = im->first;
                        ghit = 0;
                    }
                    ge[ghit] = im->second.e;
                    ge0[ghit] = im->second.e0;
                    gt[ghit] = im->first - ts_trig;
                    gid[ghit] = im->second.id;
                    ghit++;
                    hitmap.erase(im++);
                }
                else 
                    break;
            }
            bool findid = false;
            for (auto im=hitmap.begin(); im!=hitmap.end(); im++) {
                if (im->second.id == id_this){
                    findid = true;
                    im->second.e += (deadtime-double(ts_this-im->first))/deadtime*EDep;
                    
                    if (int(im->second.e0*1e4) != int(Egamma*1e4))
                        im->second.e0 = -1;
                    break;
                }
            }
            if (!findid){
                Hit hit(id_this, EDep, Egamma);
                hitmap.insert(make_pair(ts_this, hit));
            }
        }
        
        // display progress and time needed
        if (jentry%100000 == 99999){
            stop = clock();
            printf("Process %.3f %%  Time remaining %02d min %02d s        \r",double(jentry)/double(nentries)*100.,
                int((stop-start)*(nentries-jentry)/jentry/1e6/60),
                int((stop-start)*(nentries-jentry)/jentry/1e6)%60);
            fflush(stdout);
        }
    }
    stop = clock();
    printf("Process %.3f %%  Total Time %02d min %02d s        \n",100.,int((stop-start)/1e6/60),int((stop-start)/1e6)%60);
    
    opt->Write();
    opf->Close();
    std::cout<<"Done!"<<'\n';
    gROOT->ProcessLine(".q");
}
