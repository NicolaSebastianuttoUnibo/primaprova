
#include "ResonanceType.hpp";

  ResonanceType::ResonanceType(char* name, double const mass, int const charge, double const Width) : ParticleType( name, mass, charge), fWidth(Width) {}
  
  double ResonanceType::getfWidth() const { return fWidth; }
  
  void ResonanceType::Print() {Print();
  std::cout << "width: " << fWidth <<'/n';}
