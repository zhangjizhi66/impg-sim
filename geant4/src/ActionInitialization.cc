
#include "ActionInitialization.hh"

#include "RunAction.hh"
#include "EventAction.hh"
#include "TrackingAction.hh"
#include "SteppingAction.hh"
#include "StackingAction.hh"
#include "PrimaryGeneratorAction.hh"

#include "G4Version.hh"

#if G4VERSION_NUMBER >= 1030
#include "G4MultiRunAction.hh"
#include "G4MultiEventAction.hh"
#include "G4MultiTrackingAction.hh"
#include "G4MultiSteppingAction.hh"
#endif

ActionInitialization::ActionInitialization() : G4VUserActionInitialization()
{}

ActionInitialization::~ActionInitialization()
{}

void ActionInitialization::BuildForMaster() const
{}

void ActionInitialization::Build() const
{
  //源的设置
  SetUserAction(new PrimaryGeneratorAction);
  
#if G4VERSION_NUMBER >= 1030
  
  G4MultiRunAction* actsRun = new G4MultiRunAction;
  G4MultiEventAction* actsEvent = new G4MultiEventAction;
  G4MultiTrackingAction* actsTrack = new G4MultiTrackingAction;
  G4MultiSteppingAction* actsStep = new G4MultiSteppingAction;

  actsRun->push_back(G4UserRunActionUPtr(new RunAction));
  actsEvent->push_back(G4UserEventActionUPtr(new EventAction));
  actsTrack->push_back(G4UserTrackingActionUPtr(new TrackingAction));
  actsStep->push_back(G4UserSteppingActionUPtr(new SteppingAction));
  
  SetUserAction(new StackingAction);
  
  SetUserAction(actsRun);
  SetUserAction(actsTrack);
  SetUserAction(actsEvent);
  SetUserAction(actsStep);
  
#else

  G4cout<<"It need G4VERSION_NUMBER >= 1030"<<G4endl;
  
#endif 
}
