#include "GerenciamentoCanal.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vlc/vlc.h> 
#include <unistd.h>

using namespace std;

GerenciamentoCanal::GerenciamentoCanal(){
	numCanaisADD = 0;
	canalAtual = 0;
}

GerenciamentoCanal::~GerenciamentoCanal(){

}
void GerenciamentoCanal::addCanal(Canal c){
	canais[numCanaisADD] = c;
	numCanaisADD++;

}

void GerenciamentoCanal::removerCanal(int numero){
	for(int i = 0; i < numCanaisADD; i++){
		if(numero == canais[i].getNumCanal()){
			canais[i].setNumCanal(0);
		}
	}
}

void GerenciamentoCanal::listarCanal(){
	cout <<"\tCanais Cadastrados" << endl;
	for(int i = 0; i < numCanaisADD; i++){
		if(!canais[i].getNumCanal()){

		}else{
			cout << canais[i].getNumCanal() << " - " << canais[i].getNomeCanal() << endl;
		}
	}

}

void GerenciamentoCanal::upCanal(libvlc_media_list_player_t *mediaListP){
	libvlc_media_list_player_next(mediaListP);
	canalAtual++;
}
void GerenciamentoCanal::downCanal(libvlc_media_list_player_t *mediaListP){
	libvlc_media_list_player_previous(mediaListP);
	canalAtual--;
}

int GerenciamentoCanal::getCanalAtual(){
	return canalAtual;
}