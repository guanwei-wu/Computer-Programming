#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

class star:public fire_ball
    {
    public:
        //¥s¥X¹D¨ã
        bool sign;
        star():fire_ball(){sign=0;};
        ~star(){};
        void operator*(int& score){score+=300;};
        void work(bool& killall){
            killall=1;
        };
        void operator*(SDL_Event &e){
            if(e.type == SDL_KEYDOWN && e.key.keysym.sym==SDLK_z && e.key.repeat==0){
                sign=1;
            }
            else if(e.type == SDL_KEYUP && e.key.keysym.sym==SDLK_z && e.key.repeat==0){
                sign=0;
            }
}

    private:
        int item_w;
        int item_h;
    };
