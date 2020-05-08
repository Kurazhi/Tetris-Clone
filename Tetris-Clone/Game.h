#pragma once
#include "SDL.h"
#include "Board.h"

#include <string>


class Game
{
public:
	
	Game();
	void init();
	void handleEvent(SDL_Event& e);
	void render();
	bool isCollide();
	void spawnBlock();
	void placeCurrentBlock(int moveX = 0, int moveY = 0);
	void removeCurrentBlock();
	void rotateCurrentBlock();

	int mPosX, mPosY;
	Board mBoard;
private:
	char currentBlock[Board::blockSize][Board::blockSize];
	int currentBlockID;
	int nextPosX, nextPosY;
	
};

