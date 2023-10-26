#ifndef RESONANCETYPE_HPP
#define SRESONANCETYPE_HPP

#include "iostream";
#include "ParticleType.hpp";

class ResonanceType : public ParticleType
{
public:
  ResonanceType(char*, double const, int const, double const);
  
  double getfWidth() const;
  void Print();

bool operator==(const ParticleType lhs, const ParticleType rhs){
  return lhs.isEqual( rhs ) && lhs.fName == rhs.fName && lhs.fMass == rhs.fMass && lhs.fCharge == rhs.fCharge && lhs.fWidth == rhs.fWidth;
}

  private:
    double const fWidth;

};

#endif
