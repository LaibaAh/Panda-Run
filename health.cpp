#include "health.hpp"
#include "Panda.hpp"
#include <iostream>

Panda p1;
Health::Health()
{
    healthSrc = {7517, 0, 315, 75};
    healthMover = {750, 5, 180, 35};
}



void Health::drawHealth(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &healthSrc, &healthMover);
}

void Health::changeHealth(SDL_Renderer *gRenderer, SDL_Texture *assets, bool collided)
{
    if ((collided == true) && (healthSrc.x == 7517 && healthSrc.y == 0))
	{
		health = 0;
		healthSrc = {7523, 95, 314, 75};
	}

    else if ((collided == true) && (healthSrc.x == 7523 && healthSrc.y == 95))
	{
		health = 1;
		healthSrc = {7523, 187, 315, 75};
	}

    else if ((collided == true) && (healthSrc.x == 7523 && healthSrc.y == 187))
	{
		health = 2;
		healthSrc = {7523, 282, 314, 74};
	}

    else if ((collided == true) && (healthSrc.x == 7523 && healthSrc.y == 282))
	{
		health = 3;
		healthSrc = {7526, 372, 315, 74};
		// changescreen = true; 
		}

}