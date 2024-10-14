#ifndef MOVE_GEN 
#define MOVE_GEN

/* This is used by the arbiter to validate legality of bot moves.
 * It uses the board representation in board.h. This is NOT an efficient
 * board/move representation. Your bot is allowed to use it by including
 * moveGen.h and board.h, but for optimized bots this is not ideal. The API is
 * designed to allow you to create your own, more efficient board
 * representation
 */

#include "board.h"
#include <string>
#include <vector>

struct Position {
	int x;
	int y;

	Position(int x, int y) : x{x}, y{y} {};
};

std::vector<Position> generateLegalMoves(const Board &board, Piece piece, int posX, int posY); 

std::vector<Position> generatePawnMoves(const Board &board, char color, int posX, int posY);

std::vector<Position> generateKnightMoves(const Board &board, char color, int posX, int posY);

std::vector<Position> generateBishopMoves(const Board &board, char color, int posX, int posY);

std::vector<Position> generateRookMoves(const Board &board, char color, int posX, int posY);

std::vector<Position> generateQueenMoves(const Board &board, char color, int posX, int posY);

std::vector<Position> generateKingMoves(const Board &board, char color, int posX, int posY);

#endif
