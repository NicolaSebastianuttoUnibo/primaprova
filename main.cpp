#include <iostream>
#include <array>
#include "ResonanceType.hpp"

int main(){
    ParticleType* particleArray[2];
    ParticleType part;
    ResonanceType reso;
    std::cin >> part;
    std::cin >> reso;
    particleArray[0] = &part;
    particleArray[1] = &reso;
    for (int i{0}; i < 1; i++){
        particleArray[i].Print();
    }
}
