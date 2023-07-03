#pragma once
#include "Panda.hpp"
#include "ghost.hpp"
#include "goblin.hpp"
#include <iostream>

Ghost g1;
Goblin g2;

Panda::Panda()
{
    pandaSrc = {631, 1, 28, 30};
    pandaMover = {225, 50, 50, 50};
}
void Panda::operator++(){
    ++apples; 
}

void Panda::moveSouth()
{
    if ((pandaMover.y + yJump < 300) && (pandaMover.x >= 80 && pandaMover.x < 130))
    {
        pandaMover.y += yJump;
    }
    else if ((pandaMover.y + yJump < 450) && (pandaMover.x >= 130 && pandaMover.x < 180))
    {
        pandaMover.y += yJump;
    }
    else if ((pandaMover.y + yJump < 475) && (pandaMover.x >= 180 && pandaMover.x < 220))
    {
        pandaMover.y += yJump;
    }
    else if ((pandaMover.y + yJump < 500) && (pandaMover.x >= 220 && pandaMover.x < 320))
    {
        pandaMover.y += yJump;
    }
    else if ((pandaMover.y + yJump < 550) && (pandaMover.x >= 315 && pandaMover.x < 350))
    {
        pandaMover.y += yJump;
    }
    else if ((pandaMover.y + yJump < 520) && (pandaMover.x >= 660 && pandaMover.x < 840))
    {
        pandaMover.y += yJump;
    }
    else if ((pandaMover.y + yJump < 500) && (pandaMover.x >= 840 && pandaMover.x < 890))
    {
        pandaMover.y += yJump;
    }
    else if ((pandaMover.y + yJump < 340) && (pandaMover.x >= 890 && pandaMover.x < 970))
    {
        pandaMover.y += yJump;
    }
    else if ((pandaMover.y + yJump < 520) && (pandaMover.x >= 350 && pandaMover.x < 660))
    {
        pandaMover.y += yJump;
    }
}
void Panda::moveNorth()
{
    if ((pandaMover.y - yJump > 40) && (pandaMover.x >= 220 && pandaMover.x < 680))
    {
        pandaMover.y -= yJump;
    }
    else if ((pandaMover.y - yJump > 40) && (pandaMover.x <= 220))
    {
        pandaMover.y -= yJump;
    }
    else if ((pandaMover.y - yJump > 50) && (pandaMover.x >= 680 && pandaMover.x < 900))
    {
        pandaMover.y -= yJump;
    }
    else if ((pandaMover.y - yJump > 80) && (pandaMover.x >= 900 && pandaMover.x < 970))
    {
        pandaMover.y -= yJump;
    }
}
void Panda::moveEast()
{
    if ((pandaMover.x + xJump <= 675) && (pandaMover.y == 50))
    {
        pandaMover.x += xJump;
    }
    else if ((pandaMover.x + xJump <= 880) && (pandaMover.y == 75))
    {
        pandaMover.x += xJump;
    }
    else if ((pandaMover.x + xJump <= 960) && (pandaMover.y > 75 && pandaMover.y <= 320))
    {
        pandaMover.x += xJump;
    }
    else if ((pandaMover.x + xJump <= 880) && (pandaMover.y > 320 && pandaMover.y <= 490))
    {
        pandaMover.x += xJump;
    }
    else if ((pandaMover.x + xJump <= 820) && (pandaMover.y > 490 && pandaMover.y <= 520))
    {
        pandaMover.x += xJump;
    }
}
void Panda::moveWest()
{
    if ((pandaMover.x - xJump >= 80) && (pandaMover.y >= 75 && pandaMover.y <= 300))
    {
        pandaMover.x -= xJump;
    }
    else if ((pandaMover.x - xJump >= 220) && (pandaMover.y == 50))
    {
        pandaMover.x -= xJump;
    }
    else if ((pandaMover.x - xJump >= 150) && (pandaMover.y >= 320 && pandaMover.y <= 460))
    {
        pandaMover.x -= xJump;
    }

    else if ((pandaMover.x - xJump >= 220) && (pandaMover.y >= 460 && pandaMover.y <= 480))
    {
        pandaMover.x -= xJump;
    }
    else if ((pandaMover.x - xJump >= 275) && (pandaMover.y >= 480 && pandaMover.y <= 500))
    {
        pandaMover.x -= xJump;
    }
}

