#include "Volume.h"

using namespace std;

void Volume::setVolume(int volume){
    this->volume = volume;
}

int Volume::getVolume(){
    return volume;
}

void Volume::AumentarVolume(){
    volume++;
}

void Volume::BaixarVolume(){
    volume--;
}

