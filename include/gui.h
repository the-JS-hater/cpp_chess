#ifndef GUI
#define GUI

#include "board.h"

void initGUI(const int& windowSize);
void renderBoard(const Board&);
void renderPiece(const Piece& piece, int posX, int posY);
void cleanUp();

#endif
