#include "Particle.hpp"
#include <iostream>
void Particle::findParticle(ResonanceType rt){

int index{-1};

    for ( auto it= fParticleType.begin(); it<fParticleType.end();++it) {


if(rt==*it){index=std::distance(fParticleType.begin(),it);}

    }
return fIndex;



}


Particle::Particle(const char* name, double px, double py, double pz): fPx{px},fPy{py},fPz{pz}{
   fIndex=findParticle(this);
   if(fIndex<0){std::cout<<"Particella non trovata"};

}
Particle::Particle(const char* name): fPx{0},fPy{0},fPz{0}{
fIndex=findParticle(this);
   if(fIndex<0){std::cout<<"Particella non trovata"};


}
