#include "piotr.h"

#include <SDL2/SDL.h>
#include <iostream>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

bool init(SDL_Window* &window, SDL_Surface* &surface, SDL_Renderer* &renderer);

int main()
{
    Player player = Player(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;
    SDL_Renderer* renderer = nullptr;

    if(!init(window, surface, renderer))
    {
        std::cerr << "Failed to initialize - aborting..." << std::endl;
        return -1;
    }

    if(window == nullptr || surface == nullptr || renderer == nullptr)
    {
        std::cerr << "nullptrs" << std::endl;
        return -1;
    }

    while(1)
    {
        SDL_Event e;
        if(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                break;
            }
        }

        player.draw_player(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;

}

bool init(SDL_Window* &window, SDL_Surface* &surface, SDL_Renderer* &renderer)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Failed to initialize SDL" << std::endl;
        return false;
    }

    // Creation of window
    window = SDL_CreateWindow("Tester Piotr", SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr)
    {
        std::cerr << "Failed to create the window" << std::endl;
        return false;
    }

    surface = SDL_GetWindowSurface(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
        std::cerr << "Failed to create renderer" << std::endl;
        return false;
    }

    return true;
}