// First rectangle is srcRect, second is moverRect
// these values are taken from the corresponding image in assets file
// use spritecow.com to find exact values of other asset images

void Panda::drawObjects(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &pandaSrc, &pandaMover);
}

void Panda::makeMove(string direction)
{

    if (direction == "East")
    {
        moveEast(); // Call this function only if warrior needs to be moved
    }
    else if (direction == "South")
    {
        moveSouth(); // Call this function only if panda needs to be moved
    }
    else if (direction == "North")
    {
        moveNorth();
    }
    else if (direction == "West")
    {
        moveWest();
    }
}

void Panda::moveWarrior(SDL_Renderer *gRenderer, SDL_Texture *assets, SDL_Keycode key)
{
    if (key == SDLK_UP)
    {
        makeMove("North");
        pandaSrc = {695, 66, 28, 29};
    }
    else if (key == SDLK_DOWN)
    {
        makeMove("South");
        pandaSrc = {664, 34, 27, 29};
    }
    else if (key == SDLK_RIGHT)
    {
        makeMove("East");

        pandaSrc = {666, 130, 21, 29};
    }
    else if (key == SDLK_LEFT)
    {
        makeMove("West");
        pandaSrc = {699, 131, 21, 29};
    }
    else
    {
        std::cout << "hello";
    }
    // update(gRenderer, assets);
}

bool Panda::collide()
{
    bool fell = false;
    if (pandaMover.x > 386 && pandaMover.x < 460 && pandaMover.y > 420 && pandaMover.y < 495)
    {
        fell = true;
        std::cout << "panda fell"<<endl;
    }
    else if (pandaMover.x > 462 && pandaMover.x < 526 && pandaMover.y > 450 && pandaMover.y < 500)
    {
        fell = true;
        std::cout << "panda fell"<<endl;
    }
    else if (pandaMover.x > 530 && pandaMover.x < 672 && pandaMover.y > 356 && pandaMover.y < 400)
    {
        fell = true;
        std::cout << "panda fell"<<endl;
    }
    else if (pandaMover.x > 595 && pandaMover.x < 680 && pandaMover.y > 404 && pandaMover.y < 452)
    {
        fell = true;
        std::cout << "panda fell"<<endl;
    }
    else if (pandaMover.x > 354 && pandaMover.x < 500 && pandaMover.y > 140 && pandaMover.y < 200)
    {
        fell = true;
        std::cout << "panda fell"<<endl;
    }
    return fell;

    // if ((pandaMover.x >= ghostMover.x && this->GetX() <= (sprite->GetX() + sprite->GetWidth())) ||
    //     ((this->GetX() + this->GetWidth()) >= sprite->GetX() && (this->GetX() + this->GetWidth()) <= (sprite->GetX() + sprite->GetWidth())))
    // {
    //     //Now we look at the y axis:
    //     if ((this->GetY() >= sprite->GetY() && this->GetY() <= (sprite->GetY() + sprite->GetHeight())) ||
    //         ((this->GetY() + this->GetHeight()) >= sprite->GetY() && (this->GetY() + this->GetHeight()) <= (sprite->GetY() + sprite->GetHeight())))
    //     {
    //         //The sprites appear to overlap.
    //         return true;
    //     }
    // }
    // return false;
    // SDL_bool collid = false;
    // collid = SDL_HasIntersection(SDL_Rect * pandaMover, SDL_Rect * g1.ghostMover);

    // if (collid == true)
    // {
    // std::cout << "collided";
    // }

    //     bool collid = false;
    //     if (((pandaMover.x == g1.moverRect.x) && (pandaMover.y == g1.moverRect.y)) || ((pandaMover.x == g2.moverRect.x) && (pandaMover.y == g2.moverRect.y)))
    //     collid = true;
    //     else
    //     collid = false;
    //     return collid;
}