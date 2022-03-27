#include "attack.h"

attack::attack(){
    bullet_x=0;
    bullet_y=0;
    sign=0;
    start=1;
    movement=0;
    end=0;
}

void attack::operator+(int m){
    movement+=m;
}

void attack::operator*(SDL_Event &e){
    if(e.type == SDL_KEYDOWN && e.key.keysym.sym==SDLK_SPACE && e.key.repeat==0){
        sign=1;
    }

    else if(e.type == SDL_KEYUP && e.key.keysym.sym==SDLK_SPACE && e.key.repeat==0){
        sign=0;
    }
}

void attack::position(int x,int y){
    bullet_x=x;
    bullet_y=y;
}

void attack::appear(SDL_Renderer &att_ren,SDL_Texture &att_texture){
    if(bullet_y-movement-30>=0){
        SDL_Rect att_rect;
        att_rect.x = bullet_x+ 25;
        att_rect.y = bullet_y-movement- 30;
        att_rect.w = 30;
        att_rect.h = 30;

        SDL_RenderSetViewport(&att_ren, &att_rect);
        SDL_RenderCopy(&att_ren, &att_texture, NULL, NULL);
    }
    else {
        end=1;
    }

}

int attack::get_bux(){
    return bullet_x+ 25;
}

int attack::get_buy(){
    return bullet_y-movement- 30;;
}


const bool attack::get_sign(){
    return sign;
}


void attack::started(){
    start=0;
}

void attack::restart(){
    start=1;
    movement=0;
    end=0;
}







