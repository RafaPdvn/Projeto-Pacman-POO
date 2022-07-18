
//Bibliotecas --------------------------------
#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#include "Parede.h"
//--------------------------------------------
using namespace std;

Parede::Parede(ALLEGRO_BITMAP *image){
    image = NULL;
}

Parede::~Parede(void){

}

void Parede::constroi_parede(ALLEGRO_BITMAP* image, int x, int y){
    al_draw_bitmap(image,x,y,0); //Desenha a imagem
};

void Parede::destroi_parede(ALLEGRO_BITMAP* image){

};



