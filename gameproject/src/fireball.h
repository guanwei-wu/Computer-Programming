#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

class fire_ball
     {
     public:
         //�غc�l�M�Ѻc�l
         fire_ball();
         ~fire_ball(){};
         //�s�X�D��
         void get(SDL_Texture*, SDL_Renderer*, int, int);
         void operator*(int&);
         virtual void work(bool&);

     private:
         int item_w;
         int item_h;
     };

