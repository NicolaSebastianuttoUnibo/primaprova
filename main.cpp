#include <array>
#include "ResonanceType.hpp"

int main(){
    ParticleType* particleArray[2];
    char name1 = 'A';
    char name2 = 'B';
    ParticleType part(&name1, 2., 3);
    ResonanceType reso(&name2, 4., 5, 6.);
    particleArray[0] = &part;
    particleArray[1] = &reso;
    for (int i{0}; i < 1; i++){
        (*particleArray[i]).Print();
    }
}
