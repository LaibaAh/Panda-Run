#include "obstacles.hpp"

using namespace std;

Obstacles::Obstacles()
{
    treeSrc = {126, 10, 51, 54};
    treeMover = {100, 250, 50, 50};

    logSrc = {321, 115, 62, 38};
    logMover = {600, 200, 50, 50};

    waterSrc = {420, 11, 76, 74};
    waterMover = {350, 150, 200, 100};
}

void Obstacles::drawTree(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &treeSrc, &treeMover);
}

void Obstacles::drawLog(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &logSrc, &logMover);
}

void Obstacles::drawWater(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &waterSrc, &waterMover);
}