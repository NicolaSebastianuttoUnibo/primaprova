#ifndef PARTICLE_HPP
#define PARTICLE_HPP


#include "ResonanceType.hpp"
#include <array>
#include <vector>



class Particle{
static const int fMaxNumParticleType{10};
void findParticle(ParticleType rt);
const char* names[5]={"A","B","C","D","E"};
const double mass[5]={1,2,3,4,5};
const double charge[5]={1,2,3,4,5};
const double width[5]={1,2,3,4,5};



std::vector<ParticleType> fParticleType{
    ResonanceType(names[0],mass[0],charge[0],width[0]),
    ResonanceType(names[1],mass[1],charge[1],width[1]),
    ResonanceType(names[2],mass[2],charge[2],width[2]),
    ResonanceType(names[3],mass[3],charge[3],width[3]),
    ResonanceType(names[4],mass[4],charge[4],width[4])


};



static int fNParticleType;
int fIndex=10;
double fPx;
double fPy;
double fPz;
public: 
Particle(const char* name, double px, double py, double pz);
Particle(const char* name);


};

#endif
