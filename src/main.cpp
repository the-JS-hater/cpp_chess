#include <stdio.h>
#include <vector>
#include "../include/board.h"
#include "../include/moveGen.h"

int main() {
	
	Board testBoard = newBoard();
	
	printBoard(testBoard);
	
	Piece piece = testBoard.board[1][1];

	auto moveList = generatePawnMoves(testBoard, piece.color, 1, 1);			
	printf("%d %d \n", moveList[0].x, moveList[0].y);
	printf("%d %d \n", moveList[1].x, moveList[1].y);

	return 0;
}
