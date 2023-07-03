#include <iostream>
#include <SDL.h>
#include <vector>
using namespace std;

class Panda
{
public:
    int apples = 0;
    const int xJump = 25, yJump = 25; // Speed of the Panda
    SDL_Rect pandaSrc, pandaMover;

    // Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 560;

    // bool variables that check if the Panda collides with the game objects
    bool iscollide = false;
    bool iscollide2 = false;
    bool iscollide3 = false;
    bool iscollide4 = false;
    bool iscollide5 = false;
    bool iscollide6 = false;
    bool iscollide7 = false;
    bool iscollide8 = false;

    Panda();
    void drawObjects(SDL_Renderer *gRnderer, SDL_Texture *assets); // drawing the Panda on the screen
    // mover functions
    void moveSouth();
    void moveNorth();
    void moveEast();
    void moveWest();
    void makeMove(string direction);
    void moveWarrior(SDL_Renderer *gRenderer, SDL_Texture *assets, SDL_Keycode key);
    bool collide(); // Determines whether or not the panda has fallen into the water
    void operator++();
};