#include "monster.h"


monster_yellow::monster_yellow()
{
    srand(time(NULL));
    int tt=rand()%300;
    monster_w=0;
    monster_h=0;
    monster_x=tt;
    monster_y=0;
}

monster_yellow::~monster_yellow()
{

}

void monster_yellow::operator^(int r)
{
        MONSTER.x = monster_x;
        MONSTER.y = monster_y;
        MONSTER.w = 35;
        MONSTER.h = 35;

        if(b==0){
            monster_x+=2;
            monster_y+=1;
            if(monster_x>=440) b=1;

        }
        if(b==1){
            monster_x-=2;
            monster_y+=1;
            if(monster_x<=10) b=0;

        }
        if(monster_y>=635) {monster_y=0; monster_x=r;}
}

void monster_yellow::show( SDL_Renderer& renderer, SDL_Texture& tex){
    SDL_RenderSetViewport(&renderer, &MONSTER);
    SDL_RenderCopy(&renderer, &tex, NULL, NULL);
}

void monster_yellow::operator~()
{
    monster_y=-100;
    MONSTER.y=-100;
}

SDL_Rect monster_yellow::operator!(){
    return MONSTER;
}
monster_blue::monster_blue()
{
    srand(time(NULL));
    int tt=rand()%300;
    monster_h=0;
    monster_w=0;
    monster_x=tt;
    monster_y=0;

}


void monster_blue::operator^(int r)
{

    MONSTER.x = monster_x;
    MONSTER.y = monster_y;
    MONSTER.w = 35;
    MONSTER.h = 35;


        if(b==1){
            monster_x+=3;
            monster_y+=1;
            if(monster_x>=440) b=0;
        }
        if(b==0){
            monster_x-=3;
            monster_y+=1;
            if(monster_x<=10) b=1;
        }

        if(monster_y>=635) {monster_y=0; monster_x=r;}


}
monster_red::monster_red(){
    srand(time(NULL));
    int tt=rand()%300;
    monster_w=0;
    monster_h=0;
    monster_y=tt;
    monster_x=0;
}

void monster_red::operator^(int r)
{
    MONSTER.x = monster_x;
    MONSTER.y = monster_y;
    MONSTER.w = 35;
    MONSTER.h = 35;

    if(b==0){
        monster_x+=1;
        monster_y+=3;
        if(monster_y>=600) b=1;
    }
    if(b==1){
        monster_x+=1;
        monster_y-=3;
        if(monster_y<=0) b=0;
    }
    if(monster_x>=475) {monster_y=r; monster_x=0;}
}

void monster_red::operator~()
{
    monster_x=-50;
    MONSTER.x=-50;
}
