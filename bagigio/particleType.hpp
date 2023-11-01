#ifndef PARTICLETYPE_HPP
#define PARTICLETYPE_HPP

class ParticleType{
private:

const char* fName;
const double fMass;
const int fCharge;
public:

const char* GetName();
const double GetMass();
const int GetCharge();
virtual void Print();

ParticleType(const char* name,const  double mass, const int charge);
ParticleType(const char* name);

  bool operator==(const ParticleType& pt) const;

};


#endif


/*

static void AddParticleType (const char* name, const double Mass, const int charge );
static void AddParticleType (const char* name, const double Mass, const int charge ){
    if (fNParticleType!=10 || FindParticle()!=-1)
    { ParticleType npart(name, Mass, charge );
    fParticleType.pushback(npart);
    }
}


*/
