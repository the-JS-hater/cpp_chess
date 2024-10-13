#include <raylib.h>
#include "../include/gui.h"
#include "../include/board.h"


Texture2D backgroundTexture; 


void initGUI(const int& windowSize){
	SetTargetFPS(60);
	SetExitKey(KEY_ESCAPE);
	InitWindow(windowSize, windowSize, "Chess");

	Image tempImage = LoadImage("../resources/chessBoard.png");
	ImageResize(&tempImage, windowSize, windowSize);
	backgroundTexture = LoadTextureFromImage(tempImage); 
}


void renderBoard(const Board& board){
	DrawTexture(backgroundTexture, 0, 0, WHITE);
}


void cleanUp(){
	UnloadTexture(backgroundTexture);
}
