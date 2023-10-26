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

ParticleType(char* name, double mass, int charge);

};

#endif

