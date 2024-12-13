
// anti-compton
void g4anticompton(TString foldername = "root")
{
    TFile *ipf = new TFile(Form("%s/g4coin.root",foldername.Data()));
    TTree *tree = (TTree*)ipf->Get("tree");

    int ghit0 = 0,gid0[10000];
    double ge000[10000],ge00[10000],gt0[10000];
    tree->SetBranchAddress("ghit",&ghit0);
    tree->SetBranchAddress("ge0",&ge000);
    tree->SetBranchAddress("ge",&ge00);
    tree->SetBranchAddress("gt",&gt0);    // ns, start with trigger
    tree->SetBranchAddress("gid",&gid0);  // gid
    
    TFile *opf = new TFile(Form("%s/g4anticompton.root",foldername.Data()),"RECREATE");
    TTree *opt = new TTree("tree","tree");
    
    int ghit = 0,gid[10000];
    double ge0[10000],ge[10000],gt[10000];
    opt->Branch("ghit",&ghit,"ghit/I");
    opt->Branch("ge0",&ge0,"ge0[ghit]/D");
    opt->Branch("ge",&ge,"ge[ghit]/D");
    opt->Branch("gt",&gt,"gt[ghit]/D");
    opt->Branch("gid",&gid,"gid[ghit]/I");  // gid + cid*10
    
    int ahit = 0,aid[10000];
    double ae0[10000],ae[10000],at[10000];
    opt->Branch("ahit",&ahit,"ahit/I");
    opt->Branch("ae0",&ae0,"ae0[ahit]/D");
    opt->Branch("ae",&ae,"ae[ahit]/D");
    opt->Branch("at",&at,"at[ahit]/I");
    opt->Branch("aid",&aid,"aid[ahit]/I");  // gid + cid*10
    
    clock_t start=clock(),stop=clock();

    int nentries = tree->GetEntries();
    for (int jentry=0; jentry<nentries; jentry++){
        tree->GetEntry(jentry);
        
        ahit = 0;
        ghit = 0;
        for (int hit1=0; hit1<ghit0; hit1++){
            if (gid0[hit1]%10 != 1) continue;  // 非 HPGe 探头
            
            int clusterid_this = int(gid0[hit1]/10);
            
            ge0[ghit] = ge000[hit1];
            ge[ghit] = ge00[hit1];
            gt[ghit] = gt0[hit1];
            gid[ghit] = clusterid_this;
            ghit++;

            bool anti = false;
            for (int hit2=0; hit2<ghit0; hit2++)
                if (int(gid0[hit2]/10) == clusterid_this && gid0[hit2]%10 != 1){
                    anti = true;
                    break;
                }

            if (!anti) {
                ae0[ahit] = ge000[hit1];
                ae[ahit] = ge00[hit1];
                at[ahit] = gt0[hit1];
                aid[ahit] = clusterid_this;
                ahit++;
            }
        }
        if (ghit!=0 || ahit!=0) opt->Fill();
        
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