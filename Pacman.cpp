


//Bibliotecas --------------------------------
#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#include <string>
#include "Pacman.h"
//--------------------------------------------
using namespace std;

Pacman::Pacman(ALLEGRO_BITMAP *image){
    image = NULL;
}

Pacman::~Pacman(void){

}

void Pacman::constroi_pacman(ALLEGRO_BITMAP* image, int x, int y){
    al_draw_bitmap(image,x,y,0); //Desenha a imagem
}

void Pacman::destroi_pacman(ALLEGRO_BITMAP* image){

}


