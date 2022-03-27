#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

class man{
public:
    man();
    ~man(){};
    void operator*(SDL_Event &e);
    void operator~();
    void render(SDL_Texture &tex, SDL_Renderer &ren);
    int operator!();
    int operator&();
    bool sign;
    void reset();
private:
    int manpos_x,manpos_y;
    int manv_x,manv_y;

};
