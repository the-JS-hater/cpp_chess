#include "../include/rules.h"
#include "../include/board.h"
#include "../include/moveGen.h"
#include <vector>


bool isCheck(char color, int posX, int posY, const Board& board){
	for (int y = 0; y < BOARD_SIZE; y++){
		for (int x = 0; x < BOARD_SIZE; x++){
			Piece currentPiece = board.board[y][x];
			
			if (currentPiece.name == 'E'){
				continue;
			}
			if (currentPiece.color == color){
				continue;
			}

			std::vector<Position> legalMoves = generateLegalMoves(board, currentPiece, x, y);
			for (Position move : legalMoves) {
				if (move.x == posX && move.y == posY){
					return true;
				}
			}
		}		
	}	

	return false;
}


bool isCheckmate(char color, int posX, int posY, const Board& board){
	if (!isCheck(color, posX, posY, board)){
		return false;
	}
	
	const Piece& king = board.board[posY][posX];
	std::vector<Position> legalMoves = generateLegalMoves(board, king, posX, posY);
	if (legalMoves.size() == 0){
		return true;
	}
	return false;
}
