#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

class diamond
    {
    public:
        //�غc�l�M�Ѻc�l
        diamond();
        ~diamond(){};
        //�s�X�D��
        void get(SDL_Texture*, SDL_Renderer*, int, int);
        void operator*(int&);

    private:
        int item_w;
        int item_h;
    };


