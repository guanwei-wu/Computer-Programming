#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

class attack{
public:
    bool end;
    bool start;
    attack();
    ~attack(){};
    void operator+(int);
    void operator*(SDL_Event &);
    void position(int,int);
    void appear(SDL_Renderer&,SDL_Texture&);
    const bool get_sign();
    void started();
    void restart();
    virtual int get_bux();
    virtual int get_buy();
protected:
    int bullet_x;
    int bullet_y;
    int movement;
    bool sign;
};
