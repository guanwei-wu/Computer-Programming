#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

class attack_3:public attack{
public:
    attack_3():attack(){};
    ~attack_3(){};
    int get_bux(){return bullet_x-movement-30;}
    int get_buy(){return bullet_y+20;}
    void appear(SDL_Renderer &att_ren,SDL_Texture &att_texture){
        if(bullet_x-movement-30>=0){
            SDL_Rect att_rect;
            att_rect.x = bullet_x-movement-30;
            att_rect.y = bullet_y+20;
            att_rect.w = 30;
            att_rect.h = 30;

            SDL_RenderSetViewport(&att_ren, &att_rect);
            SDL_RenderCopy(&att_ren, &att_texture, NULL, NULL);
        }
        else {
            end=1;
        }

    }
};
