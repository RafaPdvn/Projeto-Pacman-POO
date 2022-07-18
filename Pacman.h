

#ifndef PACMAN_H
#define PACMAN_H
#include <string>

class Pacman{
   public:
        Pacman(ALLEGRO_BITMAP *);
        ~Pacman();
       void constroi_pacman(ALLEGRO_BITMAP*,int,int);
       void destroi_pacman(ALLEGRO_BITMAP*);
   private:
       const char img[25] = "sprites/pacman.png";


};

#endif
