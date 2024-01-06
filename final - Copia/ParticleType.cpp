#include "ParticleType.hpp"
#include <iostream>
 const char* ParticleType::GetName() const{
    return fName;
}

 double ParticleType::GetMass() const{
    return fMass;
}

 int ParticleType::GetCharge() const{
    return fCharge;
}

void ParticleType::Print(){
    std::cout<<"\nName: "<<fName<<"\nfMass: "<<fMass<<"\nCharge: "<<fCharge<<"\n";
}

ParticleType::ParticleType(const char* name, const double mass, const int charge): fName(name), fMass(mass),fCharge(charge) {

}



bool ParticleType::operator==(const ParticleType* pt) const {
  std::string a=fName;
  std::string b=pt->GetName();

    return a==b;
}

double ParticleType::GetWidth() const {
    return 0;
}