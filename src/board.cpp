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
			switch (board.board[y][x]) {
				case EMPTY:
					output_string += '-';
					break;
				case PAWN:
					output_string += 'P';
					break;
				case KNIGHT:
					output_string += 'K';
					break;
				case BISHOP:
					output_string += 'B';
					break;
				case ROOK:
					output_string += 'R';
					break;
				case QUEEN:
					output_string += 'Q';
					break;
				case KING:
					output_string += 'K';
					break;
			}
		}
		output_string += "\n";
	}

	printf("%s\n", output_string.c_str());
}
