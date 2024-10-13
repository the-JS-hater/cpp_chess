#ifndef RULES
#define RULES

#include "board.h"

bool isCheck(char color, int psoX, int posY, const Board& board);

bool isCheckmate(char color, const Board& board);


#endif
