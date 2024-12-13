
#include "RunAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"

#include "G4CsvAnalysisManager.hh"
#include "G4XmlAnalysisManager.hh"
#include "G4RootAnalysisManager.hh"

RunAction::RunAction() {}

RunAction::~RunAction() {}

G4Run* RunAction::GenerateRun()
{
    return 0;
}

void RunAction::BeginOfRunAction(const G4Run* /*aRun*/)
{
    analysisManager = G4RootAnalysisManager::Instance();  // choose file type: ROOT

    analysisManager->SetVerboseLevel(1);
    analysisManager->CreateNtuple("tree", "Geant4 data");

    //analysisManager->CreateNtupleIColumn("EventID");
    //analysisManager->CreateNtupleIColumn("ParentID");
    //analysisManager->CreateNtupleIColumn("TrackID");
    //analysisManager->CreateNtupleIColumn("CurrentStepNumber");
    //analysisManager->CreateNtupleSColumn("PName");
    //analysisManager->CreateNtupleDColumn("TrackWeight");
    //analysisManager->CreateNtupleSColumn("CreatorProcess");
    analysisManager->CreateNtupleDColumn("EDep");
    //analysisManager->CreateNtupleDColumn("TrackLength");
    //analysisManager->CreateNtupleDColumn("StepLength");
    //analysisManager->CreateNtupleIColumn("TrackStatus");
    //analysisManager->CreateNtupleDColumn("Mass");
    //analysisManager->CreateNtupleDColumn("Charge");
    //analysisManager->CreateNtupleDColumn("MagneticMoment");
    analysisManager->CreateNtupleSColumn("VolNamePre");
    //analysisManager->CreateNtupleSColumn("VolNamePost");
    //analysisManager->CreateNtupleDColumn("GlobalTimePre");
    //analysisManager->CreateNtupleDColumn("GlobalTimePost");
    //analysisManager->CreateNtupleDColumn("LocalTimePre");
    //analysisManager->CreateNtupleDColumn("LocalTimePost");
    //analysisManager->CreateNtupleDColumn("ProperTimePre");
    //analysisManager->CreateNtupleDColumn("ProperTimePost");
    //analysisManager->CreateNtupleIColumn("StepStatusPre");
    //analysisManager->CreateNtupleIColumn("StepStatusPost");
    //analysisManager->CreateNtupleDColumn("EkPre");
    //analysisManager->CreateNtupleDColumn("EkPost");
    //analysisManager->CreateNtupleDColumn("xPre");
    //analysisManager->CreateNtupleDColumn("yPre");
    //analysisManager->CreateNtupleDColumn("zPre");
    //analysisManager->CreateNtupleDColumn("xPost");
    //analysisManager->CreateNtupleDColumn("yPost");
    //analysisManager->CreateNtupleDColumn("zPost");
    //analysisManager->CreateNtupleDColumn("xMomentumDirectionPre");  // for angular correlation
    //analysisManager->CreateNtupleDColumn("yMomentumDirectionPre");  // for angular correlation
    //analysisManager->CreateNtupleDColumn("zMomentumDirectionPre");  // for angular correlation
    //analysisManager->CreateNtupleDColumn("Velocitypre");
    //analysisManager->CreateNtupleDColumn("xMomentumDirectionPost");
    //analysisManager->CreateNtupleDColumn("yMomentumDirectionPost");
    //analysisManager->CreateNtupleDColumn("zMomentumDirectionPost");
    //analysisManager->CreateNtupleDColumn("Velocitypost");
    analysisManager->CreateNtupleDColumn("Egamma");
  
    analysisManager->FinishNtuple();
    analysisManager->OpenFile("g4raw");//输出文件名
}

void RunAction::EndOfRunAction(const G4Run* /*aRun*/)
{
    analysisManager->Write();
    analysisManager->CloseFile();
}
