#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

class heart
    {
    public:
        //建構子和解構子
        heart();
        ~heart(){};
        //叫出道具
        void get(SDL_Texture*, SDL_Renderer*, int, int);
        void operator+(int&);
        void operator*(int&);

    private:
        int item_w;
        int item_h;
    };

