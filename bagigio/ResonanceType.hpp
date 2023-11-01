#ifndef RESONANCETYPE_HPP
#define RESONANCETYPE_HPP

#include "iostream"
#include "ParticleType.hpp"

class ResonanceType : public ParticleType
{
public:
  ResonanceType(const char*,const double, const int , const double);
  
  const double getfWidth() const;
   void Print();



  private:
    double const fWidth;

};

#endif

/*

InvMass(Particle &p)
{
  double Minv= std::sqrt((this.GetEnergy+p.GetEnergy)^2-(std::sqrt(this.GetPx+p.GetPx)^2+std::sqrt(this.GetPy+p.GetPy)^2 + std::sqrt(this.GetPz+p.GetPz)^2)^2)
}


*/
