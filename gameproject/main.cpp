#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include "man.h"
#include "monster.h"
#include "heart.h"
#include "goldenheart.h"
#include "diamond.h"
#include "fireball.h"
#include "star.h"
#include "attack.h"
#include "attack1.h"
#include "attack2.h"
#include "attack3.h"

using namespace std;

    int leftA, leftB = 0;
    int rightA, rightB = 0;
    int topA, topB = 0;
    int bottomA, bottomB = 0;

bool touch(man theman , SDL_Rect THING)
{
    //Calculate the sides of rect A
    leftA = !theman + 3;
    rightA = !theman + 60;
    topA = &theman + 3;
    bottomA = &theman + 60;

    //Calculate the sides of rect B
    leftB = THING.x;
    rightB = THING.x + 35;
    topB = THING.y;
    bottomB = THING.y + 35;

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

bool die(int x,int y,SDL_Rect monster){

    leftA = x;
    rightA = x + 30;
    topA = y;
    bottomA = y + 30;

    //Calculate the sides of rect B
    leftB = monster.x;
    rightB = monster.x + 35;
    topB = monster.y;
    bottomB = monster.y + 35;

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}


int main(int argc, char* argv[])
{

    SDL_Init(SDL_INIT_EVERYTHING);
    ///////////////////////////////////
    Mix_OpenAudio(128000, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Music * bgm = NULL;
    Mix_Music * top = NULL;
    Mix_Music * bye = NULL;

    bgm = Mix_LoadMUS( "mp3/music.mp3" );
    top = Mix_LoadMUS( "mp3/top.mp3" );
    bye = Mix_LoadMUS( "mp3/bye.mp3" );

    int _check = 0;

    TTF_Init();

    SDL_Window * window = NULL;
    window = SDL_CreateWindow("game", 400, 35, 480, 640, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    SDL_Renderer * renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface * surface = NULL;
    surface = IMG_Load("images/background.png");

    SDL_Texture * texture = NULL;
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Event event;


    SDL_Texture * heart_tex = NULL;
    SDL_Surface * heart_sur = IMG_Load("images/heart.png");
    heart_tex = SDL_CreateTextureFromSurface(renderer, heart_sur);
    SDL_FreeSurface(heart_sur);

    SDL_Texture * noheart_tex = NULL;
    SDL_Surface * noheart_sur = IMG_Load("images/no heart.png");
    noheart_tex = SDL_CreateTextureFromSurface(renderer, noheart_sur);
    SDL_FreeSurface(noheart_sur);

    SDL_Texture* astrotex = NULL;
    SDL_Surface* astrosur = IMG_Load("images/astro.png");
    astrotex = SDL_CreateTextureFromSurface( renderer, astrosur );
    SDL_FreeSurface(astrosur);

    SDL_Texture* yellowtex = NULL;
    SDL_Surface* yellowsur = IMG_Load("images/yellow.png");
    yellowtex = SDL_CreateTextureFromSurface( renderer, yellowsur );
    SDL_FreeSurface(yellowsur);

    SDL_Texture* redtex = NULL;
    SDL_Surface* redsur = IMG_Load("images/red.png");
    redtex = SDL_CreateTextureFromSurface( renderer, redsur );
    SDL_FreeSurface(redsur);

    SDL_Texture* bluetex = NULL;
    SDL_Surface* bluesur = IMG_Load("images/blue.png");
    bluetex = SDL_CreateTextureFromSurface( renderer, bluesur );
    SDL_FreeSurface(bluesur);

    SDL_Surface* diasur = IMG_Load("images/diamond.png");
    SDL_Texture* dia_texture = SDL_CreateTextureFromSurface(renderer, diasur);
    SDL_FreeSurface(diasur);

    SDL_Surface* firsur = IMG_Load("images/fire ball.png");
    SDL_Texture* fir_texture = SDL_CreateTextureFromSurface(renderer, firsur);
    SDL_FreeSurface(firsur);

    SDL_Surface* golsur = IMG_Load("images/golden heart.png");
    SDL_Texture* gol_texture = SDL_CreateTextureFromSurface(renderer, golsur);
    SDL_FreeSurface(golsur);

    SDL_Surface* stasur = IMG_Load("images/star.png");
    SDL_Texture* sta_texture = SDL_CreateTextureFromSurface(renderer, stasur);
    SDL_FreeSurface(stasur);

    SDL_Surface* heasur = IMG_Load("images/heart.png");
    SDL_Texture* hea_texture = SDL_CreateTextureFromSurface(renderer, heasur);
    SDL_FreeSurface(heasur);

    SDL_Rect game_word_area;
    game_word_area.x = 63;
    game_word_area.y = 203;
    game_word_area.w = 360;
    game_word_area.h = 160;

    SDL_Rect game_word_area_sd;
    game_word_area_sd.x = 60;
    game_word_area_sd.y = 200;
    game_word_area_sd.w = 360;
    game_word_area_sd.h = 160;

    SDL_Rect game_word_area_a;
    game_word_area_a.x = 120;
    game_word_area_a.y = 440;
    game_word_area_a.w = 240;
    game_word_area_a.h = 40;

    SDL_Rect game_word_area_b;
    game_word_area_b.x = 120;
    game_word_area_b.y = 480;
    game_word_area_b.w = 240;
    game_word_area_b.h = 40;

    TTF_Font *welcome = NULL;
    welcome = TTF_OpenFont("fonts/GenJyuuGothic-Regular.ttf", 200);
    TTF_SetFontStyle(welcome, TTF_STYLE_BOLD | TTF_STYLE_ITALIC);
    SDL_Color color1 = {209, 95, 238};
    SDL_Color color1_sd = {139, 102, 139};
    SDL_Color color1_ab = {180, 205, 205};

    SDL_Surface * ganasur = NULL;
    SDL_Texture * ganatex = NULL;
    SDL_Surface * ganasur_sd = NULL;
    SDL_Texture * ganatex_sd = NULL;

    SDL_Surface * ganasur_a = NULL;
    SDL_Texture * ganatex_a = NULL;
    SDL_Surface * ganasur_b = NULL;
    SDL_Texture * ganatex_b = NULL;
    SDL_Surface * ganasur_c = NULL;
    SDL_Texture * ganatex_c = NULL;

    stringstream game_name;
    game_name.str( "" );
    game_name << "Riki's Adventure";

    stringstream gna;
    gna.str( "" );
    gna << "press 'S' to start";

    stringstream gnb;
    gnb.str( "" );
    gnb << "press 'H' for help";

    stringstream gnc;
    gnc.str( "" );
    gnc << "press 'R' to restart";

    ganasur = TTF_RenderText_Solid(welcome, game_name.str().c_str(), color1);
    ganatex = SDL_CreateTextureFromSurface(renderer, ganasur);
    ganasur_sd = TTF_RenderText_Solid(welcome, game_name.str().c_str(), color1_sd);
    ganatex_sd = SDL_CreateTextureFromSurface(renderer, ganasur_sd);

    ganasur_a = TTF_RenderText_Solid(welcome, gna.str().c_str(), color1_ab);
    ganatex_a = SDL_CreateTextureFromSurface(renderer, ganasur_a);
    ganasur_b = TTF_RenderText_Solid(welcome, gnb.str().c_str(), color1_ab);
    ganatex_b = SDL_CreateTextureFromSurface(renderer, ganasur_b);
    ganasur_c = TTF_RenderText_Solid(welcome, gnc.str().c_str(), color1_ab);
    ganatex_c = SDL_CreateTextureFromSurface(renderer, ganasur_c);


    SDL_FreeSurface(ganasur);
    SDL_FreeSurface(ganasur_sd);
    SDL_FreeSurface(ganasur_a);
    SDL_FreeSurface(ganasur_b);
    SDL_FreeSurface(ganasur_c);

    SDL_Surface *attsur = IMG_Load("images/attacku.png");
    SDL_Texture *att_texture = SDL_CreateTextureFromSurface(renderer, attsur);
    SDL_FreeSurface(attsur);

    SDL_Surface *attsur_1 = IMG_Load("images/attackd.png");
    SDL_Texture *att_texture_1 = SDL_CreateTextureFromSurface(renderer, attsur_1);
    SDL_FreeSurface(attsur_1);

    SDL_Surface *attsur_2 = IMG_Load("images/attackr.png");
    SDL_Texture *att_texture_2 = SDL_CreateTextureFromSurface(renderer, attsur_2);
    SDL_FreeSurface(attsur_2);

    SDL_Surface *attsur_3 = IMG_Load("images/attackl.png");
    SDL_Texture *att_texture_3 = SDL_CreateTextureFromSurface(renderer, attsur_3);
    SDL_FreeSurface(attsur_3);

    SDL_Surface* note1sur = IMG_Load("images/note1.png");
    SDL_Texture* note1tex = SDL_CreateTextureFromSurface(renderer, note1sur);
    SDL_FreeSurface(note1sur);

    SDL_Surface* note2sur = IMG_Load("images/note2.png");
    SDL_Texture* note2tex = SDL_CreateTextureFromSurface(renderer, note2sur);
    SDL_FreeSurface(note2sur);

    SDL_Rect game_hint;
    game_hint.x = 0;
    game_hint.y = 0;
    game_hint.w = 480;
    game_hint.h = 640;


    SDL_Rect gamingscore;
    gamingscore.x = 300;
    gamingscore.y = 10;
    gamingscore.w = 160;
    gamingscore.h = 40;



    SDL_Color color2 = {30, 144, 255};
    stringstream recoscore;

    SDL_Rect fini_area;
        fini_area.x = 40;
        fini_area.y = 200;
        fini_area.w = 380;
        fini_area.h = 120;

    SDL_Texture * finitex = NULL;
    SDL_Color color3 = {100, 149, 237};
    stringstream fini_score;

        SDL_Rect roll;
        roll.x = 0;
        roll.y = 0;
        roll.w = surface->w;
        roll.h = surface->h - roll.y;

        SDL_Rect sq;
        sq.x = 0;
        sq.y = 0;
        sq.w = surface->w;
        sq.h = surface->h - roll.y;

        SDL_Rect roll2;
        roll2.x = 0;
        roll2.y = 0;
        roll2.w = surface->w;
        roll2.h = roll.y;

        SDL_Rect sq2;
        sq2.x = 0;
        sq2.y = surface->h - roll.y;
        sq2.w = surface->w;
        sq2.h = roll.y;

    int life = 3;
    int score = 0;
    bool shoot = 0;
    bool killall = 0;

    man tommy;
    attack bullet;
    attack_1 bullet_1;
    attack_2 bullet_2;
    attack_3 bullet_3;
    /////道具
    diamond theitem0;
    fire_ball theitem1;
    golden_heart theitem2;
    star theitem3;
    heart theitem4;
    /////道具

    /////道具
    int appeartime = 0;
    int xxx = 0;
    int yyy = 0;
    int no = 0;
    /////道具

    Mix_PlayMusic(top, -1);

    while(_check == 0)
    {
        roll.y+=1;
        if(roll.y > surface->h)
        {
            roll.y = 0;
        }

        roll.h = surface->h - roll.y;
        sq.h = surface->h - roll.y;
        roll2.h = roll.y;
        sq2.y = surface->h - roll.y;
        sq2.h = roll.y;

        SDL_RenderSetViewport(renderer, &roll);
        SDL_RenderCopy(renderer, texture, &sq, NULL);
        SDL_RenderSetViewport(renderer, &roll2);
        SDL_RenderCopy(renderer, texture, &sq2, NULL);

        SDL_RenderSetViewport(renderer, &game_word_area_sd);
        SDL_RenderCopy(renderer, ganatex_sd, NULL, NULL);
        SDL_RenderSetViewport(renderer, &game_word_area);
        SDL_RenderCopy(renderer, ganatex, NULL, NULL);

        SDL_RenderSetViewport(renderer, &game_word_area_a);
        SDL_RenderCopy(renderer, ganatex_a, NULL, NULL);
        SDL_RenderSetViewport(renderer, &game_word_area_b);
        SDL_RenderCopy(renderer, ganatex_b, NULL, NULL);


        SDL_RenderPresent(renderer);
        SDL_PollEvent(&event);

        if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_h)
        {
            roll.y = 0;
            SDL_DestroyTexture(ganatex);
            TTF_CloseFont(welcome);
            welcome = NULL;
            _check = 1;
            goto help;
        }

        if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s)
        {
            roll.y = 0;
            SDL_DestroyTexture(ganatex);
            TTF_CloseFont(welcome);
            welcome = NULL;
            _check = 3;
            Mix_HaltMusic();
            Mix_FreeMusic(top);
            goto game;
        }
        if(event.type == SDL_QUIT)
        {
            break;
        }

        SDL_Delay(4);
    }
help:
    while(_check == 1)
    {
        SDL_RenderSetViewport(renderer, &game_hint);
        SDL_RenderCopy(renderer, note1tex, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_PollEvent(&event);

        if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_h)
        {
            roll.y = 0;
            _check = 2;
            goto help;
        }
        if(event.type == SDL_QUIT)
        {
            break;
        }
    }

    while(_check == 2)
    {
        SDL_RenderSetViewport(renderer, &game_hint);
        SDL_RenderCopy(renderer, note2tex, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_PollEvent(&event);

        if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s)
        {
            roll.y = 0;
            _check = 3;
            Mix_HaltMusic();
            goto game;
        }
        if(event.type == SDL_QUIT)
        {
            break;
        }
    }

game:

    Mix_PlayMusic(bgm, -1);

    time_t ti = time(0);
    srand(time(0));

    monster_yellow monster1;
    monster_red monster2;
    monster_blue monster3;
    while(_check == 3)
    {
        SDL_RenderClear(renderer);
        if(event.type == SDL_QUIT)
        {
            break;
        }
        else
        {
            roll.y+=1;
        if(roll.y > surface->h)
        {
            roll.y = 0;
        }

        roll.h = surface->h - roll.y;
        sq.h = surface->h - roll.y;
        roll2.h = roll.y;
        sq2.y = surface->h - roll.y;
        sq2.h = roll.y;



            SDL_RenderSetViewport(renderer, &roll);
            SDL_RenderCopy(renderer, texture, &sq, NULL);
            SDL_RenderSetViewport(renderer, &roll2);
            SDL_RenderCopy(renderer, texture, &sq2, NULL);

            while(SDL_PollEvent(&event)!=0){
                tommy*event;
                bullet*event;
                theitem3*event;
            }
            ~tommy;

            SDL_PollEvent(&event);/////////////////////

            if(bullet.get_sign() && bullet.start && bullet_1.start && bullet_2.start && bullet_3.start && shoot == 1){
                bullet.position(!tommy,&tommy);
                bullet_1.position(!tommy,&tommy);
                bullet_2.position(!tommy,&tommy);
                bullet_3.position(!tommy,&tommy);
                bullet.appear(*renderer,*att_texture);
                bullet.started();
                bullet_1.appear(*renderer,*att_texture_1);
                bullet_1.started();
                bullet_2.appear(*renderer,*att_texture_2);
                bullet_2.started();
                bullet_3.appear(*renderer,*att_texture_3);
                bullet_3.started();
                shoot = 0;
            }
            if(!bullet.start){
                bullet+4;
                bullet.appear(*renderer,*att_texture);

            }
            if(!bullet_1.start){
                bullet_1+4;
                bullet_1.appear(*renderer,*att_texture_1);
            }
            if(!bullet_2.start){
                bullet_2+4;
                bullet_2.appear(*renderer,*att_texture_2);
            }
            if(!bullet_3.start){
                bullet_3+4;
                bullet_3.appear(*renderer,*att_texture_3);
            }


            if(bullet.end == 1 && bullet_1.end == 1 && bullet_2.end == 1 && bullet_3.end == 1){
                bullet.restart();
                bullet_1.restart();
                bullet_2.restart();
                bullet_3.restart();
            }
            if(killall && theitem3.sign){
                ~monster1;
                ~monster2;
                ~monster3;
                killall=0;
            }

            SDL_Texture * recotex = NULL;
            TTF_Font * reco = NULL;
            SDL_Surface * recosur = NULL;
            reco = TTF_OpenFont("fonts/GenJyuuGothic-Regular.ttf", 100);
            TTF_SetFontStyle(reco, TTF_STYLE_BOLD|TTF_STYLE_ITALIC);
            recoscore.str( "" );
            recoscore << "SCORE : " << score;
            recosur = TTF_RenderText_Solid(reco, recoscore.str().c_str(), color2);
            recotex = SDL_CreateTextureFromSurface(renderer, recosur);
            SDL_FreeSurface(recosur);
            SDL_RenderSetViewport(renderer, &gamingscore);
            SDL_RenderCopy(renderer, recotex, NULL, NULL);
            SDL_DestroyTexture(recotex);

            appeartime++;

            SDL_Rect heart1_zone;
            heart1_zone.x = 15;
            heart1_zone.y = 15;
            heart1_zone.w = 30;
            heart1_zone.h = 30;

            SDL_Rect heart2_zone;
            heart2_zone.x = 45;
            heart2_zone.y = 15;
            heart2_zone.w = 30;
            heart2_zone.h = 30;

            SDL_Rect heart3_zone;
            heart3_zone.x = 75;
            heart3_zone.y = 15;
            heart3_zone.w = 30;
            heart3_zone.h = 30;

            SDL_Rect fire_zone;
            fire_zone.x = 120;
            fire_zone.y = 15;
            fire_zone.w = 30;
            fire_zone.h = 30;

            SDL_Rect star_zone;
            star_zone.x = 150;
            star_zone.y = 15;
            star_zone.w = 30;
            star_zone.h = 30;


            if(life<0)
            {
                life = 0;
            }
            if(life>3)
            {
                life = 3;
            }
            if(life==0)
            {
                SDL_RenderSetViewport(renderer, &heart1_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart2_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart3_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
                _check = 4;
                Mix_HaltMusic();
                goto scorepart;
            }

            if(life==1)
            {
                SDL_RenderSetViewport(renderer, &heart1_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart2_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart3_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
            }


            if(life==2)
            {
                SDL_RenderSetViewport(renderer, &heart1_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart2_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart3_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
            }

            if(life==3)
            {
                SDL_RenderSetViewport(renderer, &heart1_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart2_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart3_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
            }

            if(shoot)
            {
                SDL_RenderSetViewport(renderer, &fire_zone);
                SDL_RenderCopy(renderer, fir_texture, NULL, NULL);
            }

            if(killall)
            {
                SDL_RenderSetViewport(renderer, &star_zone);
                SDL_RenderCopy(renderer, sta_texture, NULL, NULL);
            }


            if(appeartime == 500)
            {
                xxx = rand()%420 + 10;
                yyy = rand()%540 + 50;
                no = rand()%10;
            }

            if(appeartime > 500 && appeartime < 1500)
            {
                switch(no)
                {
                    case 0 : {theitem0.get(dia_texture, renderer, xxx, yyy); break;}
                    case 1 : {theitem1.get(fir_texture, renderer, xxx, yyy); break;}
                    case 2 : {theitem2.get(gol_texture, renderer, xxx, yyy); break;}
                    case 3 : {theitem3.get(sta_texture, renderer, xxx, yyy); break;}
                    case 4 : {theitem4.get(hea_texture, renderer, xxx, yyy); break;}
                    case 5 : {theitem1.get(fir_texture, renderer, xxx, yyy); break;}
                    case 6 : {theitem1.get(fir_texture, renderer, xxx, yyy); break;}
                    case 7 : {theitem1.get(fir_texture, renderer, xxx, yyy); break;}
                    case 8 : {theitem2.get(gol_texture, renderer, xxx, yyy); break;}
                    case 9 : {theitem1.get(fir_texture, renderer, xxx, yyy); break;}
                }
            }

            if(appeartime == 1500)
            {
                xxx = -100;
                yyy = -100;
                appeartime = 0;
            }


            SDL_Rect Item;
            Item.x = xxx;
            Item.y = yyy;
            Item.w = 30;
            Item.h = 30;


            if(touch(tommy, Item))
            {
                appeartime = 0;
                xxx = 0;
                yyy = 0;

                if(no == 0)
                {
                    theitem0*score;
                }
                if(no == 1 || no == 5 || no == 6 || no == 7 || no == 9)
                {
                    theitem1*score;
                    theitem1.work(shoot);
                }
                if(no == 2 || no == 8)
                {
                    theitem2+life;
                    theitem2*score;
                }
                if(no == 3)
                {
                    theitem3*score;
                    theitem3.work(killall);
                }
                if(no == 4)
                {
                    theitem4+life;
                    theitem4*score;
                }
            }
            tommy.render(*astrotex, *renderer);

            int r=rand()%300;

            monster1^r;
            monster1.show(*renderer, *yellowtex);
            if(time(0)-ti>20){
                monster3^r;
                monster3.show(*renderer, *bluetex);
                if(time(0)-ti>60){
                        monster2^r;
                        monster2.show(*renderer, *redtex);
                }
            }
            ////////////////////////////////////////////////////////////////////////////

    if(die(bullet.get_bux(),bullet.get_buy(),!monster1) && bullet.start == 0){
        ~monster1;
    }
    if(die(bullet_1.get_bux(),bullet_1.get_buy(),!monster1) && bullet_1.start == 0){
        ~monster1;
    }
    if(die(bullet_2.get_bux(),bullet_2.get_buy(),!monster1) && bullet_2.start == 0){
        ~monster1;
    }
    if(die(bullet_3.get_bux(),bullet_3.get_buy(),!monster1) && bullet_3.start == 0){
        ~monster1;
    }
    if(die(bullet.get_bux(),bullet.get_buy(),!monster2) && bullet.start == 0){
        ~monster2;
    }
    if(die(bullet_1.get_bux(),bullet_1.get_buy(),!monster2) && bullet_1.start == 0){
        ~monster2;
    }
    if(die(bullet_2.get_bux(),bullet_2.get_buy(),!monster2) && bullet_2.start == 0){
        ~monster2;
    }
    if(die(bullet_3.get_bux(),bullet_3.get_buy(),!monster2) && bullet_3.start == 0){
        ~monster2;
    }
    if(die(bullet.get_bux(),bullet.get_buy(),!monster3) && bullet.start == 0){
        ~monster3;
    }
    if(die(bullet_1.get_bux(),bullet_1.get_buy(),!monster3) && bullet_1.start == 0){
        ~monster3;
    }
    if(die(bullet_2.get_bux(),bullet_2.get_buy(),!monster3) && bullet_2.start == 0){
        ~monster3;
    }
    if(die(bullet_3.get_bux(),bullet_3.get_buy(),!monster3) && bullet_3.start == 0){
        ~monster3;
    }

    if(touch(tommy,!monster1)) {life--; ~monster1;}
    if(touch(tommy,!monster2)) {life--; ~monster2;}
    if(touch(tommy,!monster3)) {life--; ~monster3;}

            SDL_RenderPresent(renderer);
            TTF_CloseFont(reco);
            reco = NULL;
        }

    SDL_Delay(4);
}

scorepart:

        Mix_PlayMusic(bye, 0);

        TTF_Font * fini = NULL;
        SDL_Surface * finisur = NULL;
        fini = TTF_OpenFont("fonts/GenJyuuGothic-Regular.ttf", 200);
        TTF_SetFontStyle(fini, TTF_STYLE_BOLD|TTF_STYLE_ITALIC);
        fini_score.str( "" );
        fini_score << "YOUR SCORE : "<<score;
        finisur = TTF_RenderText_Solid(fini, fini_score.str().c_str(), color3);
        finitex = SDL_CreateTextureFromSurface(renderer, finisur);
        SDL_FreeSurface(finisur);

    while(_check == 4)
    {
        roll.y+=1;
        if(roll.y > surface->h)
        {
            roll.y = 0;
        }

        roll.h = surface->h - roll.y;
        sq.h = surface->h - roll.y;
        roll2.h = roll.y;
        sq2.y = surface->h - roll.y;
        sq2.h = roll.y;

        SDL_RenderSetViewport(renderer, &roll);
        SDL_RenderCopy(renderer, texture, &sq, NULL);
        SDL_RenderSetViewport(renderer, &roll2);
        SDL_RenderCopy(renderer, texture, &sq2, NULL);

        SDL_RenderSetViewport(renderer, &fini_area);
        SDL_RenderCopy(renderer, finitex, NULL, NULL);

        SDL_RenderSetViewport(renderer, &game_word_area_a);
        SDL_RenderCopy(renderer, ganatex_c, NULL, NULL);

        SDL_RenderPresent(renderer);
        SDL_PollEvent(&event);

        if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r)
        {
            _check = 3;
            shoot = 0;
            killall = 0;
            roll.y = 0;
            appeartime = 0;
            score = 0;
            tommy.reset();
            ~monster1;
            ~monster2;
            ~monster3;
            life = 3;
            goto game;
        }
        if(event.type == SDL_QUIT)
        {
            break;
        }
        TTF_CloseFont(fini);
        fini = NULL;

        SDL_Delay(4);
    }

    Mix_FreeMusic(bye);
    Mix_FreeMusic(bgm);

    SDL_DestroyTexture(note1tex);
    SDL_DestroyTexture(note2tex);
    SDL_DestroyTexture(att_texture);
    SDL_DestroyTexture(att_texture_1);
    SDL_DestroyTexture(att_texture_2);
    SDL_DestroyTexture(att_texture_3);
    SDL_DestroyTexture(hea_texture);
    SDL_DestroyTexture(sta_texture);
    SDL_DestroyTexture(gol_texture);
    SDL_DestroyTexture(fir_texture);
    SDL_DestroyTexture(dia_texture);
    SDL_DestroyTexture(bluetex);
    SDL_DestroyTexture(redtex);
    SDL_DestroyTexture(yellowtex);
    SDL_DestroyTexture(astrotex);
    SDL_DestroyTexture(noheart_tex);
    SDL_DestroyTexture(heart_tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}

