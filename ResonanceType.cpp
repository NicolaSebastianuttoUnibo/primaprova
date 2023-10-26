#include "ResonanceType.hpp";
ResonanceType::class ResonanceType : public ParticleType
{


  ResonanceType(char* fName, double const fMass, int const fCharge, double const fWidth) : fName(name), fMass(Mass), fCharge(Charge), fWidth(Width) ;
  
  double getfWidth() const { return fWidth; }
  
  void Print() {Print();
  std::cout << "width: " << fWidth <<'/n';}
 
};
