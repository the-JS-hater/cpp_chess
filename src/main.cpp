#include "../include/board.h"
#include "../include/gui.h"
#include <raylib.h>

int main() {
	
	Board testBoard = newBoard();
	
	printBoard(testBoard);
	
	initGUI(420);
	
	while (!WindowShouldClose()) {
		BeginDrawing();
			//TODO:
		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}
