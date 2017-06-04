#ifndef Canal_h
#define Canal_h
#include <string>

class Canal{
private:
    int numeroCanal;
    std::string nomeCanal;
public:
	Canal();
	Canal(int, std::string);
	~Canal();
    void setNumCanal(int);
    int getNumCanal();
    void setNomeCanal(std::string);
    std::string getNomeCanal();
};

#endif  //canal_h