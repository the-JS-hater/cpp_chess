#include "../include/moveGen.h"
#include "../include/board.h"
#include <string>
#include <vector>

std::vector<std::string> generateLegalMoves(const Board &board, char piece, int posX, int posY) {
	// TODO:
	std::vector<std::string> moveArray = {};

	switch (piece) {
		case 'P':
			return generatePawnMoves(board, posX, posY);
			break;
		case 'N':
			break;
		case 'B':
			break;
		case 'R':
			break;
		case 'Q':
			break;
		case 'K':
			break;
	}

	return moveArray;
}


std::vector<std::string> generatePawnMoves(const Board &board, char color, int posX, int posY){
	//TODO:
	std::vector<std::string> moveArray = {};
	int direction = (color == 'w') ? 1 : -1;
	int starting_row = (color == 'w') ? 1 : 6; //assuming 0 indexed position 


	return moveArray;
} 
