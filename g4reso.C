
// parameters of sigma curve
const double p0 = 0.7441208;
const double p1 = 3.14089132e-4;
const double p2 = 1.845081513e-8;

// convolute detector resolution
void g4reso(TString foldername = "root")
{
    TFile *ipf = new TFile(Form("%s/g4anticompton.root",foldername.Data()));
    TTree *tree = (TTree*)ipf->Get("tree");

    int ghit,ahit;
    double ge[10000],ae[10000];
    double ge0[10000],ae0[10000];
    
    tree->SetBranchAddress("ghit",&ghit);
    tree->SetBranchAddress("ge0",&ge0);
    tree->SetBranchAddress("ge",&ge);
    
    tree->SetBranchAddress("ahit",&ahit);
    tree->SetBranchAddress("ae0",&ae0);
    tree->SetBranchAddress("ae",&ae);
    
    TFile *opf = new TFile(Form("%s/g4reso.root",foldername.Data()),"RECREATE");
    TTree *opt = tree->CloneTree(0);
    
    int gIsFull[10000],aIsFull[10000];
    opt->Branch("gIsFull",&gIsFull,"gIsFull[ghit]/I");
    opt->Branch("aIsFull",&aIsFull,"aIsFull[ahit]/I");
    
    TRandom3 *gr = new TRandom3(0);
    TF1 *f1 = new TF1("f1","pol2",0,4000);
    f1->SetParameter(0,p0);
    f1->SetParameter(1,p1);
    f1->SetParameter(2,p2);
    
    clock_t start=clock(),stop=clock();

    int nentries = tree->GetEntries();
    for (int jentry=0; jentry<nentries; jentry++){
        tree->GetEntry(jentry);
        
        for (int iahit=0; iahit<ahit; iahit++){
            if (int(ae[iahit]*1e3) == int(ae0[iahit]*1e3)) aIsFull[iahit] = 1;
            else aIsFull[iahit] = 0;
        }
        for (int ighit=0; ighit<ghit; ighit++){
            if (int(ge[ighit]*1e3) == int(ge0[ighit]*1e3)) gIsFull[ighit] = 1;
            else gIsFull[ighit] = 0;
        }
        
        std::vector<int> processed(ghit,0);
        for (int iahit=0; iahit<ahit; iahit++){
            for (int ighit=0; ighit<ghit; ighit++){
                if (processed[ighit]) continue;
                
                if (int(ge[ighit]*1e3) == int(ae[iahit]*1e3)){
                    double deltaE = gr->Gaus(0,f1->Eval(ge[ighit]));
                    ge[ighit] += deltaE;
                    ae[iahit] += deltaE;
                    processed[ighit] = 1;
                }
                /*
                else if (int((ge[ighit]+ge[ighit+1])*1e3) == int(ae[iahit]*1e3) && ighit<=ghit-2){    // addback
                    ge[ighit] += gr->Gaus(0,f1->Eval(ge[ighit]));
                    ge[ighit+1] += gr->Gaus(0,f1->Eval(ge[ighit+1]));
                    ae[iahit] = ge[ighit] + ge[ighit+1];
                    processed[ighit] = 1;
                    processed[ighit+1] = 1;
                }
                */
            }
        }
        for (int ighit=0; ighit<ghit; ighit++){
            if (processed[ighit]) continue;
            ge[ighit] += gr->Gaus(0,f1->Eval(ge[ighit]));
        }
        opt->Fill();
        
        // display progress and time needed
        if (jentry%50000 == 49999){
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