
#include "TrackInformation.hh"
#include "SteppingAction.hh"

#include "G4TrackVector.hh"
#include "G4SteppingManager.hh"

#include "G4CsvAnalysisManager.hh"
#include "G4XmlAnalysisManager.hh"
#include "G4RootAnalysisManager.hh"

SteppingAction::SteppingAction() : G4UserSteppingAction()
{
  analysisManager = G4RootAnalysisManager::Instance();
}

SteppingAction::~SteppingAction() {}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
  // energy deposit
  EDep = step->GetTotalEnergyDeposit();

  // step length
  //StepLength = 0.;
  //if ( step->GetTrack()->GetDefinition()->GetPDGCharge() != 0. ){
  //    StepLength = step->GetStepLength();
  //}
  
  G4Track* aTrack = step->GetTrack();//获取数据接口
  //G4ParticleDefinition* theparticle = aTrack->GetDefinition();
  //PName = theparticle->GetParticleName();

  //const G4DynamicParticle* dyParticle = aTrack->GetDynamicParticle();  //获取数据接口

  //EventID = G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetEventID();
  //TrackID = aTrack->GetTrackID();
  ParentID = aTrack->GetParentID();
  //CurrentStepNumber = aTrack->GetCurrentStepNumber();
  //TrackLength = aTrack->GetTrackLength();
  //TrackStatus = aTrack->GetTrackStatus();

  G4StepPoint* preStepPoint = step->GetPreStepPoint();//获取数据接口
  //G4StepPoint* postStepPoint = step->GetPostStepPoint();//获取数据接口

  // G4LogicalVolume
  //preStepVolume = preStepPoint->GetPhysicalVolume()->GetLogicalVolume();
  //if (postStepPoint->GetPhysicalVolume())//判断是否在world外
  //  postStepVolume = postStepPoint->GetPhysicalVolume()->GetLogicalVolume();

  // Dynamical data of the particle
  //Mass = preStepPoint->GetMass();
  //Charge = preStepPoint->GetCharge();
  //MagneticMoment = preStepPoint->GetMagneticMoment();
  //TrackWeight = preStepPoint->GetWeight(); 

  //PosPre = preStepPoint->GetPosition();
  //EkPre = preStepPoint->GetKineticEnergy();
  //GlobalTimePre = preStepPoint->GetGlobalTime();
  //LocalTimePre = preStepPoint->GetLocalTime();
  //VelocityPre = preStepPoint->GetVelocity();
  //MomentumDirectionPre = preStepPoint->GetMomentumDirection();  // for angular correlation
  VolNamePre = preStepPoint->GetPhysicalVolume()->GetName();
  //StepStatusPre = preStepPoint->GetStepStatus();
  //ProperTimePre = preStepPoint->GetProperTime();

  //const G4VProcess* pcr = aTrack->GetCreatorProcess();
  //if (pcr) CreatorProcess = pcr->GetProcessName();
  //else CreatorProcess = "##";

  //PosPost = postStepPoint->GetPosition();
  //EkPost = postStepPoint->GetKineticEnergy();
  //GlobalTimePost = postStepPoint->GetGlobalTime();
  //LocalTimePost = postStepPoint->GetLocalTime();
  //VelocityPost = postStepPoint->GetVelocity();
  //MomentumDirectionPost = postStepPoint->GetMomentumDirection();
  //if (postStepPoint->GetPhysicalVolume()) VolNamePost = postStepPoint->GetPhysicalVolume()->GetName(); //判断是否在world外
  //else VolNamePost = "**";

  //StepStatusPost = postStepPoint->GetStepStatus();
  //ProperTimePost = postStepPoint->GetProperTime();
    
  //TrackingInformation
  TrackInformation* trackInformation = (TrackInformation*)(aTrack->GetUserInformation());
  if (trackInformation)
      Egamma = trackInformation->GetEgamma();
  else
      Egamma = -1;
    
  // output filter
  if ( (!strstr(VolNamePre,"crystal") || EDep<=0) && ParentID!=0 ) return;
  //if (GlobalTimePre == 0) GlobalTimePre = GlobalTimePost;

  int iCol=0;
  //analysisManager->FillNtupleIColumn(iCol++, EventID);
  //analysisManager->FillNtupleIColumn(iCol++, ParentID);
  //analysisManager->FillNtupleIColumn(iCol++, TrackID);
  //analysisManager->FillNtupleIColumn(iCol++, CurrentStepNumber);
  //analysisManager->FillNtupleSColumn(iCol++, PName);
  //analysisManager->FillNtupleDColumn(iCol++, TrackWeight);
  //analysisManager->FillNtupleSColumn(iCol++, CreatorProcess);
  analysisManager->FillNtupleDColumn(iCol++, EDep);
  //analysisManager->FillNtupleDColumn(iCol++, TrackLength);
  //analysisManager->FillNtupleDColumn(iCol++, StepLength);
  //analysisManager->FillNtupleIColumn(iCol++, TrackStatus);
  //analysisManager->FillNtupleDColumn(iCol++, Mass);
  //analysisManager->FillNtupleDColumn(iCol++, Charge);
  //analysisManager->FillNtupleDColumn(iCol++, MagneticMoment);
  analysisManager->FillNtupleSColumn(iCol++, VolNamePre);
  //analysisManager->FillNtupleSColumn(iCol++, VolNamePost);
  //analysisManager->FillNtupleDColumn(iCol++, GlobalTimePre);
  //analysisManager->FillNtupleDColumn(iCol++, GlobalTimePost);
  //analysisManager->FillNtupleDColumn(iCol++, LocalTimePre);
  //analysisManager->FillNtupleDColumn(iCol++, LocalTimePost);
  //analysisManager->FillNtupleDColumn(iCol++, ProperTimePre);
  //analysisManager->FillNtupleDColumn(iCol++, ProperTimePost);
  //analysisManager->FillNtupleIColumn(iCol++, StepStatusPre);
  //analysisManager->FillNtupleIColumn(iCol++, StepStatusPost);
  //analysisManager->FillNtupleDColumn(iCol++, EkPre);
  //analysisManager->FillNtupleDColumn(iCol++, EkPost);
  //analysisManager->FillNtupleDColumn(iCol++, PosPre.x());
  //analysisManager->FillNtupleDColumn(iCol++, PosPre.y());
  //analysisManager->FillNtupleDColumn(iCol++, PosPre.z());
  //analysisManager->FillNtupleDColumn(iCol++, PosPost.x());
  //analysisManager->FillNtupleDColumn(iCol++, PosPost.y());
  //analysisManager->FillNtupleDColumn(iCol++, PosPost.z());
  //analysisManager->FillNtupleDColumn(iCol++, MomentumDirectionPre.x());  // for angular correlation
  //analysisManager->FillNtupleDColumn(iCol++, MomentumDirectionPre.y());  // for angular correlation
  //analysisManager->FillNtupleDColumn(iCol++, MomentumDirectionPre.z());  // for angular correlation
  //analysisManager->FillNtupleDColumn(iCol++, VelocityPre);
  //analysisManager->FillNtupleDColumn(iCol++, MomentumDirectionPost.x());
  //analysisManager->FillNtupleDColumn(iCol++, MomentumDirectionPost.y());
  //analysisManager->FillNtupleDColumn(iCol++, MomentumDirectionPost.z());
  //analysisManager->FillNtupleDColumn(iCol++, VelocityPost);
  analysisManager->FillNtupleDColumn(iCol++, Egamma);

  analysisManager->AddNtupleRow();  //相当于 Fill
}
