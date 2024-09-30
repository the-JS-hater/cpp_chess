#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 8

#include <string>

enum Notation {
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H
};

struct Piece {
	char name;
	char color;
	
	Piece(char name, char color) : name{name}, color{color}{};
};

// TODO: fix data representation to use Piece struct instead 
struct Board {
	Piece board[BOARD_SIZE][BOARD_SIZE] = {
		{Piece('R', 'w'), Piece('N', 'w'), Piece('B', 'w'), Piece('Q', 'w'), Piece('K', 'w'), Piece('B', 'w'), Piece('N', 'w'), Piece('R', 'w')},
		{Piece('P', 'w'), Piece('P', 'w'), Piece('P', 'w'), Piece('P', 'w'), Piece('P', 'w'), Piece('P', 'w'), Piece('P', 'w'), Piece('P', 'w')},
		{Piece('E', '_'),Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_')},
		{Piece('E', '_'),Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_')},
		{Piece('E', '_'),Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_')},
		{Piece('E', '_'),Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_'), Piece('E', '_')},
		{Piece('P', 'b'), Piece('P', 'b'), Piece('P', 'b'), Piece('P', 'b'), Piece('P', 'b'), Piece('P', 'b'), Piece('P', 'b'), Piece('P', 'b')},
		{Piece('R', 'b'), Piece('N', 'b'), Piece('B', 'b'), Piece('Q', 'b'), Piece('K', 'b'), Piece('B', 'b'), Piece('N', 'b'), Piece('R', 'b')}
	};
};

Board newBoard();
void printBoard(Board &board);



#endif
