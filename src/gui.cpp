#include <raylib.h>
#include "../include/gui.h"
#include "../include/board.h"

Texture2D backgroundTexture; 
Texture2D whitePawn;
Texture2D blackPawn;
Texture2D whiteKnight;
Texture2D blackKnight;
Texture2D whiteBishop;
Texture2D blackBishop;
Texture2D whiteRook;
Texture2D blackRook;


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
	
	Image tempWhiteKnight = LoadImage("../resources/whiteKnight32x32.png");
	ImageResize(&tempWhiteKnight, windowSize / 8, windowSize / 8);
	
	Image tempBlackKnight = LoadImage("../resources/blackKnight32x32.png");
	ImageResize(&tempBlackKnight, windowSize / 8, windowSize / 8);
	
	Image tempWhiteBishop = LoadImage("../resources/whiteBishop32x32.png");
	ImageResize(&tempWhiteBishop, windowSize / 8, windowSize / 8);
	
	Image tempBlackBishop = LoadImage("../resources/blackBishop32x32.png");
	ImageResize(&tempBlackBishop, windowSize / 8, windowSize / 8);
	
	Image tempWhiteRook = LoadImage("../resources/whiteRook32x32.png");
	ImageResize(&tempWhiteRook, windowSize / 8, windowSize / 8);
	
	Image tempBlackRook = LoadImage("../resources/blackRook32x32.png");
	ImageResize(&tempBlackRook, windowSize / 8, windowSize / 8);
	
	backgroundTexture = LoadTextureFromImage(tempBackground); 
	whitePawn = LoadTextureFromImage(tempWhitePawn); 
	blackPawn = LoadTextureFromImage(tempBlackPawn); 
	whiteKnight = LoadTextureFromImage(tempWhiteKnight); 
	blackKnight = LoadTextureFromImage(tempBlackKnight); 
	whiteBishop = LoadTextureFromImage(tempWhiteBishop); 
	blackBishop = LoadTextureFromImage(tempBlackBishop); 
	whiteRook = LoadTextureFromImage(tempWhiteRook); 
	blackRook = LoadTextureFromImage(tempBlackRook); 
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
				DrawTexture(whitePawn, posX * OFFSET, posY * OFFSET, WHITE);
				break;
			case 'N': 
				DrawTexture(whiteKnight, posX * OFFSET, posY * OFFSET, WHITE);
				break;
			case 'B': 
				DrawTexture(whiteBishop, posX * OFFSET, posY * OFFSET, WHITE);
				break;
			case 'R': 
				DrawTexture(whiteRook, posX * OFFSET, posY * OFFSET, WHITE);
				break;
		}
	} else {
		switch (piece.name){
			case 'P':
				DrawTexture(blackPawn, posX * OFFSET, posY * OFFSET, WHITE);
				break;
			case 'N':
				DrawTexture(blackKnight, posX * OFFSET, posY * OFFSET, WHITE);
				break;
			case 'B':
				DrawTexture(blackBishop, posX * OFFSET, posY * OFFSET, WHITE);
				break;
			case 'R':
				DrawTexture(blackRook, posX * OFFSET, posY * OFFSET, WHITE);
				break;
		}	
	}
}

void cleanUp(){
	UnloadTexture(backgroundTexture);
	UnloadTexture(blackPawn);
	UnloadTexture(whitePawn);
	UnloadTexture(blackKnight);
	UnloadTexture(whiteKnight);
	UnloadTexture(whiteBishop);
	UnloadTexture(blackBishop);
	UnloadTexture(blackRook);
	UnloadTexture(whiteRook);
}
