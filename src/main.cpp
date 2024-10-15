#include "../include/board.h"
#include "../include/gui.h"
#include <raylib.h>

int main() {
	Board testBoard = newBoard();
	
	printBoard(testBoard);
	
	initGUI(820);
	
	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			renderBoard(testBoard);
		EndDrawing();
	}
	
	cleanUp();
	CloseWindow();
	return 0;
}
