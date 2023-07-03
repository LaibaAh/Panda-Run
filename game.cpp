#include "game.hpp"
#include "Panda.hpp"
#include "ghost.hpp"
#include "goblin.hpp"
#include "obstacles.hpp"
#include "apple.hpp"
#include "health.hpp"

#include <iostream>
Mix_Music *bgMusic = NULL;

bool Game::init()
{
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("HU Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	// Loading success flag
	bool success = true;

	assets = loadTexture("spritesheet (6).png");
	gTexture = loadTexture("pandarun.PNG");
	if (assets == NULL || gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}

	bgMusic = Mix_LoadMUS("forest.wav");

	if (bgMusic == NULL)
	{
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	// Free loaded images
	SDL_DestroyTexture(assets);
	assets = NULL;
	SDL_DestroyTexture(gTexture);

	// Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic(bgMusic);
	bgMusic = NULL;
	// Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void Game::select_page(int xMouse, int yMouse)
{

	if (xMouse > 36 && xMouse < 208 && yMouse > 426 && yMouse < 504 && current_screen == 0)
	{
		current_screen = 1;
		gTexture = loadTexture("playscreen.png");
	}
	else if (xMouse > 752 && xMouse < 914 && yMouse > 466 && yMouse < 520 && current_screen == 1)
	{
		current_screen = 2;
		gTexture = loadTexture("pptsample.png");
	}
	else if (xMouse > 276 && xMouse < 750 && yMouse > 426 && yMouse < 504 && current_screen == 0)
	{
		current_screen = 3;
		gTexture = loadTexture("instructions.png");
		;
	}
	else if (xMouse > 0 && xMouse < 40 && yMouse > 0 && yMouse < 40 && current_screen == 2)
	{
		current_screen = 0;
		gTexture = loadTexture("pandarun.png");
	}
	else if (xMouse > 672 && xMouse < 810 && yMouse > 508 && yMouse < 570 && current_screen == 3)
	{
		current_screen = 0;
		gTexture = loadTexture("pandarun.png");
	}
	else if (xMouse > 40 && xMouse < 160 && yMouse > 504 && yMouse < 550 && current_screen == 4)
	{
		current_screen = 0;
		gTexture = loadTexture("pandarun.png");
	}
	else if (xMouse > 810 && xMouse < 930 && yMouse > 506 && yMouse < 550 && current_screen == 4)
	{
		close();
	}
	else if (xMouse > 805 && xMouse < 972 && yMouse > 430 && yMouse < 510 && current_screen == 0)
	{
		close();
	}
	else if (xMouse > 750 && xMouse < 868 && yMouse > 462 && yMouse < 498 && current_screen == 5)
	{
		close();
	}
	else if (xMouse > 810 && xMouse < 930 && yMouse > 506 && yMouse < 550 && current_screen == 6)
	{
		close();
	}
}

void Game::run()
{
	// creating objects of the characters included into the game
	bool quit = false;
	SDL_Event e;
	Panda panda1;
	Ghost ghost;
	Ghost ghost1;
	Goblin goblin;
	Obstacles obstacles;
	Health h;
	vector<Apples *> App; // dynamic vector

	// dynamically creating and appending apples (defined at 7 specific coordinates) to the array of apples intialized above.
	App.push_back(new Apples({386, 302, 35, 35}));
	App.push_back(new Apples({600, 500, 35, 35}));
	App.push_back(new Apples({198, 360, 35, 35}));
	App.push_back(new Apples({864, 304, 35, 35}));
	App.push_back(new Apples({579, 59, 35, 35}));
	App.push_back(new Apples({842, 403, 35, 35}));
	App.push_back(new Apples({265, 446, 35, 35}));

	int eat_apples = 0; // variable to keep track of the number of apples the Panda eats

	while (!quit)
	{
		// Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				std::cout << xMouse << " " << yMouse << " ";
				select_page(xMouse, yMouse); // adjusting the game screens based on where the mouse is clicked

				if (current_screen == 2) // The second screen is the primary game screen, where all of the game action takes place
				{
					panda1.drawObjects(gRenderer, assets); // drawing Panda onto the screen
				}
			}

			else if (e.type == SDL_KEYDOWN) // condition to check if the keyboard buttons have been pressed
			{
				if (current_screen == 2)
				{
					panda1.moveWarrior(gRenderer, assets, e.key.keysym.sym); // The position of the Panda on the screen will change depending on which button is pressed.
				}
			}

			// This will play the background music of the game
			if (Mix_PlayingMusic() == 0)
			{
				// Play the music
				Mix_PlayMusic(bgMusic, 2);
			}
		}

		SDL_RenderClear(gRenderer);						 // removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL); // Draws background to renderer
		//********draw the objects here*******

		bool collid = false; // When Panda collides with any of the game's obstacles or enemies, this variable is set to true.

		if (current_screen == 2)
		{
			// drawing game objects other than the Panda on the screen
			obstacles.drawTree(gRenderer, assets);
			obstacles.drawLog(gRenderer, assets);
			obstacles.drawWater(gRenderer, assets);
			goblin.drawEnemy(gRenderer, assets);
			h.drawHealth(gRenderer, assets);
			ghost.drawEnemy(gRenderer, assets);
			panda1.drawObjects(gRenderer, assets);
			ghost1.drawEnemy(gRenderer, assets);

			for (int i = 0; i < 7; i++)
			{
				App[i]->drawApple(gRenderer, assets);
			}

			ghost1.moveEnemy(); // changing position of the first ghost
			ghost.moveEnemy();	// changing position of the second ghost
			goblin.moveEnemy(); // changing position of the goblin

			// pointers pointing to the screen coordinates of the game characters
			SDL_Rect *Moverptr = &panda1.pandaMover;
			SDL_Rect *Ghostptr = &ghost.moverRect;
			SDL_Rect *Ghostptr1 = &ghost1.moverRect;
			SDL_Rect *Goblinptr = &goblin.moverRect;

			SDL_bool collision;
			SDL_bool collision2;
			SDL_bool collision3;
			bool col_fall = panda1.collide();

			int coll_count = 0;

			// The following lines of code check to see if the Panda collides with the first ghost and update its health status accordingly.
			// If this is not the case, the collision variable is set to false.
			collision = SDL_HasIntersection(Moverptr, Ghostptr);
			if (collision == SDL_TRUE && panda1.iscollide == false)
			{
				collid = true;
				panda1.iscollide = true;
				std::cout << "collisoon detected" << endl;
				h.changeHealth(gRenderer, assets, collid);
			}
			else if (collision == SDL_FALSE && panda1.iscollide == true)
			{
				panda1.iscollide = false;
			}

			// The following lines of code check to see if the Panda collides with the second ghost and update its health status accordingly.
			// If this is not the case, the collision variable is set to false.
			collision2 = SDL_HasIntersection(Moverptr, Ghostptr1);
			if (collision2 == SDL_TRUE && panda1.iscollide2 == false)
			{
				collid = true;
				panda1.iscollide2 = true;
				std::cout << "collision detected" << endl;
				h.changeHealth(gRenderer, assets, collid);
			}
			else if (collision2 == SDL_FALSE && panda1.iscollide2 == true)
			{
				panda1.iscollide2 = false;
				// coll_count += 1;
				// cout << coll_count;
			}

			// The following lines of code check to see if the Panda collides with the goblin on the screen and update its health status accordingly.
			// If this is not the case, the collision variable is set to false.
			collision3 = SDL_HasIntersection(Moverptr, Goblinptr);
			if (collision3 == SDL_TRUE && panda1.iscollide3 == false)
			{
				collid = true;
				panda1.iscollide3 = true;
				std::cout << "collisoon detected" << endl;
				h.changeHealth(gRenderer, assets, collid);
			}
			else if (collision3 == SDL_FALSE && panda1.iscollide3 == true)
			{
				panda1.iscollide3 = false;
				// coll_count += 1;
				// cout << coll_count;
			}

			// The Panda's collision with the apples on the screen is being checked here.
			// If collision is detected, the apple is removed by setting its coordinates to zero.
			for (int i = 0; i < 7; i++)
			{
				SDL_Rect vk = App[i]->appleMover;
				collision = SDL_HasIntersection(Moverptr, &vk);
				if (collision == SDL_TRUE)
				{
					++panda1; 
					App[i]->appleMover = {0,0,0,0};
				}
			}

			// If the Panda's health has been completely depleted due to collisions with game obstacles, all items on the screen are removed, and the game screen changes to the quit game screen.
			if (h.health == 3 && current_screen == 2)
			{
				current_screen = 4;
				panda1.pandaMover = {0, 0, 0, 0};
				obstacles.treeMover = {0, 0, 0, 0};
				obstacles.logMover = {0, 0, 0, 0};
				obstacles.waterMover = {0, 0, 0, 0};
				ghost.moverRect = {0, 0, 0, 0};
				ghost1.moverRect = {0, 0, 0, 0};
				goblin.moverRect = {0, 0, 0, 0};
				gTexture = loadTexture("quitscreen.png");
			}

			// Checks if the Panda has fallen into the water. The game ends if this is the case.
			if (col_fall == true && current_screen == 2)
			{
				current_screen = 5;
				panda1.pandaMover = {0, 0, 0, 0};
				obstacles.treeMover = {0, 0, 0, 0};
				obstacles.logMover = {0, 0, 0, 0};
				obstacles.waterMover = {0, 0, 0, 0};
				ghost.moverRect = {0, 0, 0, 0};
				ghost1.moverRect = {0, 0, 0, 0};
				goblin.moverRect = {0, 0, 0, 0};
				gTexture = loadTexture("fellscreen.png");
			}

			// If panda has successfully collected all 7 apples and reached bamboo space, the screen switches to the win game screen.
			if (panda1.apples == 7 && current_screen == 2)
			{
				current_screen = 6;
				panda1.pandaMover = {0, 0, 0, 0};
				obstacles.treeMover = {0, 0, 0, 0};
				obstacles.logMover = {0, 0, 0, 0};
				obstacles.waterMover = {0, 0, 0, 0};
				ghost.moverRect = {0, 0, 0, 0};
				ghost1.moverRect = {0, 0, 0, 0};
				goblin.moverRect = {0, 0, 0, 0};

				gTexture = loadTexture("winscreen.png");
			}
		}

		//**********************
		SDL_RenderPresent(gRenderer); // displays the updated renderer

		SDL_Delay(60); // causes sdl engine to delay for specified miliseconds
	}
}