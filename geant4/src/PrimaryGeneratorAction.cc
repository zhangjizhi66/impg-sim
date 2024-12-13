
#include "PrimaryGeneratorAction.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4RandomDirection.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction() : G4VUserPrimaryGeneratorAction(),particleGun(NULL)
{
    particleGun = new G4ParticleGun(1);  // G4int n_particle
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    if (particleGun) {
        delete particleGun;
        particleGun = NULL;
    }  
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    /* hybrid source */
    G4double scale = 1.;
    G4double nBi214 = 0.0015*scale;
    G4double nAc228 = 0.0008*scale;
    G4double nK40  = 0.003*scale;
    G4double nCo60 = 0.0013*scale;
    G4double nMn54 = 0.0003*scale;
    G4double nNa22 = 0.0014*scale;
    G4double nNa24 = 0.0003*scale;
    
    G4double samp = G4UniformRand();
    
    /* Environmental Radioactivity */
    if ( samp < nBi214 ) SetStaticNucleus(anEvent, 83, 214, 0);  // 214Bi
    else if ( samp < nBi214+nK40 ) SetSourceK40(anEvent);
    else if ( samp < nBi214+nK40+nCo60 ) SetStaticNucleus(anEvent, 27, 60, 0);  // 60Co
    else if ( samp < nBi214+nK40+nCo60+nMn54 ) SetStaticNucleus(anEvent, 25, 54, 0);  // 54Mn
    else if ( samp < nBi214+nK40+nCo60+nMn54+nNa22 ) SetStaticNucleus(anEvent, 11, 22, 0);  // 22Na
    else if ( samp < nBi214+nK40+nCo60+nMn54+nNa22+nAc228 ) SetStaticNucleus(anEvent, 89, 228, 0);  // 228Ac
    else if ( samp < nBi214+nK40+nCo60+nMn54+nNa22+nAc228+nNa24 ) SetStaticNucleus(anEvent, 11, 24, 0);  // 24Na
    
    /* Main Source */
    //else SetStaticNucleus(anEvent, 56, 133, 0);         // 133Ba
    else SetStaticNucleus(anEvent, 31, 67, 3855.99*keV);     // 67Ga
    //else SetStaticNucleus(anEvent, 31, 65, 3065.06*keV);    // 65Ga
    //else SetStaticNucleus(anEvent, 30, 64, 3993.4*keV);     // 64Zn
    
    
    /* single source */
    //SetSourceGamma(anEvent);
    //SetSourceNeutron(anEvent);
    //SetSourceMuon(anEvent);
    //SetSourceRa226(anEvent);
}

void PrimaryGeneratorAction::SetStaticNucleus(G4Event* anEvent, G4int Z, G4int A, G4double Estar)
{
    G4int IonZ = Z;
    G4int IonA = A;
    G4double IonEstar = Estar;  // exitition energy
    G4double IonQ = Z;
    particleGun->SetParticleCharge(IonQ);
    G4ParticleDefinition* pp = G4ParticleTable::GetParticleTable()->GetIonTable()->GetIon(IonZ, IonA, IonEstar);  //4.10.01版本强制 G4IonTable.hh
    particleGun->SetParticleDefinition(pp);
    
    particleGun->SetParticlePosition(G4ThreeVector(0, 0, 0));
    particleGun->SetParticleEnergy(0.);
    
    particleGun->GeneratePrimaryVertex(anEvent);   //这个调用一次设置一次粒子，一次模拟要同时发射多个不同粒子就得多次调用它
}

void PrimaryGeneratorAction::SetSourceK40(G4Event* anEvent)
{
    // Geant4已经定义的粒子
    particleGun->SetParticleDefinition(G4ParticleTable::GetParticleTable()->FindParticle("gamma"));

    // primary particle position
    particleGun->SetParticlePosition(G4ThreeVector(0,0,0));

    // primary particle kinematics
    G4double theta = acos(2.*G4UniformRand()-1.);   // theta range, even distribution by solid angle
    G4double phi = G4UniformRand()*2.0*pi;        // phi range
    particleGun->SetParticleMomentumDirection(G4ThreeVector(sin(theta)*cos(phi), sin(theta)*sin(phi), cos(theta)));
    
    // primary particle kinetic energy
    particleGun->SetParticleEnergy(1.46082*MeV);
  
    particleGun->GeneratePrimaryVertex(anEvent);   //这个调用一次设置一次粒子，一次模拟要同时发射多个不同粒子就得多次调用它
}

void PrimaryGeneratorAction::SetSourceNeutron(G4Event* anEvent)
{
    particleGun->SetParticleDefinition(G4ParticleTable::GetParticleTable()->FindParticle("neutron"));

    G4double Rmin = 500.*mm;
    G4double Rmax = 600.*mm;
    G4ThreeVector v1 = G4RandomDirection()*(Rmin + G4UniformRand()*(Rmax - Rmin));
    G4ThreeVector v2 = G4RandomDirection()*G4UniformRand()*400.*mm;
    particleGun->SetParticlePosition(v1);
    particleGun->SetParticleMomentumDirection(v2-v1);
    
    particleGun->SetParticleEnergy(1.*MeV);
    
    particleGun->GeneratePrimaryVertex(anEvent);   //这个调用一次设置一次粒子，一次模拟要同时发射多个不同粒子就得多次调用它
}

