
#ifndef PAREDE_H
#define PAREDE_H
#include <string>
#include <string.h>
#include <stdio.h>

class Parede{
   public:
        Parede(ALLEGRO_BITMAP *);
        ~Parede();
        void constroi_parede(ALLEGRO_BITMAP*,int,int);
        void destroi_parede(ALLEGRO_BITMAP*);
   private:

};

#endif
