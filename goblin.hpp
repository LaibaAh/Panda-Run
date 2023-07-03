#include <SDL.h>
#include"enemy.hpp"
#pragma once

class Goblin: public Enemy
{
public:
    bool right_move = true;
   


// public:
    Goblin();
    void drawEnemy(SDL_Renderer *gRnderer, SDL_Texture *assets);
    
    void moveEnemy();
};
