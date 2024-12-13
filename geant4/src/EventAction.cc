
#include "EventAction.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4ParticleTable.hh"
#include "globals.hh"

#include "G4DigiManager.hh"

EventAction::EventAction()
{}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event* anEvent)
{
  G4int EventID = anEvent->GetEventID();//  Returns the event ID
    
  if (EventID%10000 == 0) G4cout<<EventID<<G4endl;
  
  // // This method sets a new primary vertex. This method must be invoked exclusively by G4VPrimaryGenerator concrete class.
  // anEvent->AddPrimaryVertex(G4PrimaryVertex* aPrimaryVertex);

  // //  Returns i-th primary vertex of the event.
  // G4PrimaryVertex *primaryvertex = anEvent->GetPrimaryVertex(/*G4int i=0*/);// return G4PrimaryVertex*
  // primaryvertex->GetPosition();//G4ThreeVector
  // primaryvertex->GetX0();//G4double
  // primaryvertex->GetY0();//G4double
  // primaryvertex->GetZ0();//G4double
  // primaryvertex->GetT0();//G4double
  // primaryvertex->GetNumberOfParticle();//G4int
  // primaryvertex->GetPrimary(/*G4int i=0*/);//G4PrimaryParticle*
  // primaryvertex->GetWeight();//G4double
  // primaryvertex->GetUserInformation();//G4VUserPrimaryVertexInformation*
  // primaryvertex->SetUserInformation(/*G4VUserPrimaryVertexInformation* anInfo*/);

  // G4PrimaryParticle* primaryparticle = primaryvertex->GetPrimary(/*G4int i=0*/);
  // primaryparticle->GetPDGcode();//G4int
  // primaryparticle->GetG4code();//G4ParticleDefinition*
  // primaryparticle->GetMass();//G4double
  // primaryparticle->GetCharge();//G4double
  // primaryparticle->GetKineticEnergy();//G4double
  // primaryparticle->GetMomentumDirection();//G4ThreeVector&
  // primaryparticle->GetTotalMomentum();//G4double
  // primaryparticle->GetTotalEnergy();//G4double
  // primaryparticle->GetMomentum();//G4ThreeVector
  // primaryparticle->GetPx();//G4ThreeVector
  // primaryparticle->GetPy();//G4ThreeVector
  // primaryparticle->GetPz();//G4ThreeVector
  // primaryparticle->GetTrackID();//G4int "trackID" will be set if this particle is sent to G4EventManager and converted to G4Track. Otherwise = -1.
  // primaryparticle->GetPolarization();//G4ThreeVector
  // primaryparticle->GetPolX();//G4double
  // primaryparticle->GetPolY();//G4double
  // primaryparticle->GetPolZ();//G4double
  // primaryparticle->GetWeight();//G4double
  // primaryparticle->GetProperTime();//G4double   
  // primaryparticle->GetUserInformation();//G4VUserPrimaryParticleInformation*
  // primaryparticle->SetUserInformation(/*G4VUserPrimaryParticleInformation* anInfo*/);
  
  // anEvent->SetUserInformation(/*G4VUserEventInformation* anInfo*/);
  // anEvent->GetUserInformation();//return G4VUserEventInformation*
}

void EventAction::EndOfEventAction(const G4Event* /*anEvent*/)
{
  // // 读取该事件SD中记录的数据
  // G4HCofThisEvent *HCE = anEvent->GetHCofThisEvent();//SD  (hits collections of this event)
  // if(HCE)
  //   {
  //     size_t nHCinHCE = HCE->GetCapacity();//SD个数
  //     // 
  //     for(size_t i = 0; i < nHCinHCE; i++)//遍历SD
  // 	{
  // 	  // 拿到HitCollection

  // 	}
  //   }

  // G4DCofThisEvent* *DCE = anEvent->GetDCofThisEvent();// (digi collections of this event)
}
