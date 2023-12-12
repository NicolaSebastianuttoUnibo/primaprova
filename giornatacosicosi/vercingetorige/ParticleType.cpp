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
    std::cout<<"Name: "<<fName<<"\nfMass: "<<fMass<<"\nCharge: "<<fCharge;
}

ParticleType::ParticleType(const char* name, const double mass, const int charge): fName(name), fMass(mass),fCharge(charge) {

}
/*ParticleType::ParticleType(const char* name): fName(name), fMass(0),fCharge(0) {}

*/

  bool ParticleType::operator==(const ParticleType& pt)  const   {
    //std::cout<<pt.GetName()<<fName<<"\n";
  return fName==pt.GetName();
}

double ParticleType::GetWidth() const {
    return 0;
}
