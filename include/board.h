#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 8

#include <string>

enum Pieces {
	EMPTY,
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING,
};

struct Piece {
	std::string name;
	char color;
	
	Piece(std::string name, char color) : name{name}, color{color}{};
};

// TODO: fix data representation to use Piece struct instead 
struct Board {
	Pieces board[BOARD_SIZE][BOARD_SIZE] = {
		{ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
		{PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
		{ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}
	};
};

Board newBoard();
void printBoard(Board &board);



#endif
