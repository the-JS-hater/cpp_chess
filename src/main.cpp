#include "../include/board.h"
#include "../include/gui.h"
#include <raylib.h>

int main() {
	Board testBoard = newBoard();
	
	printBoard(testBoard);
	
	initGUI(620);
	
	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);
			renderBoard(testBoard);
		EndDrawing();
	}
	
	//cleanUp();
	CloseWindow();
	return 0;
}
