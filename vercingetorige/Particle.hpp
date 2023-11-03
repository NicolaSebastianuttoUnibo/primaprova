#ifndef PARTICLE_HPP
#define PARTICLE_HPP


#include "ResonanceType.hpp"
#include <array>
#include <vector>




class Particle{
static const int fMaxNumParticleType{10};
 static int findParticle(ParticleType* rt);



 static std::vector<ParticleType*> fParticleType;





static int fNParticleType;
 int fIndex=10;
double fPx;
double fPy;
double fPz;

void Boost(double bx, double by, double bz);

public: 
Particle(const char* name, double px=0, double py=0, double pz=0);
//Particle(const char* name);

 void Setter(const int index);
void Setter(const char* name);

void PrintAll();
void PrintParticle();

int GetfIndex();
 static void AddParticleType (ResonanceType);
void SetfIndex(int);

double GetPx();
double GetPy();
double GetPz();
double GetMassParticle() const;
double GetImpulse();
double GetEnergy() const;
double InvMass(Particle &p);
void SetP(double,double,double);

int Decay2body(Particle &dau1,Particle &dau2) const;
};

#endif