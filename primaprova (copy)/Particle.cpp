#include "Particle.hpp"
#include <iostream>
int Particle::findParticle(ParticleType* rt){

int index{-1};

    for ( auto it= fParticleType.begin(); it<fParticleType.end();++it) {


if(*rt==*it){index=std::distance(fParticleType.begin(),it);}

    }
return fIndex;



}


Particle::Particle(const char* name, double px, double py, double pz): fPx{px},fPy{py},fPz{pz}{
    ParticleType a=ParticleType(name,0.,0);
   fIndex=findParticle(&a);
   if(fIndex<0){std::cout<<"Particella non trovata";}

}
Particle::Particle(const char* name): fPx{0},fPy{0},fPz{0}{
    ParticleType b=ParticleType(name,0.,0);
fIndex=findParticle(&b);
   if(fIndex<0){std::cout<<"Particella non trovata";}


}

void Particle::Setter(const char* name){
   // ResonanceType a=ResonanceType(name,0,0);

    //fIndex=findParticle(a);

}
