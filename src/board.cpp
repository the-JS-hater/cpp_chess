#include <stdio.h>
#include <string>
#include "../include/board.h"

Board newBoard() {
	return Board();
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

