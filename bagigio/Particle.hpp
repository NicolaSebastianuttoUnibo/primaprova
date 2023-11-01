#ifndef PARTICLE_HPP
#define PARTICLE_HPP


#include "ResonanceType.hpp"
#include <array>
#include <vector>
#include "math.h"



class Particle{
static const int fMaxNumParticleType{10};
int findParticle(ParticleType* rt);
const char* names[5]={"A","B","C","D","E"};
const double mass[5]={1,2,3,4,5};
const double charge[5]={1,2,3,4,5};
const double width[5]={1,2,3,4,5};



std::vector<ParticleType> fParticleType{
    ParticleType(names[0],mass[0],charge[0]),
    ParticleType(names[1],mass[1],charge[1]),
    ParticleType(names[2],mass[2],charge[2]),
    ParticleType(names[3],mass[3],charge[3]),
    ParticleType(names[4],mass[4],charge[4])


};



static int fNParticleType;
int fIndex=10;
double fPx;
double fPy;
double fPz;
public: 
Particle(const char* name, double px, double py, double pz);
Particle(const char* name);

 void Setter(const int index);
void Setter(const char* name);

void PrintAll();
void PrintParticle();

int GetfIndex();
 /*static*/ void AddParticleType (const char* name, const double Mass, const int charge );
int SetfIndex();

double GetPx();
double GetPy();
double GetPz();
double GetMassParticle() const;
double GetImpulse();
double GetEnergy() const;
double InvMass(Particle &p);
void SetP(double,double,double);

};

#endif



std::vector<ParticleType> fParticleType{
    ParticleType(names[0],mass[0],charge[0]),
    ParticleType(names[1],mass[1],charge[1]),
    ParticleType(names[2],mass[2],charge[2]),
    ParticleType(names[3],mass[3],charge[3]),
    ParticleType(names[4],mass[4],charge[4])


};



static int fNParticleType;
int fIndex=10;
double fPx;
double fPy;
double fPz;
public: 
Particle(const char* name, double px, double py, double pz);
Particle(const char* name);

 void Setter(const int index);
void Setter(const char* name);

void PrintAll();
void PrintParticle();



};

#endif
