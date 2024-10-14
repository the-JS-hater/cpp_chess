#include <raylib.h>
#include "../include/gui.h"
#include "../include/board.h"

Texture2D backgroundTexture; 
Texture2D whitePawn;
Texture2D blackPawn;


void initGUI(const int& windowSize){
	SetTargetFPS(60);
	SetExitKey(KEY_ESCAPE);
	InitWindow(windowSize, windowSize, "Chess");

	Image tempBackground = LoadImage("../resources/chessBoard.png");
	ImageResize(&tempBackground, windowSize, windowSize);
	
	Image tempWhitePawn = LoadImage("../resources/whitePawn32x32.png");
	ImageResize(&tempWhitePawn, windowSize / 8, windowSize / 8);
	
	Image tempBlackPawn = LoadImage("../resources/blackPawn32x32.png");
	ImageResize(&tempBlackPawn, windowSize / 8, windowSize / 8);
	
	backgroundTexture = LoadTextureFromImage(tempBackground); 
	whitePawn = LoadTextureFromImage(tempWhitePawn); 
	blackPawn = LoadTextureFromImage(tempBlackPawn); 
}


void renderBoard(const Board& board){
	DrawTexture(backgroundTexture, 0, 0, WHITE);
	for (int y = 0; y < BOARD_SIZE; y++){
		for (int x = 0; x < BOARD_SIZE; x++){
			const Piece& piece = board.board[y][x];
			if (piece.name == 'E'){
				continue;
			}
			renderPiece(piece, x, y);
		}	
	
	}
}


void renderPiece(const Piece& piece, int posX, int posY){
	const int OFFSET = GetScreenWidth() / 8;
	if (piece.color == 'w'){
		switch (piece.name){
			case 'P': 
				puts("HERE");
				DrawTexture(whitePawn, posX * OFFSET, posY * OFFSET, WHITE);
				break;
		}
	} else {
		switch (piece.name){
			case 'P':
				DrawTexture(blackPawn, posX * OFFSET, posY * OFFSET, WHITE);
				break;
		}	
	}
}

void cleanUp(){
	UnloadTexture(backgroundTexture);
	UnloadTexture(blackPawn);
	UnloadTexture(whitePawn);
}
