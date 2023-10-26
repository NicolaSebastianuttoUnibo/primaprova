#ifndef PARTICLETYPE_HPP
#define PARTICLETYPE_HPP

class ParticleType{

private: 
char* fName;
const double fMass;
const int fCharge;
public:

char* GetName();
double GetMass();
int GetCharge();
void Print();
bool operator==(const ParticleType lhs, const ParticleType rhs){
  return lhs.isEqual( rhs ) && lhs.fName == rhs.fName && lhs.fMass == rhs.fMass && lhs.fCharge == rhs.fCharge;
}

ParticleType(char* name, double mass, int charge);

};

#endif
