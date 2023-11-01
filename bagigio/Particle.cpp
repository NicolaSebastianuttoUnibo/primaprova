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
    ParticleType a=ParticleType(name,0,0);

    fIndex=findParticle(&a);
}
void Particle::Setter(int index){
    fIndex=index;
}

void Particle::PrintAll(){
    for(int i=0;i<fParticleType.size();i++){
        std::cout<<(i+1)<<"a particella:\n";
        (fParticleType[i]).Print();
        std::cout<<"\n";
    }
}
void Particle::PrintParticle(){
    std::cout<<"index: "<<fIndex<<"\n"<<"Name: "<< (fParticleType[fIndex]).GetName()<<"\nPx: "<<fPy<<"\nPy: "<<fPz<<"\nPz: "<<fPx<<"\n";

  
}


 int Particle::GetfIndex(){return fIndex;}

 /*static*/ void Particle::AddParticleType (const char* name, const double Mass, const int charge ){
    ParticleType* a=&fParticleType[fIndex];
    if (fNParticleType!=10 || findParticle(a)!=-1)
    { ParticleType npart(name, Mass, charge );
    fParticleType.push_back(npart);
    }
}

int Particle::SetfIndex() {
    std::cout << "fIndex:";
std::cin>> fIndex;
std::cout << '\n';


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
    ParticleType a=fParticleType[fIndex];
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
  double Minv=std::pow( std::sqrt(this->GetEnergy()+p.GetEnergy())*(this->GetEnergy()+p.GetEnergy())-(std::sqrt(this->GetPx()+p.GetPx())*(std::sqrt(this->GetPx()+p.GetPx())+std::sqrt(this->GetPy()+p.GetPy())*std::sqrt(this->GetPy()+p.GetPy()) + std::sqrt(this->GetPz()+p.GetPz())*std::sqrt(this->GetPz()+p.GetPz()))),2);
    return Minv;
}

void Particle::SetP(double Px, double Py, double Pz)
{
  fPx=Px;
  fPy=Py;
  fPz=Pz;
}





