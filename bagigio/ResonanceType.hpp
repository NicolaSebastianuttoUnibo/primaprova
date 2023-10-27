#ifndef RESONANCETYPE_HPP
#define RESONANCETYPE_HPP

#include "iostream"
#include "particleType.hpp"

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