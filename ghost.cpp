#include "ghost.hpp"
#include<iostream>
using namespace std;




Ghost::Ghost() //the constructor chooses from 6 random positions to assign to the ghost mover
{
    int ran = rand()%6;
    srcRect = {435, 107, 49, 42};
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
   // moverRect = {200, 350, 50, 50};
}



void Ghost::drawEnemy(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Ghost::moveEnemy()
{ // ghost only moves up and down

    if (moverRect.y >= 500)
    {
        down = false;
    }
    else if (moverRect.y <= 100)
    {
        down = true;
    }
    if (down)
    {
        moverRect.y += 5;
    }
    else if (!down)
    {
        moverRect.y -= 5;
    }
}