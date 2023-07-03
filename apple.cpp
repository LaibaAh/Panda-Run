#include "apple.hpp"

using namespace std;

Apples::Apples(SDL_Rect mover) // constructor intializing the Src and Mover Rect coordinates of the Apple
{
    appleSrc = {351, 176, 35, 35};
    appleMover = mover; // moverRect for each apple will be different
}

void Apples::drawApple(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &appleSrc, &appleMover);
}
