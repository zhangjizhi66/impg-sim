
#include "StackingAction.hh"

#include "G4Track.hh"
#include "G4ios.hh"
#include "G4ParticleTable.hh"
#include "globals.hh"
#include "G4VProcess.hh"

#include <TGraph.h>

StackingAction::StackingAction() : G4UserStackingAction()
{
    TGraph *gr = new TGraph;
    int iPnt = 0;
    gr->SetPoint(iPnt++,20,0);
    gr->SetPoint(iPnt++,30,0.009);
    gr->SetPoint(iPnt++,80,0.2);
    gr->SetPoint(iPnt++,100,0.4);
    gr->SetPoint(iPnt++,140,0.75);
    gr->SetPoint(iPnt++,200,1);
    
    sp = new TSpline3("sp",gr);
}

StackingAction::~StackingAction()
{}

G4ClassificationOfNewTrack StackingAction::ClassifyNewTrack(const G4Track *aTrack)
{
    G4String PName = aTrack->GetDefinition()->GetParticleName();

    G4String CreatorProcess;
    const G4VProcess* pcr = aTrack->GetCreatorProcess();
    if (pcr) CreatorProcess = pcr->GetProcessName();
    else CreatorProcess = "##";
    
    if (strstr(PName,"e-"))
        if (!strstr(CreatorProcess,"phot") && !strstr(CreatorProcess,"compt") && !strstr(CreatorProcess,"conv"))
            return fKill;
    
    // kill decay daughter
    if (!strstr(PName,"gamma") && !strstr(PName,"Ga") && strstr(CreatorProcess,"Radioacti"))
        return fKill;
    
    // absorber
    if (strstr(PName,"gamma") && (strstr(CreatorProcess,"Radioacti")||aTrack->GetParentID()==0)) { // 当前track的粒子是衰变产生的gamma或初始gamma
        G4double E = aTrack->GetKineticEnergy()*1000;  // keV
        G4double scale = 1;
        if (E > 200) {
            if (G4UniformRand() > scale) return fKill;
        }
        else if (E < 20) {
            return fKill;
        }
        else {
            if (G4UniformRand() > sp->Eval(E)*scale ) return fKill;
        }
    }
    
    return fUrgent;
}

void StackingAction::NewStage()
{}
  
void StackingAction::PrepareNewEvent()
{}
