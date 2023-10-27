
#include "ResonanceType.hpp"

  ResonanceType::ResonanceType(const char* name, const double mass,const  int charge, const double Width) : ParticleType( name, mass, charge), fWidth(Width) {}
  
  const double ResonanceType::getfWidth() const { return fWidth; }
  
  void ResonanceType::Print() {Print();
  std::cout << "width: " << fWidth <<'/n';}

