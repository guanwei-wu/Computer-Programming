#include "item.h"

item::item()
{
	item_w = 40;
	item_h = 40;
}
item::~item()
{
    disappear();
}
void item::get_diamond(SDL_Texture* dia_texture, SDL_Renderer* item_ren, int xxx, int yyy)
{
    SDL_Rect diamond_rect;
    diamond_rect.x = xxx;
    diamond_rect.y = yyy;
    diamond_rect.w = item_w;
    diamond_rect.h = item_h;

    SDL_RenderSetViewport(item_ren, &diamond_rect);
    SDL_RenderCopy(item_ren, dia_texture, NULL, NULL);
}
void item::get_fireball(SDL_Texture* fir_texture, SDL_Renderer* item_ren, int xxx, int yyy)
{
    SDL_Rect fireball_rect;
    fireball_rect.x = xxx;
    fireball_rect.y = yyy;
    fireball_rect.w = item_w;
    fireball_rect.h = item_h;


    SDL_RenderSetViewport(item_ren, &fireball_rect);
    SDL_RenderCopy(item_ren, fir_texture, NULL, NULL);
}
void item::get_goldenheart(SDL_Texture* gol_texture, SDL_Renderer* item_ren, int xxx, int yyy)
{
    SDL_Rect goldenheart_rect;
    goldenheart_rect.x = xxx;
    goldenheart_rect.y = yyy;
    goldenheart_rect.w = item_w;
    goldenheart_rect.h = item_h;

    SDL_RenderSetViewport(item_ren, &goldenheart_rect);
    SDL_RenderCopy(item_ren, gol_texture, NULL, NULL);
}

void item::get_star(SDL_Texture* sta_texture, SDL_Renderer* item_ren, int xxx, int yyy)
{
    SDL_Rect star_rect;
    star_rect.x = xxx;
    star_rect.y = yyy;
    star_rect.w = item_w;
    star_rect.h = item_h;

    SDL_RenderSetViewport(item_ren, &star_rect);
    SDL_RenderCopy(item_ren, sta_texture, NULL, NULL);
}

void item::get_heart(SDL_Texture* hea_texture, SDL_Renderer* item_ren, int xxx, int yyy)
{
    SDL_Rect heart_rect;
    heart_rect.x = xxx;
    heart_rect.y = yyy;
    heart_rect.w = item_w;
    heart_rect.h = item_h;

    SDL_RenderSetViewport(item_ren, &heart_rect);
    SDL_RenderCopy(item_ren, hea_texture, NULL, NULL);
}

//道具消失
void item::disappear()
{
    if(item_texture != NULL)
	{
		SDL_DestroyTexture(item_texture);
		item_texture = NULL;
		item_w = 0;
		item_h = 0;
	}
}
