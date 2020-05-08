#include <iostream>
#include "WindowManager.h"

SDL_Renderer* WindowManager::mRenderer = NULL;
WindowManager::WindowManager()
{
	mWindow = NULL;
	quit = false;
	game = new Game;
}

bool WindowManager::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL was unable to initialize: " << SDL_GetError() << std::endl;
		return false;
	}
	else
	{
		mWindow = SDL_CreateWindow("Tetris Clone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (mWindow == NULL)
		{
			std::cerr << "Window was unable to be created: " << SDL_GetError() << std::endl;
			return false;
		}
		else
		{
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (mRenderer == NULL)
			{
				std::cerr << "Renderer was unable to be created: " << SDL_GetError() << std::endl;
				return false;
			}
		}
	}
	return true;
}
// Game Loop
void WindowManager::run()
{
	game->init();
	while (!quit)
	{
		if (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			else
			{
				game->handleEvent(event);
			}
		}

		game->render();
	}
}

void WindowManager::close()
{
	delete game;
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	mRenderer = NULL;
	mWindow = NULL;
	SDL_Quit();
}