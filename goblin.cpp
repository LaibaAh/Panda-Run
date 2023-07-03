#include <iostream>
#include "goblin.hpp"
#include <vector>


Goblin::Goblin()
{
 
    srcRect = {437, 173, 62, 65};
    int ran = rand()%6;
    if (ran == 0 ){
        moverRect = coordinates[0];
    }
    else if (ran == 1){
        moverRect = coordinates[1];
    }
    else if (ran == 2){
        moverRect = coordinates[2];
    }
    else if (ran == 3){
        moverRect = coordinates[3];
    }
    else if (ran == 4){
        moverRect = coordinates[4];
    }
    else if (ran == 5){
        moverRect = coordinates[5];
    }

    //moverRect = {500, 250, 50, 50};
}

void Goblin::drawEnemy(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Goblin::moveEnemy()
{ // goblin only moves left to right

    if (moverRect.x >= 900)
    {
        right_move = false;
    }
    else if (moverRect.x <= 200)
    {
        right_move = true;
    }
    if (right_move == true)
    {
        moverRect.x += 10;
    }
    else if (right_move == false)
    {
        moverRect.x -= 10;
    }
}