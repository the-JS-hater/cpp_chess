#ifndef MOVE_GEN 
#define MOVE_GEN

#include "board.h"
#include <string>
#include <vector>

struct Position {
	int x;
	int y;

	Position(int x, int y) : x{x}, y{y} {};
};

std::vector<Position> generateLegalMoves(const Board &board, char piece, int posX, int posY); 


std::vector<Position> generatePawnMoves(const Board &board, char color, int posX, int posY);

std::vector<Position> generateKnightMoves(const Board &board, char color, int posX, int posY);

std::vector<Position> generateBishopMoves(const Board &board, char color, int posX, int posY);

#endif
