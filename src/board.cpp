#include <stdio.h>
#include <string>
#include "../include/board.h"

Board newBoard() {
	return Board();
}

bool isFree(const Board &board, int posX, int posY) {
	return board.board[posY][posX].name == 'E';
}

bool outOfBounds(int posX, int posY){
	return (posX >= 0 && posX <= 7) && (posY >= 0 && posY <= 7);
}

void printBoard(Board &board) {
	std::string output_string = "";
	
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
				output_string += board.board[y][x].name;
		}
		
		output_string += "\n";
	}
	
	printf("%s\n", output_string.c_str());
}

bool isCapturable(const Board &board, char color, int posX, int posY){
	return (board.board[posY][posX].color != color);
}

// WARN: movePiece() does NOT check legality of moves
// only legal moves should be generated and passed in
void movePiece(Board &board, int oldX, int oldY, int newX, int newY){
	const Piece& piece = board.board[oldY][oldX];
	if (piece.name == 'K'){
		if (piece.color == 'w'){
			board.wShortCastle = false;
			board.wLongCastle = false;
		} else {
			board.bShortCastle = false;
			board.bLongCastle = false;
		}
		//TODO: check IF king is currently castling
		// if so, do it and return
	}
	if (piece.name == 'R'){
		bool white = piece.color == 'w';
		if (white && oldX == 0){
			board.wLongCastle = false;
		}
		if (white && oldX == 7){
			board.wShortCastle = false;
		}
		if (!white && oldX == 0){
			board.bLongCastle = false;
		}
		if (!white && oldX == 7){
			board.bShortCastle = false;
		}
	}

	board.board[newY][newX] = piece;
	board.board[oldY][oldX] = Piece('E', '_');
}

