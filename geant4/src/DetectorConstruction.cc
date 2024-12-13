
#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"//继承G4VPhysicalVolume
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UserLimits.hh"
#include "G4AutoDelete.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4Region.hh"
#include "G4RegionStore.hh"

#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"

#include "G4PSEnergyDeposit3D.hh"
#include "G4PSNofStep3D.hh"
#include "G4PSCellFlux3D.hh"
#include "G4PSPassageCellFlux3D.hh"
#include "G4PSFlatSurfaceFlux3D.hh"
#include "G4PSFlatSurfaceCurrent3D.hh"
#include "G4SDParticleWithEnergyFilter.hh"
#include "G4SDParticleFilter.hh"
#include "G4SDChargedFilter.hh"
#include "G4SDNeutralFilter.hh"

#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4CutTubs.hh"
#include "G4Orb.hh"
#include "G4Para.hh"
#include "G4Sphere.hh"
#include "G4Torus.hh"
#include "G4Trap.hh"
#include "G4Trd.hh"
#include "G4Tubs.hh"

#include "CADMesh.hh"

DetectorConstruction::DetectorConstruction() : G4VUserDetectorConstruction() {}

DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    G4VPhysicalVolume *theDetector = DefineVolumes();
    return theDetector;
}

// import STL models
G4VPhysicalVolume *DetectorConstruction::DefineVolumes()
{
    // physical world
    G4VPhysicalVolume *theDetector = 0x0;
    G4Box *detWorld = new G4Box("world",2.*CLHEP::m,2.*CLHEP::m,2.*CLHEP::m);
    G4LogicalVolume *detlogicWorld = new G4LogicalVolume(detWorld, G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"), "world", 0, 0, 0);
    detlogicWorld->SetVisAttributes(G4VisAttributes::Invisible); // hide the world
    theDetector = new G4PVPlacement(0, G4ThreeVector(), detlogicWorld, "world", 0, false, -1, true);
/*
    // Fe support
    auto modelSupport = CADMesh::TessellatedMesh::FromSTL("../model/Fe_support.STL");
    G4LogicalVolume *theSupport = new G4LogicalVolume(modelSupport->GetSolid(),
                                      G4NistManager::Instance()->FindOrBuildMaterial("G4_Fe"), "support", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(), theSupport, "support", detlogicWorld, false, -1, true);
*/
    // Al casing
    auto modelCasing = CADMesh::TessellatedMesh::FromSTL("../model/Al_casing.STL");
    G4LogicalVolume *theCasing = new G4LogicalVolume(modelCasing->GetSolid(),
                                      G4NistManager::Instance()->FindOrBuildMaterial("G4_Al"), "casing", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(), theCasing, "casing", detlogicWorld, false, -1, true);

    // Pb collimator
    auto modelCollimator = CADMesh::TessellatedMesh::FromSTL("../model/Pb_collimator.STL");
    G4LogicalVolume *theCollimator = new G4LogicalVolume(modelCollimator->GetSolid(),
                                      G4NistManager::Instance()->FindOrBuildMaterial("G4_Pb"), "collimator", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(), theCollimator, "collimator", detlogicWorld, false, -1, true);
/*
    // Cu absorber
    auto modelAbsorber1 = CADMesh::TessellatedMesh::FromSTL("../model/Cu_absorber.STL");
    G4LogicalVolume *theAbsorber1 = new G4LogicalVolume(modelAbsorber1->GetSolid(),
                                      G4NistManager::Instance()->FindOrBuildMaterial("G4_Cd"), "absorber1", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(), theAbsorber1, "absorber1", detlogicWorld, false, -1, true);

    // Cd absorber
    auto modelAbsorber2 = CADMesh::TessellatedMesh::FromSTL("../model/Cd_absorber.STL");
    G4LogicalVolume *theAbsorber2 = new G4LogicalVolume(modelAbsorber2->GetSolid(),
                                      G4NistManager::Instance()->FindOrBuildMaterial("G4_Cu"), "absorber2", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(), theAbsorber2, "absorber2", detlogicWorld, false, -1, true);
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int mapping[24][2] = {{1,1},{1,2},{1,3},{1,4},{2,2},{2,4},{2,6},{2,8},{3,1},{3,2},{3,3},{3,4},{3,5},{3,6},{3,7},{3,8},{4,1},{4,3},{4,5},{4,7},{5,1},{5,2},{5,3},{5,4}};
    
    G4VisAttributes *visatt1 = new G4VisAttributes( G4Colour(220./255, 20./255, 60./255, 1) );
    visatt1->SetVisibility(true);
    
    G4VisAttributes *visatt2 = new G4VisAttributes( G4Colour(239./255, 220./255, 18./255, 1) );
    visatt2->SetVisibility(true);
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Ge crystal
    G4LogicalVolume *theGe[24];
    std::shared_ptr<CADMesh::TessellatedMesh> modelGe[24];
    for (int id=0; id<24; id++){
        G4String name = G4String("Ge_"+std::to_string(mapping[id][0])+"_"+std::to_string(mapping[id][1])+"_crystal");
        modelGe[id] = CADMesh::TessellatedMesh::FromSTL(
                                G4String("../model/Ge_"+std::to_string(mapping[id][0])+"-"+std::to_string(mapping[id][1])+".STL") );
        theGe[id] = new G4LogicalVolume(modelGe[id]->GetSolid(),
                                G4NistManager::Instance()->FindOrBuildMaterial("G4_Ge"), name, 0, 0, 0);
        theGe[id]->SetVisAttributes( visatt1 );
        new G4PVPlacement(0, G4ThreeVector(), theGe[id], name, detlogicWorld, false, -1, true);
    }
    
    // BGO crystal
    G4LogicalVolume *theBGO[24];
    std::shared_ptr<CADMesh::TessellatedMesh> modelBGO[24];
    for (int id=0; id<24; id++){
        G4String name = G4String("BGO_"+std::to_string(mapping[id][0])+"_"+std::to_string(mapping[id][1])+"_crystal");
        modelBGO[id] = CADMesh::TessellatedMesh::FromSTL(
                                G4String("../model/BGO_"+std::to_string(mapping[id][0])+"-"+std::to_string(mapping[id][1])+".STL") );
        theBGO[id] = new G4LogicalVolume(modelBGO[id]->GetSolid(),
                                G4NistManager::Instance()->FindOrBuildMaterial("G4_BGO"), name, 0, 0, 0);
        theBGO[id]->SetVisAttributes( visatt2 );
        new G4PVPlacement(0, G4ThreeVector(), theBGO[id], name, detlogicWorld, false, -1, true);
    }
    
    // CsI crystal
    G4LogicalVolume *theCsI[8];
    std::shared_ptr<CADMesh::TessellatedMesh> modelCsI[8];
    for (int id=0; id<8; id++){
        G4String name = G4String("CsI_3_"+std::to_string(id+1)+"_crystal");
        modelCsI[id] = CADMesh::TessellatedMesh::FromSTL(
                                G4String("../model/CsI_3-"+std::to_string(id+1)+".STL") );
        theCsI[id] = new G4LogicalVolume(modelCsI[id]->GetSolid(),
                                G4NistManager::Instance()->FindOrBuildMaterial("G4_CESIUM_IODIDE"), name, 0, 0, 0);
        new G4PVPlacement(0, G4ThreeVector(), theCsI[id], name, detlogicWorld, false, -1, true);
    }

    return theDetector;
}
