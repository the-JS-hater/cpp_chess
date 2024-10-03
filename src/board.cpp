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
	board.board[newY][newX] = board.board[oldY][oldX];
	board.board[oldY][oldX] = Piece('E', '_');
}

