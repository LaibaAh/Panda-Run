#include <SDL.h>
#include <vector>
#include <iostream>
#pragma once
using namespace std;

class Enemy
{
public:
    // declaring the Src and Mover Rect coordinates of Enemy
    SDL_Rect srcRect, moverRect;
    SDL_Rect coordinates[6] = {{500, 250, 50, 50}, {386, 302, 50, 50}, {601, 535, 50, 50}, {934, 161, 50, 50}, {560, 64, 50, 50}, {87, 150, 50, 50}};

public:
    Enemy();
    void drawEnemy(SDL_Renderer *gRnderer, SDL_Texture *assets);
    virtual void moveEnemy() = 0; // purely virtual since it works differently for each child class
};
