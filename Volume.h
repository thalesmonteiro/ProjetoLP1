#ifndef Volume_h
#define Volume_h
#include <string>


class Volume {
private:
    int volume;
public:
    void setVolume(int);
    int getVolume();
    void AumentarVolume();
    void BaixarVolume();
};

#endif