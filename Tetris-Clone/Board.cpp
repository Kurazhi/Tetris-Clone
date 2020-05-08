#include "Board.h"
#include "WindowManager.h"
#include <iostream>

int Board::lLineX = (WindowManager::screenWidth - boardWidth * pixelsPerCell) / 2;
int Board::topLineY = (WindowManager::screenHeight - boardHeight * pixelsPerCell) / 2;
char Board::tetrominos[Board::maxTetrominos][Board::blockSize][Board::blockSize] =
{
	{
		// Tetris Block
		{'.', '.', 'X', '.'},
		{'.', '.', 'X', '.'},
		{'.', '.', 'X', '.'},
		{'.', '.', 'X', '.'}
	},
	{
		// Zig Zag Block
		{'.', '.', 'X', '.'},
		{'.', 'X', 'X', '.'},
		{'.', 'X', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		// Zig Zag Block Inverse
		{'.', 'X', '.', '.'},
		{'.', 'X', 'X', '.'},
		{'.', '.', 'X', '.'},
		{'.', '.', '.', '.'}
	},
	{
		 // T block
		{'.', '.', 'X', '.'},
		{'.', 'X', 'X', '.'},
		{'.', '.', 'X', '.'},
		{'.', '.', '.', '.'}
	},
	{
		// L shaped Block
		{'.', '.', '.', '.'},
		{'.', 'X', '.', '.'},
		{'.', 'X', '.', '.'},
		{'.', 'X', 'X', '.'}
	},
	{
		// Inverse L shaped Block
		{'.', '.', '.', '.'},
		{'.', '.', 'X', '.'},
		{'.', '.', 'X', '.'},
		{'.', 'X', 'X', '.'}
	},
	{
		// Square Block
		{'.', '.', '.', '.'},
		{'.', 'X', 'X', '.'},
		{'.', 'X', 'X', '.'},
		{'.', '.', '.', '.'}
	}
};
Board::Board()
{
	for (int row = 0; row < boardHeight; row++)
	{
		for (int col = 0; col < boardWidth; col++)
		{
			int rectIndex = row * boardWidth + col;
			mBoard[row][col] = '.';
			boardRects[rectIndex].x = lLineX + col * pixelsPerCell;
			boardRects[rectIndex].y = topLineY + row * pixelsPerCell;
			boardRects[rectIndex].w = pixelsPerCell;
			boardRects[rectIndex].h = pixelsPerCell;
		}
	}
}
void Board::renderBoard()
{
	
	SDL_SetRenderDrawColor(WindowManager::mRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawLine(WindowManager::mRenderer, lLineX - 1, topLineY, lLineX - 1, topLineY + boardHeight * pixelsPerCell);
	SDL_RenderDrawLine(WindowManager::mRenderer, lLineX + boardWidth * pixelsPerCell, topLineY, lLineX + boardWidth * pixelsPerCell, topLineY + boardHeight * pixelsPerCell);
	//SDL_RenderDrawLine(WindowManager::mRenderer, lLineX, topLineY + WindowManager::screenHeight, lLineX + WindowManager::screenWidth, topLineY + WindowManager::screenHeight);
}
void Board::renderBlocks()
{
	
	for (int row = 0; row < boardHeight; row++)
	{
		for (int col = 0; col < boardWidth; col++)
		{
			switch (mBoard[row][col])
			{
			case '0':
				// Red Tetris Block
				SDL_SetRenderDrawColor(WindowManager::mRenderer, 0xFF, 0x00, 0x00, 0xFF);
				break;
			case '1':
				// Green Zig Zag Block
				SDL_SetRenderDrawColor(WindowManager::mRenderer, 0x00, 0xFF, 0x00, 0xFF);
				break;
			case '2':
				// Inverse Zig Zag Block
				SDL_SetRenderDrawColor(WindowManager::mRenderer, 0x00, 0xFF, 0x00, 0xFF);
				break;
			case '3':
				// Blue T Block
				SDL_SetRenderDrawColor(WindowManager::mRenderer, 0x00, 0x00, 0xFF, 0xFF);
				break;
			case '4':
				// Cyan L Block
				SDL_SetRenderDrawColor(WindowManager::mRenderer, 0x00, 0xFF, 0xFF, 0xFF);
				break;
			case '5':
				// Inverse Cyan L Block
				SDL_SetRenderDrawColor(WindowManager::mRenderer, 0x00, 0xFF, 0xFF, 0xFF);
				break;
			case '6':
				// Yellow Square Block
				SDL_SetRenderDrawColor(WindowManager::mRenderer, 0xFF, 0xFF, 0x00, 0xFF);
				break;
			case '.':
				SDL_SetRenderDrawColor(WindowManager::mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				break;
			default:
				break;
			}
			int rectIndex = row * boardWidth + col;
			SDL_RenderFillRect(WindowManager::mRenderer, &boardRects[rectIndex]);
		}
	}
}
void Board::close()
{
}
void Board::displayBoard()
{
	for (int i = 0; i < boardHeight; i++)
	{
		for (int j = 0; j < boardWidth; j++)
		{
			std::cout << mBoard[i][j];
		}
		std::cout << std::endl;
	}
}

//bool Board::isCollide(int TetrominoID, int rotation, int posX, int posY)
//{
//	for (int pX = 0; pX < Blocks::blockSize; pX++)
//	{
//		for (int pY = 0; pY < Blocks::blockSize; pY++)
//		{
//			int piece = blocks.rotate(pX, pY, rotation);
//
//			int board = (posX + pY) * Board::boardWidth + (posX + pX);
//
//			// Bounds checking
//			if (posX + pX >= 0 && posX + pX < Board::boardWidth)
//			{
//				if (posY + pY >= 0 && posY + pY < Board::boardHeight)
//				{
//					if (blocks.tetromino[TetrominoID][piece] == 'X' && mBoard[board] != 0)
//				}
//			}
//		}
//	}
//}