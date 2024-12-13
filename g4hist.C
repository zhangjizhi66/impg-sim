// Last Modified zhangjizhi, 20221026

// Make 2-fold gg-matrix(TH2) from ROOT files(TTree) 
// Author: Li Zhihuan, Peking University

#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TString.h"
#include "TROOT.h"
#include "TSystem.h"
#include <iostream>
#include <ctime>

using namespace std;

int nBin = 2500;
int MaxE = 2500;

// choose Branch
TString hit_name = "ghit";
TString e_name = "ge";
TString IsFull_name = "gIsFull";

TH2F *hg2xy = nullptr;
clock_t start,stop;

void root2g2hist(TString foldername);

void g4hist(TString foldername = "root")
{
    start = clock();
    hg2xy = new TH2F("hg2xy","raw matrix",nBin,0,MaxE,nBin,0,MaxE);
    
    root2g2hist(foldername);

    TFile *fout = new TFile(Form("%s/g4hist.root",foldername.Data()),"recreate");//output file 
    hg2xy->Write();
    fout->Close();
    cout<<"Write Histgrams to "<<Form("%s/g4hist.root",foldername.Data())<<'\n';

    stop=clock();
    double seconds=(double)(stop-start)/CLOCKS_PER_SEC;
    cout<<"Time taken by program is : "<<seconds<<" seconds."<<'\n'<<"Done!"<<'\n';
    gROOT->ProcessLine(".q");
}

void root2g2hist(TString foldername)
{
    if(gSystem->AccessPathName(Form("%s/g4reso.root",foldername.Data()))){
        cout <<Form("%s/g4reso.root",foldername.Data())<< " does not exist!" <<endl;
        return 0;
    }
    start = clock();

    TFile *f = new TFile(Form("%s/g4reso.root",foldername.Data())); 
    TTree *tree = (TTree*)f->Get("tree");
    
    Int_t ghit,gIsFull[10000],gid[10000];
    Double_t ge[10000];
    tree->SetBranchAddress(hit_name,&ghit); //hit
    tree->SetBranchAddress(e_name,&ge);     //energy
    tree->SetBranchAddress(IsFull_name,&gIsFull);
    tree->SetBranchAddress("gid",&gid);
    
    clock_t start=clock(),stop=clock();
    
    Long64_t nentries=tree->GetEntries();
    for (Long64_t jentry=0;jentry<nentries;jentry++){
        tree->GetEntry(jentry);
        if (ghit<2) continue;
        
        for (int i=0;i<ghit;i++)
            for (int j=0;j<ghit;j++) {
                if(i==j) continue;
                if(ge[i]<0 || ge[i]>MaxE) continue;
                if(ge[j]<0 || ge[j]>MaxE) continue;
                
                //if(int(gid[i]/10)==3 || int(gid[j]/10)==3) continue;  // no clover
                
                hg2xy->Fill(ge[i],ge[j]);
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
}
