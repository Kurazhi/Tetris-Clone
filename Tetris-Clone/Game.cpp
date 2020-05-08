#include "Game.h"
#include "WindowManager.h"
#include <sstream>
#include <iostream>
#include <ctime>


void Game::init()
{
	srand(time(NULL));
	mPosX = 4;
	mPosY = 0;
	for (int col = 0; col < Board::blockSize; col++)
	{
		for (int row = 0; row < Board::blockSize; row++)
		{
			currentBlock[col][row] = '.';
		}
	}
	spawnBlock();
	placeCurrentBlock();
}
Game::Game()
{
	
}
void Game::handleEvent(SDL_Event& e)
{
	if (e.key.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			removeCurrentBlock();
			--mPosX;
			if (isCollide())
			{
				++mPosX;
			}
			placeCurrentBlock();
			break;
		case SDLK_d:
			removeCurrentBlock();
			++mPosX;
			if (isCollide())
				--mPosX;
			placeCurrentBlock();
			break;
		case SDLK_s:
			removeCurrentBlock();
			++mPosY;
			if (isCollide())
				--mPosY;
			placeCurrentBlock();
			break;
		case SDLK_w:
			removeCurrentBlock();
			--mPosY;
			if (isCollide())
				++mPosY;
			placeCurrentBlock();
			break;
		case SDLK_z:
			removeCurrentBlock();
			rotateCurrentBlock();
			if (isCollide())
				for (int i = 0; i < 3; i++)
					rotateCurrentBlock();
			placeCurrentBlock();
			break;
		case SDLK_x:
			removeCurrentBlock();
			for (int i = 0; i < 3; i++)
				rotateCurrentBlock();
			if (isCollide())
				rotateCurrentBlock();
			placeCurrentBlock();
			break;
		}
	}
}
void Game::render()
{
	SDL_SetRenderDrawColor(WindowManager::mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(WindowManager::mRenderer);
	mBoard.renderBoard();
	mBoard.renderBlocks();
	SDL_RenderPresent(WindowManager::mRenderer);
}

bool Game::isCollide()
{
	for (int colBlock = 0, colBoard = mPosY; colBlock < Board::blockSize; colBlock++, colBoard++)
	{
		for (int rowBlock = 0, rowBoard = mPosX; rowBlock < Board::blockSize; rowBlock++, rowBoard++)
		{
			if (currentBlock[colBlock][rowBlock] == 'X')
			{
				if (mPosX + rowBlock < 0 || mPosX + rowBlock >= Board::boardWidth || mPosY + colBlock < 0 || mPosY + colBlock >= Board::boardHeight)
				{	
					return true;
				}
				else if (mPosX >= 0 && mPosY >= 0)
				{
					if (mBoard.getBoard(mPosX, mPosY) != '.')
						return true;
				}
			}
			
		}
	}
	return false;
}
void Game::spawnBlock()
{
	std::cout << "Spawning block ID" << std::endl;
	currentBlockID = (rand() % 7);
	for (int row = 0; row < Board::blockSize; row++)
	{
		for (int col = 0; col < Board::blockSize; col++)
		{
			currentBlock[row][col] = mBoard.getTetromino(currentBlockID, row, col);
		}
	}
}

void Game::placeCurrentBlock(int moveX, int moveY)
{
	for (int rowCurrent = 0, rowBoard = mPosY; rowCurrent < Board::blockSize; rowCurrent++, rowBoard++)
	{
		for (int colCurrent = 0, colBoard = mPosX; colCurrent < Board::blockSize; colCurrent++, colBoard++)
		{
			if (currentBlock[rowCurrent][colCurrent] == 'X')
			{
				char charID = '0' + currentBlockID;
				mBoard.editBoard(colBoard, rowBoard, charID);
			}
		}
	}
}
void Game::removeCurrentBlock()
{
	for (int rowCurrent = 0, rowBoard = mPosY; rowCurrent < Board::blockSize; rowCurrent++, rowBoard++)
	{
		for (int colCurrent = 0, colBoard = mPosX; colCurrent < Board::blockSize; colCurrent++, colBoard++)
		{
			if (currentBlock[rowCurrent][colCurrent] == 'X')
			{
				mBoard.editBoard(colBoard, rowBoard, '.');
			}
		}
	}
}
void Game::rotateCurrentBlock()
{
	for (int row = 0; row < Board::blockSize / 2; row++) {
		for (int col = row; col < Board::blockSize - row - 1; col++) {
			int temp = currentBlock[row][col];
			currentBlock[row][col] = currentBlock[col][Board::blockSize - 1 - row];
			currentBlock[col][Board::blockSize - 1 - row] = currentBlock[Board::blockSize - 1 - row][Board::blockSize - 1 - col];
			currentBlock[Board::blockSize - 1 - row][Board::blockSize - 1 - col] = currentBlock[Board::blockSize - 1 - col][row];
			currentBlock[Board::blockSize - 1 - col][row] = temp;
		}
	}
}
