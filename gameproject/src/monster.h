#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class monster_yellow
{
public:
    monster_yellow();
    ~monster_yellow();

    int b=0;

    virtual void operator^(int);//move

    void operator~();//disappear

    void show( SDL_Renderer&, SDL_Texture&);

    SDL_Rect operator!();
protected:
    int monster_x;
    int monster_y;
    SDL_Rect MONSTER;

private:
    int monster_w;
    int monster_h;


};

class monster_blue : public monster_yellow
{
    public:
        monster_blue();
        ~monster_blue(){};
        void operator^(int);


    private:
        int monster_w;
        int monster_h;

};

class monster_red : public monster_yellow
{
    public:
        monster_red();
        ~monster_red(){};
        void operator~();
        void operator^(int);

    private:
        int monster_w;
        int monster_h;
};
