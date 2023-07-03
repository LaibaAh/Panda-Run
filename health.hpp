#include <SDL.h>

class Health
{
public:

    SDL_Rect healthSrc;
    SDL_Rect healthMover;
    int health; 
    // bool changescreen = false;

    // public:
    Health();
    void drawHealth(SDL_Renderer *gRenderer, SDL_Texture *assets);
    void changeHealth(SDL_Renderer *gRenderer, SDL_Texture *assets, bool collided);

};