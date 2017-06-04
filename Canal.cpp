#include "Canal.h"

using namespace std;

Canal::Canal(){

}
Canal::~Canal(){

}

Canal::Canal(int canal, string nomeCanal){
	setNumCanal(canal);
	setNomeCanal(nomeCanal);
}

void Canal::setNumCanal(int canal){
    numeroCanal = canal;
}

int Canal::getNumCanal(){
    return numeroCanal;
}

void Canal::setNomeCanal(string nomeCanal){
    this->nomeCanal = nomeCanal;
}

string Canal::getNomeCanal(){
    return nomeCanal;
}

