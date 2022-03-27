#include "man.h"
using namespace std;

man::man(){
    manpos_x = 210;
    manpos_y = 490;
    manv_x = 0;
    manv_y = 0;
    sign=0;
}

void man::operator*(SDL_Event &e){

    if(e.type == SDL_KEYDOWN){

        if(e.key.keysym.sym==SDLK_UP){
            manv_y=-2;
        }
        if(e.key.keysym.sym==SDLK_DOWN){
            manv_y=2;
        }
        if(e.key.keysym.sym==SDLK_LEFT){
            manv_x=-2;
        }
        if(e.key.keysym.sym==SDLK_RIGHT){
            manv_x=2;
        }
    }

    else if(e.type == SDL_KEYUP){

        if(e.key.keysym.sym==SDLK_UP){
            if(manv_y==-2) manv_y=0;
        }
        if(e.key.keysym.sym==SDLK_DOWN){
            if(manv_y==2) manv_y=0;
        }
        if(e.key.keysym.sym==SDLK_LEFT){
            if(manv_x==-2) manv_x=0;
        }
        if(e.key.keysym.sym==SDLK_RIGHT){
            if(manv_x==2) manv_x=0;
        }
    }

}

void man::operator~()
{
    manpos_x += manv_x;

    //If the dot went too far to the left or right
    if( ( manpos_x < 0 ) || ( manpos_x + 60 > 480 ) )
    {
        //Move back
        manpos_x -= manv_x;
    }
    //Move the dot up or down
    manpos_y += manv_y;

    //If the dot went too far up or down
    if( ( manpos_y < 50 ) || ( manpos_y + 60 > 640 ) )
    {
        //Move back
        manpos_y -= manv_y;
    }
}



void man::render(SDL_Texture &tex, SDL_Renderer &ren){
    SDL_Rect Quad;
    Quad.x = manpos_x;
    Quad.y = manpos_y;
    Quad.w = 60;
    Quad.h = 60;
    SDL_RenderSetViewport(&ren, &Quad);
    SDL_RenderCopy(&ren, &tex, NULL, NULL);
}

int man::operator!()
{
    return manpos_x;
}
int man::operator&()
{
    return manpos_y;
}

void man::reset()
{
    manpos_x = 210;
    manpos_y = 490;
    manv_x = 0;
    manv_y = 0;
}
