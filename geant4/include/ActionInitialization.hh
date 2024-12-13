
#ifndef _ACTIONINITIALIZATION_H_
#define _ACTIONINITIALIZATION_H_

#include "G4VUserActionInitialization.hh"

using namespace std;

class ActionInitialization : public G4VUserActionInitialization
{
public:
  ActionInitialization();
  virtual ~ActionInitialization();

  virtual void BuildForMaster() const;
  virtual void Build() const;

};

#endif /* _ACTIONINITIALIZATION_H_ */
