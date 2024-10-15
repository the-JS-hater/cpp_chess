#include "../include/rules.h"
#include "../include/board.h"
#include "../include/moveGen.h"
#include <vector>
#include <algorithm>

bool isCheck(char color, int posX, int posY, const Board& board){
	Position kingsPos = Position(posX, posY);
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
			if(std::find(legalMoves.begin(), legalMoves.end(), kingsPos) != legalMoves.end()) {
				return true;
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
	if (legalMoves.empty()){
		return true;
	}
	return false;
}


bool legalMove(const Board& board, const Piece& piece, const Position& move){
	std::vector<Position> legalMoves = generateLegalMoves(board, piece, move.x, move.y);
	
	if(std::find(legalMoves.begin(), legalMoves.end(), move) != legalMoves.end()) {
    return true;
	} else {
		return false;
	}
}
