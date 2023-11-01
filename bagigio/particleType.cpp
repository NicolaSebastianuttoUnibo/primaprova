#include "ParticleType.hpp"
#include <iostream>
 const char* ParticleType::GetName(){
    return fName;
}

const double ParticleType::GetMass(){
    return fMass;
}

const int ParticleType::GetCharge(){
    return fCharge;
}

void ParticleType::Print(){
    std::cout<<"Name: "<<fName<<"\nfMass: "<<fMass<<"\nCharge: "<<fCharge;
}

ParticleType::ParticleType(const char* name, const double mass, const int charge): fName(name), fMass(mass),fCharge(charge) {

}
ParticleType::ParticleType(const char* name): fName(name), fMass(0),fCharge(0) {}


  bool ParticleType::operator==(const ParticleType& pt)           const   {
  return true;
}
