#include <SDL.h>
using namespace std;

class Apples
{
public:
    // declaring the Src and Mover Rect coordinates of Apple since they will be drawn on the screen
    SDL_Rect appleSrc;
    SDL_Rect appleMover;

    Apples(SDL_Rect mover);
    void drawApple(SDL_Renderer *gRenderer, SDL_Texture *assets); // This function draws the Apple onto the screen
};