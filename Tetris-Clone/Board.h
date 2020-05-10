#pragma once
#include <SDL.h>
#include <array>
class Board
{
public:
	Board();
	void renderBoard();
	void renderBlocks();
	// Cell formating constants
	static const int pixelsPerCell = 20;
	static const int boardWidth = 12;
	static const int boardHeight = 18;
	static int lLineX;
	static int topLineY;

	// Tetrominos constants
	static const int maxTetrominos = 7;
	static const int blockSize = 4;

	//bool isCollide(int tetrominoID, int rotation, int posX, int posY);
	static char tetrominos[maxTetrominos][blockSize][blockSize];
	static char getTetromino(int tetroID, int row, int col) { return tetrominos[tetroID][row][col]; }

	char getBoard(int col, int row) { return mBoard[row][col]; }
	void editBoard(int colBoard, int rowBoard, char c) { mBoard[rowBoard][colBoard] = c; }
	void close();

	void deleteLine(int boardY);
	void deletePossibleLines();

	// Debug
	void displayBoard();
private:
	
	char mBoard[boardHeight][boardWidth];
	SDL_Rect boardRects[(boardHeight * boardWidth)];
	
	
};

