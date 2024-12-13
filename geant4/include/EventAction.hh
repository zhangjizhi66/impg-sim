
#ifndef _EVENTACTION_H_
#define _EVENTACTION_H_

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4ios.hh"

#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4SDManager.hh"

//  This is the base class of one of the user's optional action classes.
// The two methods BeginOfEventAction() and EndOfEventAction() are invoked
// at the beginning and the end of one event processing. These methods are
// invoked by G4EventManager.
//  Be aware that BeginOfEventAction() is invoked when a G4Event object is
// sent to G4EventManager. Thus the primary vertexes/particles have already
// been made by the primary generator. In case the user wants to do something
// before generating primaries (i.e., store random number status), do it in
// the G4VUserPrimaryGeneratorAction concrete class.

class EventAction : public G4UserEventAction
{
public:
  EventAction();
  virtual ~EventAction();

public: // with description
  virtual void BeginOfEventAction(const G4Event* anEvent);
  virtual void EndOfEventAction(const G4Event* anEvent);
};

#endif /* _EVENTACTION_H_ */
