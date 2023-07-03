#pragma once
#include <SDL.h>
#include <vector>
#include <iostream>
#include "enemy.hpp"

using namespace std;

class Ghost : public Enemy
{
public:
    bool down = true; // controls position of Ghost

    SDL_Rect ghostSrc;
    SDL_Rect ghostMover;

    // public:
    Ghost();
    void drawEnemy(SDL_Renderer *gRnderer, SDL_Texture *assets);
    void moveEnemy(); // this function will be overridden
};
