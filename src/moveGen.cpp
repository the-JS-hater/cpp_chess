#include "../include/moveGen.h"
#include "../include/board.h"
#include <vector>


std::vector<Position> generateLegalMoves(const Board &board, Piece piece, int posX, int posY) {
	// TODO:
	std::vector<Position> moveArray = {};

	switch (piece.name) {
		case 'P':
			return generatePawnMoves(board, piece.color, posX, posY);
			break;
		case 'N':
			return generateKnightMoves(board, piece.color, posX, posY);
			break;
		case 'B':
			return generateBishopMoves(board, piece.color, posX, posY);
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


std::vector<Position> generatePawnMoves(const Board &board, char color, int posX, int posY){
	//TODO:
	std::vector<Position> moveArray = {};
	int direction = (color == 'w') ? 1 : -1;
	int starting_row = (color == 'w') ? 1 : 6; //assuming 0 indexed position 
	
	if (outOfBounds(posX, posY + (1 * direction))){
		return moveArray;
	}

	if (isFree(board, posX, posY + (1 * direction))) {
		moveArray.push_back(Position(posX, posY + (1 * direction)));
	}

	if (posY == starting_row && isFree(board, posX, posY + (2 * direction))) {
		moveArray.push_back(Position(posX, posY + (2 * direction)));
	}
	//TODO: add legal captures
	//TODO: add enPassant

	return moveArray;
}


std::vector<Position> generateKnightMoves(const Board &board, char color, int posX, int posY){
	//TODO:
	std::vector<Position> moveArray = {};
	std::vector<Position> candidateMoves = {};
	candidateMoves.push_back(Position(posX -1, posY -2));
	candidateMoves.push_back(Position(posX -2, posY -1));
	candidateMoves.push_back(Position(posX -2, posY +1));
	candidateMoves.push_back(Position(posX -1, posY +2));
	candidateMoves.push_back(Position(posX +1, posY -2));
	candidateMoves.push_back(Position(posX +2, posY -1));
	candidateMoves.push_back(Position(posX +2, posY +1));
	candidateMoves.push_back(Position(posX +1, posY +2));
	
	for (const Position candidateMove : candidateMoves) {
		if (!outOfBounds(candidateMove.x, candidateMove.y)) {
			moveArray.push_back(candidateMove);
		}
	}
	
	//TODO: filter illegal captures
	return moveArray;
}


std::vector<Position> generateBishopMoves(const Board &board, char color, int posX, int posY){
	//TODO: 
	std::vector<Position> moveArray = {};

	for (int y = posY; y <= 7; y++){
		for (int x = posX; x <= 7; x++){
			if (isFree(board, posX, posY)){
				moveArray.push_back(Position(x, y));
			}
			//TODO: add legal captures
		}
	}	

	for (int y = posY; y >= 0; y--){
		for (int x = posX; x >= 0; x--){
			if (isFree(board, posX, posY)){
				moveArray.push_back(Position(x, y));
			}
			//TODO: add legal captures
		}
	}	
	
	for (int y = posY; y <= 7; y++){
		for (int x = posX; x >= 0; x--){
			if (isFree(board, posX, posY)){
				moveArray.push_back(Position(x, y));
			}
			//TODO: add legal captures
		}
	}	

	for (int y = posY; y >= 0; y--){
		for (int x = posX; x <= 7; x++){
			if (isFree(board, posX, posY)){
				moveArray.push_back(Position(x, y));
			}
			//TODO: add legal captures
		}
	}

	return moveArray;
}

