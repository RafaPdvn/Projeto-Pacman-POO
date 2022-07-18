
#ifndef PILULA_H
#define PILULA_H

#include <string>
class Pilula{
   public:
        Pilula(ALLEGRO_BITMAP *);
        ~Pilula();
        void constroi_pilula(ALLEGRO_BITMAP*,int,int);
        void destroi_pilula(ALLEGRO_BITMAP*);
   private:
       const char img[25] = "sprites/pilula_img.png";

};

#endif
