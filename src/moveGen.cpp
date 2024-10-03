#include "../include/moveGen.h"
#include "../include/board.h"
#include <vector>
#include <stdio.h>
#include <cstdlib>

std::vector<Position> generateLegalMoves(const Board &board, Piece piece, int posX, int posY) {
	// TODO:
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
			return generateRookMoves(board, piece.color, posX, posY);
			break;
		case 'Q':
			return generateQueenMoves(board, piece.color, posX, posY);
			break;
		case 'K':
			return generateKingMoves(board, piece.color, posX, posY);
			break;
		default:
			//NOTE: SHOULD NEVER BE REACHED
			printf("ILLEGAL PIECE DISCOVERED, CRASHING IMMIDIETLEY \n");
			abort();
			break;
	}
	// NOTE: this is only here to make the LSP shut up
	return std::vector<Position> {};
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


std::vector<Position> generateRookMoves(const Board &board, char color, int posX, int posY){
	std::vector<Position> moveArray = {};
	//TODO: add legal captures
	int smallest_x = 0, smallest_y = 0, largest_x = 7, largest_y = 7;
	
	for (int x = posX; x <= 7; x++){
		if (!isFree(board, x, posY)){
			break;
		}
		moveArray.push_back(Position(x, posY));
	}

	for (int x = posX; x >= 0; x--){
		if (!isFree(board, x, posY)){
			break;
		}
		moveArray.push_back(Position(x, posY));
	}

	for (int y = posY; y <= 0; y++){
		if (!isFree(board, posX, y)){
			break;
		}
		moveArray.push_back(Position(posX, y));
	}
	
	for (int y = posY; y >= 0; y--){
		if (!isFree(board, posX, y)){
			break;
		}
		moveArray.push_back(Position(posX, y));
	}
	return moveArray;
}


std::vector<Position> generateQueenMoves(const Board &board, char color, int posX, int posY) {
	std::vector<Position> diagonalMoves = generateBishopMoves(board, color, posX, posY);
	std::vector<Position> straightMoves = generateRookMoves(board, color, posX, posY);
	
	//Howto extend one vec with another, because c++ is a beutiful language (sarcasm)
	diagonalMoves.insert(std::end(diagonalMoves), std::begin(straightMoves), std::end(straightMoves));

	return diagonalMoves;
}


std::vector<Position> generateKingMoves(const Board &board, char color, int posX, int posY){
	//TODO:
	std::vector<Position> moveArray = {};
	
	//TODO: filter legal and illegal captures
	//TODO: filter moving into check
	//TODO: add castling
	for (int x = posX - 1; x <= posX + 1; x++){
		for (int y = posY - 1; y <= posY + 1; y++) {
			if (!outOfBounds(x, y)){
				moveArray.push_back(Position(x, y));
			}
		}
	}

	return moveArray;
}
