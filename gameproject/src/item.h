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
    //�غc�l�M�Ѻc�l
    item();
    ~item();
    //�s�X�D��
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