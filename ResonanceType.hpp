#ifndef RESONANCETYPE_HPP
#define SRESONANCETYPE_HPP


#include "ParticleType.hpp";
#include "iostream";

class ResonanceType : public ParticleType
{

    double const fWidth;

 public:
  ResonanceType(char*, double const, int const, double const);
  
  double getfWidth() const;
  void Print();
 
};

#endif
