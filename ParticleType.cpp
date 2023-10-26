#include "particleType.hpp"
#include <iostream>
char* ParticleType::GetName(){
return fName;
}

double ParticleType::GetMass(){
return fMass;
}

int ParticleType::GetCharge(){
return fCharge;
}

void ParticleType::Print(){
std::cout<<"Name: "<<fName<<"\nfMass: "<<fMass<<"\nCharge: "<<fCharge;
}

ParticleType::ParticleType(char* name, double mass, int charge): fName(name), fMass(mass),fCharge(charge) {}

