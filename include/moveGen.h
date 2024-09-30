#ifndef MOVE_GEN 
#define MOVE_GEN

#include "board.h"
#include <string>
#include <vector>

std::vector<std::string> generateLegalMoves(const Board &board, char piece, int posX, int posY); 


std::vector<std::string> generatePawnMoves(const Board &board, int posX, int posY);


#endif