void PrimaryGeneratorAction::SetSourceMuon(G4Event* anEvent)
{
    if (G4UniformRand()<0.5)
        particleGun->SetParticleDefinition(G4ParticleTable::GetParticleTable()->FindParticle("mu+"));
    else
        particleGun->SetParticleDefinition(G4ParticleTable::GetParticleTable()->FindParticle("mu-"));

    G4double R = 500.*mm;
    G4double x = R*(1.0 - 2*G4UniformRand());
    G4double z = sqrt(R*R - x*x)*(1.0 - 2*G4UniformRand());
    particleGun->SetParticlePosition(G4ThreeVector(x, R, z));
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0,-1,0));  // Vertical for now. Eventually implement cos^2 distribution
    
    particleGun->SetParticleEnergy(4.*GeV);
    
    particleGun->GeneratePrimaryVertex(anEvent);   //这个调用一次设置一次粒子，一次模拟要同时发射多个不同粒子就得多次调用它
}

void PrimaryGeneratorAction::SetSourceRa226(G4Event* anEvent)
{
    particleGun->SetParticleDefinition(G4ParticleTable::GetParticleTable()->FindParticle("gamma"));

    G4double Rmin = 500.*mm;
    G4double Rmax = 600.*mm;
    G4ThreeVector v1 = G4RandomDirection()*(Rmin + G4UniformRand()*(Rmax - Rmin));
    G4ThreeVector v2 = G4RandomDirection()*G4UniformRand()*400.*mm;
    particleGun->SetParticlePosition(v1);
    particleGun->SetParticleMomentumDirection(v2-v1);
    
    // set energy branch
    G4double e, b = 0.;
    std::map<double,double> ebmap;
    e = 186.211*keV; b += 0.03533; ebmap.insert(std::make_pair(b,e));
    e = 241.997*keV; b += 0.0719; ebmap.insert(std::make_pair(b,e));
    e = 295.224*keV; b += 0.1828; ebmap.insert(std::make_pair(b,e));
    e = 351.932*keV; b += 0.3534; ebmap.insert(std::make_pair(b,e));
    e = 609.316*keV; b += 0.4516; ebmap.insert(std::make_pair(b,e));
    e = 665.453*keV; b += 0.01521; ebmap.insert(std::make_pair(b,e));
    e = 768.367*keV; b += 0.0485; ebmap.insert(std::make_pair(b,e));
    e = 806.185*keV; b += 0.01255; ebmap.insert(std::make_pair(b,e));
    e = 934.061*keV; b += 0.03074; ebmap.insert(std::make_pair(b,e));
    e = 1120.287*keV; b += 0.1478; ebmap.insert(std::make_pair(b,e));
    e = 1155.190*keV; b += 0.01624; ebmap.insert(std::make_pair(b,e));
    e = 1238.110*keV; b += 0.05785; ebmap.insert(std::make_pair(b,e));
    e = 1280.960*keV; b += 0.01425; ebmap.insert(std::make_pair(b,e));
    e = 1377.669*keV; b += 0.03954; ebmap.insert(std::make_pair(b,e));
    e = 1401.516*keV; b += 0.01324; ebmap.insert(std::make_pair(b,e));
    e = 1407.993*keV; b += 0.02369; ebmap.insert(std::make_pair(b,e));
    e = 1509.217*keV; b += 0.02108; ebmap.insert(std::make_pair(b,e));
    e = 1620.740*keV; b += 0.0151; ebmap.insert(std::make_pair(b,e));
    e = 1661.316*keV; b += 0.01037; ebmap.insert(std::make_pair(b,e));
    e = 1729.640*keV; b += 0.02817; ebmap.insert(std::make_pair(b,e));
    e = 1764.539*keV; b += 0.1517; ebmap.insert(std::make_pair(b,e));
    e = 1847.420*keV; b += 0.0200; ebmap.insert(std::make_pair(b,e));
    e = 2118.536*keV; b += 0.01148; ebmap.insert(std::make_pair(b,e));
    e = 2204.071*keV; b += 0.0489; ebmap.insert(std::make_pair(b,e));
    e = 2447.673*keV; b += 0.01536; ebmap.insert(std::make_pair(b,e));
    
    // sampling
    G4double sample = G4UniformRand()*b;
    for (auto im=ebmap.begin(); im!=ebmap.end(); im++)
        if (sample < im->first){
            e = im->second;
            break;
        }
    particleGun->SetParticleEnergy(e);
    
    particleGun->GeneratePrimaryVertex(anEvent);   //这个调用一次设置一次粒子，一次模拟要同时发射多个不同粒子就得多次调用它
}

void PrimaryGeneratorAction::SetSourceGamma(G4Event* anEvent)
{
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* pp = 0;

    // Geant4已经定义的粒子
    pp = particleTable->FindParticle("gamma");
  
    if (pp)
        particleGun->SetParticleDefinition(pp);
    else
        G4cout<<"Null pp in PrimaryGeneratorAction::SetParticleGun()"<<G4endl;

    // primary particle position
    G4double envSizeXY = 0.*cm;
    G4double envSizeZ = 0.*mm;
    G4double x = envSizeXY * (G4UniformRand()-0.5) + 0.;
    G4double y = envSizeXY * (G4UniformRand()-0.5) + 0.;
    G4double z = envSizeZ * (G4UniformRand()-0.5) + 0.;
    particleGun->SetParticlePosition(G4ThreeVector(x, y, z));

    // primary particle kinematics
    G4double theta,phi;
    theta = acos(2.*G4UniformRand()-1.);   // theta range, even distribution by solid angle
    phi = G4UniformRand()*2.0*pi;       // phi range
    particleGun->SetParticleMomentumDirection(G4ThreeVector(sin(theta)*cos(phi), sin(theta)*sin(phi), cos(theta)));
    
    // primary particle kinetic energy
    G4double deltaE,centerE;
    deltaE = 0.*keV;
    centerE = 2.*MeV;
    particleGun->SetParticleEnergy(centerE + deltaE*(G4UniformRand()-0.5));
  
    particleGun->GeneratePrimaryVertex(anEvent);   //这个调用一次设置一次粒子，一次模拟要同时发射多个不同粒子就得多次调用它
}

