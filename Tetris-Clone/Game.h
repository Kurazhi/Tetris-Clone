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
	void gravityTime();
	void createNewBlock();
	
	
	Board mBoard;
	static unsigned long delayGravity;
private:
	// Current Block data
	int mPosX, mPosY;
	char currentBlock[Board::blockSize][Board::blockSize];
	int currentBlockID;

	// Next Block Date
	int nextPosX, nextPosY;
	char nextBlock[Board::blockSize][Board::blockSize];
	int nextBlockID;

	unsigned long start, end;
	
};

