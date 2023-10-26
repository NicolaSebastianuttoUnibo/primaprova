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

  private:
    double const fWidth;

};

#endif
