#include "fireball.h"

fire_ball::fire_ball()
     {
      item_w = 35;
      item_h = 35;
     }

     void fire_ball::get(SDL_Texture* dia_texture, SDL_Renderer* item_ren, int xxx, int yyy)
     {
         SDL_Rect diamond_rect;
         diamond_rect.x = xxx;
         diamond_rect.y = yyy;
         diamond_rect.w = item_w;
         diamond_rect.h = item_h;

         SDL_RenderSetViewport(item_ren, &diamond_rect);
         SDL_RenderCopy(item_ren, dia_texture, NULL, NULL);
     }

     void fire_ball::operator*(int& score){
         score+=150;
     }

    void fire_ball::work(bool& shoot){
        shoot=1;
    }

