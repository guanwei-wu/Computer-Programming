#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

 class golden_heart:public heart{
    public:
        golden_heart():heart(){};
        ~golden_heart(){};
        void operator+(int& life){life=3;};
        void operator*(int& score){score+=200;}
    private:
        int item_w;
        int item_h;
    };
