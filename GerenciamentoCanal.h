#ifndef GerenciamentoCanal_h
#define GerenciamentoCanal_h
#include "Canal.h"
#include <string>
 #include <stdlib.h>
 #include <vlc/vlc.h>

class GerenciamentoCanal{
protected:
	int numCanaisADD;
	int canalAtual;
private:
	Canal canais[50];
public:
	GerenciamentoCanal();
	~GerenciamentoCanal();
    void addCanal(Canal);
    void removerCanal(int);
    void listarCanal();
    void upCanal(libvlc_media_list_player_t *);
    void downCanal(libvlc_media_list_player_t *);
    int getCanalAtual();
};

#endif