#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

class attack_1:public attack{
public:
    attack_1():attack(){};
    ~attack_1(){};
    int get_bux(){return bullet_x+ 25;}
    int get_buy(){return bullet_y+movement+75;}
    void appear(SDL_Renderer &att_ren,SDL_Texture &att_texture){
        if(bullet_y+movement-30<=900){
            SDL_Rect att_rect;
            att_rect.x = bullet_x+ 25;
            att_rect.y = bullet_y+movement+75;
            att_rect.w = 30;
            att_rect.h = 30;

            SDL_RenderSetViewport(&att_ren, &att_rect);
            SDL_RenderCopy(&att_ren, &att_texture, NULL, NULL);
        }
        else {
            end=1;
        }
    };

};
