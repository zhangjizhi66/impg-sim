
#ifndef _STEPPINGACTION_H_
#define _STEPPINGACTION_H_

#include "G4UserSteppingAction.hh"

#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4Track.hh"
#include "G4TrackStatus.hh"
#include "G4VProcess.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
#include "G4ios.hh"

class G4VAnalysisManager;

class SteppingAction : public G4UserSteppingAction
{
public:
  SteppingAction();
  virtual ~SteppingAction();

public:
  virtual void UserSteppingAction(const G4Step* step);

private:
  G4int    EventID;//
  G4int    ParentID;//
  G4int    TrackID;//
  G4int    CurrentStepNumber;//       // Total steps number up to now
  G4String  PName;//                           //particle name
  G4double  TrackWeight;//                        // Track Weight
  G4String  CreatorProcess;//
  G4double  EDep;//
  G4double  TrackLength;//          // Accumulated track length
  G4double  StepLength;//
  G4int    TrackStatus;//

  G4double  Mass;//                 // Dynamical mass of the particle静质量
  G4double  Charge;//             // Dynamical Charge of the particle
  G4double  MagneticMoment;//    // Dynamical MagneticMoment of the particle

  G4String  VolNamePre;//                   //G4VPhysicalVolume name
  G4String  VolNamePost;//
  G4double  GlobalTimePre;//                   //Time since event is created
  G4double  GlobalTimePost;//
  G4double  LocalTimePre;//                  // Time since track is created
  G4double  LocalTimePost;//
  G4double  ProperTimePre;//            // Time since track is created (in rest frame of particle)
  G4double  ProperTimePost;//
  G4int    StepStatusPre;//
  G4int    StepStatusPost;//
  G4double  EkPre;//                    
  G4double  EkPost;//
  G4ThreeVector PosPre;//
  G4ThreeVector PosPost;//
  G4ThreeVector MomentumDirectionPre;//
  G4double  VelocityPre;//
  G4ThreeVector MomentumDirectionPost;//
  G4double  VelocityPost;//
  G4int Info;//

  G4LogicalVolume * preStepVolume;
  G4LogicalVolume * postStepVolume;
  
  G4double Egamma;
  
  G4VAnalysisManager* analysisManager;
};

// enum G4StepStatus
// {
//   fWorldBoundary,// Step reached the world boundary
//   fGeomBoundary,// Step defined by a geometry boundary
//   fAtRestDoItProc,// Step defined by a PreStepDoItVector
//   fAlongStepDoItProc,// Step defined by a AlongStepDoItVector
//   fPostStepDoItProc,// Step defined by a PostStepDoItVector
//   fUserDefinedLimit,// Step defined by the user Step limit in the logical volume
//   fExclusivelyForcedProc,// Step defined by an exclusively forced PostStepDoIt process 
//   fUndefined// Step not defined yet
// };

// enum G4SteppingControl  
// {
//   NormalCondition,
//   AvoidHitInvocation,// Hit will NOT be called 
//   Debug
// };

#endif /* _STEPPINGACTION_H_ */
