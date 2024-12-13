
#ifndef _TRACKINGACTION_H_
#define _TRACKINGACTION_H_

#include "G4Types.hh"

//   This class represents actions taken place by the user at 
//   the start/end point of processing one track. 

class TrackingAction : public G4UserTrackingAction
{
public:
  TrackingAction();
  virtual ~TrackingAction();

public:
  virtual void PreUserTrackingAction(const G4Track* aTrack);
  virtual void PostUserTrackingAction(const G4Track* aTrack);
};

// enum G4TrackStatus
// {
//   fAlive,             // Continue the tracking
//   fStopButAlive,      // Invoke active rest physics processes and kill the current track afterward
//   fStopAndKill,       // Kill the current track
//   fKillTrackAndSecondaries, // Kill the current track and also associated secondaries.
//   fSuspend,           // Suspend the current track
//   fPostponeToNextEvent // Postpones the tracking of thecurrent track to the next event.
// };

// enum G4ProcessType
// {
//   fNotDefined,
//   fTransportation,
//   fElectromagnetic,
//   fOptical,             
//   fHadronic,
//   fPhotolepton_hadron,
//   fDecay,
//   fGeneral,
//   fParameterisation,
//   fUserDefined,
//   fParallel,
//   fPhonon,
//   fUCN
// };

#endif /* _TRACKINGACTION_H_ */
