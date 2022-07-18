
//Bibliotecas --------------------------------
#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#include <string>
#include "Pilula.h"
//--------------------------------------------
using namespace std;

Pilula::Pilula(ALLEGRO_BITMAP *image){
    image = NULL;
}

Pilula::~Pilula(void){

}

void Pilula::constroi_pilula(ALLEGRO_BITMAP* image, int x, int y){
    al_draw_bitmap(image,x,y,0); //Desenha a imagem
}

void Pilula::destroi_pilula(ALLEGRO_BITMAP* image){

}
