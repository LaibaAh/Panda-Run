#include <SDL.h>
using namespace std;

class Obstacles
{
public:
    SDL_Rect treeSrc;
    SDL_Rect treeMover;

    SDL_Rect logSrc;
    SDL_Rect logMover;

    SDL_Rect waterSrc;
    SDL_Rect waterMover;

//public:
    Obstacles();
    void drawTree(SDL_Renderer *gRenderer, SDL_Texture *assets);

    void drawLog(SDL_Renderer *gRenderer, SDL_Texture *assets);

    void drawWater(SDL_Renderer *gRenderer, SDL_Texture *assets);
};
