#ifndef PIOTR_H
#define PIOTR_H

#include <SDL2/SDL.h>

#define PLAYER_RECT_WIDTH 100
#define PLAYER_RECT_HEIGHT 100

class Player
{
public:
    Player(int x, int y) : x_{x}, y_{y} {}

    bool draw_player(SDL_Renderer* renderer);
    
private:
    // Player coordinates
    int x_;
    int y_;

    // Player colors
    uint8_t colors_[4] = {0xFF, 0x0, 0x0, 0xFF};
};

#endif