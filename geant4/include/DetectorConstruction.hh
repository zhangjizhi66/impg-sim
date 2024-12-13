
#ifndef _DETECTORCONSTRUCTION_H_
#define _DETECTORCONSTRUCTION_H_


#include "G4TransportationManager.hh"
#include "G4PropagatorInField.hh"
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4SDManager.hh"

// GDML parser include，可视化界面几何体颜色设置用
#include "G4GDMLParser.hh"

// class description:
//
//  This is the abstract base class of the user's mandatory initialization class
// for detector setup. It has only one pure virtual method Construct() which is
// invoked by G4RunManager when it's Initialize() method is invoked.
//  The Construct() method must return the G4VPhysicalVolume pointer which represents
// the world volume.
//
class G4VPhysicalVolume;
class G4LogicalVolume;

class DetectorConstruction: public G4VUserDetectorConstruction
{
public:
    DetectorConstruction();
    virtual ~DetectorConstruction();

public:
    virtual G4VPhysicalVolume* Construct();
    G4VPhysicalVolume *DefineVolumes();
};

#endif /* _DETECTORCONSTRUCTION_H_ */
