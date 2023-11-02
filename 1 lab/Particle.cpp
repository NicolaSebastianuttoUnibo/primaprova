#include "Particle.hpp"
#include <iostream>

 std::vector<ParticleType*> Particle::fParticleType;
int Particle::findParticle(ParticleType* rt){

int index{-1};

     for ( auto it= fParticleType.begin(); it<fParticleType.end();++it) {


if(*(&rt)==*it){index=std::distance(fParticleType.begin(),it);}

    } 
     
return index;



}


Particle::Particle(const char* name, double px, double py, double pz): fPx{px},fPy{py},fPz{pz}{
    ParticleType a=ParticleType(name,0.,0);
   fIndex=findParticle(&a);
   if(fIndex<0){std::cout<<"Particella non trovata";}
for(auto it=istParticleType.begin(); it<istParticleType.end();it++){
  fParticleType.push_back(&(*it));
}
}
Particle::Particle(const char* name): fPx{0},fPy{0},fPz{0}{
    ParticleType b=ParticleType(name,0.,0);
fIndex=findParticle(&b);
   if(fIndex<0){std::cout<<"Particella non trovata";}
for(auto it=istParticleType.begin(); it<istParticleType.end();it++){
  fParticleType.push_back(&(*it));}

}

void Particle::Setter(const char* name){
    ParticleType a=ParticleType(name,0,0);

    fIndex=findParticle(&a);
}
void Particle::Setter(int index){
    fIndex=index;
}

void Particle::PrintAll(){
    for(unsigned int i=0;i<fParticleType.size();i++){
        std::cout<<(i+1)<<"a particella:\n";
        (*fParticleType[i]).Print();
        std::cout<<"\n";
    }
}
void Particle::PrintParticle(){
    std::cout<<"index: "<<fIndex<<"\n"<<"Name: "<< (*(fParticleType[fIndex])).GetName()<<"\nPx: "<<fPy<<"\nPy: "<<fPz<<"\nPz: "<<fPx<<"\n";

  
}


 int Particle::GetfIndex(){return fIndex;}
 

void Particle::AddParticleType (const char* name, const double Mass, const int charge ){
   ParticleType* a= new ParticleType(name,Mass,charge);
   
    if (fParticleType.size()<=fMaxNumParticleType || findParticle(a)!=-1)
    { ParticleType npart(name, Mass, charge );
    fParticleType.push_back(a);
    }
}

void  Particle::SetfIndex(int index) {
    fIndex=index;


}


double Particle::GetPx(){
  return fPx;
}
double Particle::GetPy(){
  return fPy;
}
double Particle::GetPz(){
  return fPz;
}

double Particle::GetMassParticle() const{
    ParticleType a=*fParticleType[fIndex];
  return a.GetMass();
}

double Particle::GetImpulse(){
  double P=std::sqrt(fPx*fPx+fPy*fPy+fPz*fPz);
  return P;
}

double Particle::GetEnergy() const{
    Particle a=*this;
  double E=std::sqrt((a.GetMassParticle())*(a.GetMassParticle())+(a.GetImpulse())*(a.GetImpulse()));
  return E;
}

double Particle::InvMass(Particle &p)
{
  double Minv=std::sqrt(
    std::pow(this->GetEnergy()+p.GetEnergy(),2)
    -(std::pow(fPx+p.GetPx(),2)+std::pow(fPy+p.GetPy(),2)+std::pow(fPz+p.GetPz(),2))
    );
    return Minv;
}

void Particle::SetP(double Px, double Py, double Pz)
{
  fPx=Px;
  fPy=Py;
  fPz=Pz;
}