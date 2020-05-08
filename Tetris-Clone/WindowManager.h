#pragma once
#include "Game.h"
#include <SDL.h>
class WindowManager
{
public:
	static const int screenHeight = 640;
	static const int screenWidth = 640;
	WindowManager();
	
	bool init();
	void run();
	void close();


	// Exit program
	bool quit;
	// Getters
	SDL_Window* getWindow() { return mWindow; }
	SDL_Renderer* getRenderer() { return mRenderer; }

	static SDL_Renderer* mRenderer;
	Game* game;
private:
	SDL_Window* mWindow;
	
	SDL_Event event;
};

