
#include "TrackingAction.hh"

#include "globals.hh"
#include "G4RunManager.hh"
#include "G4Track.hh"
#include "G4TrackVector.hh"
#include "G4ParticleTypes.hh"
#include "G4TrackingManager.hh"

TrackingAction::TrackingAction() : G4UserTrackingAction()
{}

TrackingAction::~TrackingAction()
{}

void TrackingAction::PreUserTrackingAction(const G4Track* aTrack)
{
  // 以下是数据接口定义
    
  // aTrack->GetTrackID();//G4int
  // aTrack->GetParentID();//G4int
  // aTrack->GetWeight();//G4double   These are methods for manipulating a weight for this track.
  // aTrack->GetCreatorModelID();//G4int
  // aTrack->GetCreatorModelName();//G4String&
  // aTrack->GetCreatorProcess();//G4VProcess*
  // const G4VProcess* pcr = aTrack->GetCreatorProcess();
  // if(pcr) G4String CreatorProcess = pcr->GetProcessName();//  Returns the name of the process.
  // else G4String CreatorProcess = "##";
  // pcr->GetProcessType();//G4ProcessType    Returns the process type.
  // pcr->GetProcessSubType();//G4int    Returns the process sub type.
  
  // aTrack->GetTrackLength();//G4double
  // // Before the end of the AlongStepDoIt loop,StepLength keeps the initial value which is determined by the shortest geometrical Step proposed by a physics process. After finishing the AlongStepDoIt, it will be set equal to 'StepLength' in G4Step.
  // aTrack->GetStepLength();//G4double
  // aTrack->GetCurrentStepNumber();//G4int
  // aTrack->GetStep();//G4Step*
  // // The flag of "GoodForTracking" is set by processes if this track should be tracked even if the energy is below threshold
  // aTrack->IsGoodForTracking();//G4bool
  // // The flag of "BelowThreshold" is set to true if this track energy is below threshold energy in this material determined by the range cut value
  // aTrack->IsBelowThreshold();//G4bool
  // aTrack->GetTrackStatus();//G4TrackStatus    track status, flags for tracking
  // aTrack->GetPolarization();//G4ThreeVector& 
  // aTrack->UseGivenVelocity();//G4bool
  // aTrack->CalculateVelocity();//G4double
  // aTrack->CalculateVelocityForOpticalPhoton();//G4double
  // aTrack->GetVelocity();//G4double
  // aTrack->GetMomentum();//G4ThreeVector
  // aTrack->GetMomentumDirection();//G4ThreeVector&
  // aTrack->GetTotalEnergy();//G4double
  // aTrack->GetKineticEnergy();//G4double
  // aTrack->GetVolume();//G4VPhysicalVolume*
  // aTrack->GetNextVolume();//G4VPhysicalVolume*
  // aTrack->GetMaterial();//G4Material*
  // aTrack->GetNextMaterial();//G4Material*
  // aTrack->GetMaterialCutsCouple();//G4MaterialCutsCouple*
  // aTrack->GetNextMaterialCutsCouple();//G4MaterialCutsCouple*
  // aTrack->GetTouchable();//G4VTouchable*
  // aTrack->GetTouchableHandle();//G4TouchableHandle&
  // aTrack->GetNextTouchable();//G4VTouchable*
  // aTrack->GetNextTouchableHandle();//G4TouchableHandle&
  // aTrack->GetOriginTouchable();//G4VTouchable*
  // aTrack->GetOriginTouchableHandle();//G4TouchableHandle&
  // aTrack->GetPosition();//G4ThreeVector&
  // aTrack->GetGlobalTime();//G4double    Time since the event in which the track belongs is created.
  // aTrack->GetLocalTime();//G4double    Time since the current track is created.
  // aTrack->GetProperTime();//G4double    Proper time of the current track
  // aTrack->GetDynamicParticle();//G4DynamicParticle*   dynamic particle 
  // aTrack->GetParticleDefinition();//G4ParticleDefinition*    particle definition 
  
  // // vertex (,where this track was created) information  
  // aTrack->GetVertexPosition();//G4ThreeVector&
  // aTrack->GetVertexMomentumDirection();//G4ThreeVector&
  // aTrack->GetVertexKineticEnergy();//G4double
  // aTrack->GetLogicalVolumeAtVertex();//G4LogicalVolume*
  
  // aTrack->GetUserInformation();// G4VUserTrackInformation*
  // aTrack->SetUserInformation(/*G4VUserTrackInformation* aValue*/);
    
}

void TrackingAction::PostUserTrackingAction(const G4Track* aTrack)
{
    G4TrackVector* secondaries = fpTrackingManager->GimmeSecondaries();
    if (secondaries) {   //如果当前 tracking 中产生了次级粒子
        TrackInformation* info = (TrackInformation*)(aTrack->GetUserInformation());  //当前 track 的信息

        size_t nSeco = secondaries->size();
        if (nSeco>0) {  //对次级粒子进行遍历
            for (size_t i=0; i<nSeco; i++) { 
                TrackInformation* infoNew = new TrackInformation(info);

                //G4cout<<infoNew->PrintFlag()<<G4endl;
                // G4cout<<"###  "<<(*secondaries)[i]->GetCreatorProcess()->GetProcessName()<<"  "<<(*secondaries)[i]->GetParticleDefinition()->GetParticleName()<<G4endl;

                (*secondaries)[i]->SetUserInformation(infoNew);
            }
        }
    }
}
