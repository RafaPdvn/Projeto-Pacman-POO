#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "allegro5/allegro_acodec.h"
#include <allegro5/allegro_primitives.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include "Parede.h"
#include "Pilula.h"
#include "Pacman.h"

using namespace std;

int main(){
    Parede *pr;
    Pilula *pl;
    Pacman *pc;

    int psPacX = 495, psPacY = 500, mpx = 9, mpy = 9;
    int score = 0, coins = 180;


    int mapa[19][19] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1,
                        1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
                        1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
                        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                        1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
                        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                        1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
                        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                        1, 0, 1, 0, 1, 0, 1, 1, 0, 6, 0, 1, 1, 0, 1, 0, 1, 0, 1,
                        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                        1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
                        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                        1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
                        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                        1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
                        1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
                        1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,};


    ALLEGRO_DISPLAY *display = NULL; //Tela
    ALLEGRO_BITMAP  *parede_img = NULL; //Imagem parede
    ALLEGRO_BITMAP  *pilula_img = NULL; //Imagem pilula
    ALLEGRO_BITMAP  *pacman_img = NULL; //Imagem pacman

    //Inicialização allegro

    if(!al_init()) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o Allegro",
        NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    if(!al_install_keyboard()) {
      fprintf(stderr, "failed to initialize the keyboard!\n");
      return -1;
   }


   if(!al_init_acodec_addon()){
      fprintf(stderr, "failed to initialize audio codecs!\n");
      return -1;
   }



    if(!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o al_init_image_addon!",
        NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    //Cria uma tela com essas dimensoes
    display = al_create_display(1050,1050);

    if(!display) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o display!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    //Declaração das imagens
    parede_img = al_load_bitmap("sprites/parede_img.png");
    pilula_img = al_load_bitmap("sprites/pilula_img.png");
    pacman_img = al_load_bitmap("sprites/pacman.png");


    if(!parede_img) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar a parede!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }

    if(!pilula_img) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar a pilula!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }

    al_init_primitives_addon();
    al_clear_to_color(al_map_rgb(0,0,0)); //Cor de background da tela (RGB)
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());


    do{
        int x = 50,y = 50;

        for(int i = 0; i<19;i++){//X
            for(int j = 0; j<19; j++){//Y
            int map_num = mapa[i][j];
                switch(map_num){//Identifica o elemento do mapa a ser construido
                case 0:
                    pl->constroi_pilula(pilula_img,x,y);
                    break;
                case 1:
                    pr->constroi_parede(parede_img,x,y);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    pc->constroi_pacman(pacman_img,psPacX,psPacY);
                    break;
                }
                x += 50;
            }
            y += 50;
            x = 50;
        }

        al_flip_display();//Atualiza o Buffer da Tela
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        if(events.type = ALLEGRO_EVENT_KEY_DOWN){
            switch(events.keyboard.keycode){
            case ALLEGRO_KEY_UP:
                if(mapa[mpx][mpy-1] == 0){
                mapa[mpx][mpy] = -1;
                psPacY -=1;
                score ++;
                }
                psPacX -= 50;
                break;
            case ALLEGRO_KEY_DOWN:
                if(mapa[mpx][mpy+1] == 0){
                mapa[mpx][mpy] = -1;
                psPacY +=1;
                score ++;
                }
                psPacX += 50;
                break;
            case ALLEGRO_KEY_LEFT:
                if(mapa[mpx-1][mpy] == 0){
                    mapa[mpx][mpy] = -1;
                    psPacY -=1;
                    score ++;
                }
                psPacY += 50;
                break;
            case ALLEGRO_KEY_RIGHT:
                if(mapa[mpx+1][mpy] == 0){
                mapa[mpx][mpy] = -1;
                psPacY +=1;
                score ++;
                }
                psPacX += 50;
                break;
            }

        }

        al_flip_display();//Atualiza o Buffer da Tela

    }while(score < coins);

    al_destroy_display(display); //Destroi a tela

    return 0;
}
