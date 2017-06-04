#include "Canal.h"
#include "GerenciamentoCanal.h"
#include "Canal.h"
#include <string>
#include <stdlib.h>
#include <vlc/vlc.h> 
#include <unistd.h> //biblioteca para utilizar funcao sleep
#include <iostream>

using namespace std;

int main(){
	
	Canal p1(67, "FOX");
	Canal p2(63, "Discovery");
	Canal p3(7, "Axn");
	Canal p4(30, "Warner");
	Canal p5(32, "Hbo");
	Canal p6(110, "Polishop");

	GerenciamentoCanal canal;

	
	int i, comando, status;
	libvlc_media_player_t *mediaPlay; //mp
	libvlc_instance_t *vlc; //vlc
	libvlc_media_list_t *mediaL; //ml
	libvlc_media_list_player_t *mediaListP; //mlp
	libvlc_media_t *mediaD; //md
	
	vlc = libvlc_new (0, NULL);  // Carrega a engine VLC 
	mediaL = libvlc_media_list_new(vlc); // Cria uma lista vazia
	mediaListP = libvlc_media_list_player_new(vlc); // Cria um novo media_list_player
	mediaPlay = libvlc_media_player_new(vlc); // Cria um objeto media_player vazio

	canal.addCanal(p1);
    mediaD = libvlc_media_new_path (vlc, "fox.mp4"); // Cria uma midia para certo arquivo  		
    libvlc_media_list_add_media (mediaL, mediaD); // Adiciona a instancia da midia a lista de midia 	

	canal.addCanal(p2);				
    mediaD = libvlc_media_new_path (vlc, "discoverykids.mp4"); // Cria uma midia para certo arquivo 	
    libvlc_media_list_add_media (mediaL, mediaD);// Adiciona a instancia da midia a lista de midia 		

    canal.addCanal(p3);				
    mediaD = libvlc_media_new_path (vlc, "axn.mp4"); // Cria uma midia para certo arquivo 	
    libvlc_media_list_add_media (mediaL, mediaD);// Adiciona a instancia da midia a lista de midia 			 		

	canal.addCanal(p4);				
    mediaD = libvlc_media_new_path (vlc, "warner.mp4"); // Cria uma midia para certo arquivo 	
    libvlc_media_list_add_media (mediaL, mediaD);// Adiciona a instancia da midia a lista de midia 			 		

	canal.addCanal(p5);				
    mediaD = libvlc_media_new_path (vlc, "hbo.mp4"); // Cria uma midia para certo arquivo 	
    libvlc_media_list_add_media (mediaL, mediaD);// Adiciona a instancia da midia a lista de midia 			 		
	 
	canal.addCanal(p6);				
    mediaD = libvlc_media_new_path (vlc, "polishop.mp4"); // Cria uma midia para certo arquivo 	
    libvlc_media_list_add_media (mediaL, mediaD);// Adiciona a instancia da midia a lista de midia 			 		
	
	libvlc_media_list_player_set_media_list (mediaListP, mediaL); // Configura a lista de midia associada com o player
	libvlc_media_list_player_set_media_player(mediaListP, mediaPlay);// Substitui o media player em media_list_player com esta instanci
	status = 1;
	libvlc_media_list_player_play(mediaListP); //Abre o player

	while(status) {
		comando = getchar();
		switch(comando)
		{
			case 's':	// para de tocar
				if(mediaListP) {
					libvlc_media_list_player_stop(mediaListP);
					printf ("STOP\n");
				}
				break;
				
			case 'n':	// proxima midia da lista
				if(mediaListP) {
					//libvlc_media_list_player_next(mlp);
					canal.upCanal(mediaListP);

					cout << "" << canal.getCanalAtual(); 
				}
				break;
				
			case 'b':	// midia anterior da lista
				if(mediaListP) {
					canal.downCanal(mediaListP);
					printf ("ANTERIOR\n");
				}
				break;
				
			case 'q':	// sai e encerra o player
				printf("Adeus!\n");
				status = 0;
				break;
			
			case 'o':   /* pausa a midia atual */
				if(mediaListP) {
					libvlc_media_list_player_pause(mediaListP); 
					printf ("PAUSE\n");
				}
				break;			
		}
	}
 
	libvlc_release (vlc);


	return 0;
}