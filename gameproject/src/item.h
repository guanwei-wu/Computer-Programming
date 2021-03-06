#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

class item
{
public:
    //建構子和解構子
    item();
    ~item();
    //叫出道具
    void get_diamond(SDL_Texture*, SDL_Renderer*, int, int);
    void get_fireball(SDL_Texture*, SDL_Renderer*, int, int);
    void get_goldenheart(SDL_Texture*, SDL_Renderer*, int, int);
    void get_star(SDL_Texture*, SDL_Renderer*, int, int);
    void get_heart(SDL_Texture*, SDL_Renderer*, int, int);

    void disappear();

private:
    int score;
    SDL_Texture* item_texture;
    int item_w;
    int item_h;
};
