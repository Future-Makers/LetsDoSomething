#include "piotr.h"

bool Player::draw_player(SDL_Renderer* renderer)
{
    SDL_Rect player_point = {this->x_, this->y_, 
            PLAYER_RECT_WIDTH, PLAYER_RECT_HEIGHT};
    
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, this->colors_[0], this->colors_[1],
        this->colors_[2], this->colors_[3]);
    SDL_RenderFillRect(renderer, &player_point);
    SDL_RenderPresent(renderer);
}
