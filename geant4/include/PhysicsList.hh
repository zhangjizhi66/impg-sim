
#ifndef _PHYSICSLIST_H_
#define _PHYSICSLIST_H_

#include "globals.hh"
#include "G4VModularPhysicsList.hh"

// #include "CompileTimeConstraints.hh"
// #include "G4VPhysicsConstructor.hh"

class PhysicsList : public G4VModularPhysicsList
{
public:
  PhysicsList(G4int ver=1);
  virtual ~PhysicsList();

public:
  virtual void SetCuts();
  virtual void ConstructParticle();
  
// private:
//   enum {ok = CompileTimeConstraints::IsA<G4VModularPhysicsList, 
//   G4VModularPhysicsList>::ok };

};

#endif /* _PHYSICSLIST_H_ */
