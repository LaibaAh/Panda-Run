#include "enemy.hpp"
#include <cstdlib>

Enemy::Enemy()
{
    // The Src and Mover Rect coordinates of each enemy in the game are different so these will be initialized by the child classes only.
    // cout<<"Enemy is created"<<endl;
}

void Enemy::drawEnemy(SDL_Renderer *gRenderer, SDL_Texture *assets) // drawing the enemy on screen
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Enemy::moveEnemy()
{
    // different implementation for each enemy (implemented in child classes)
}