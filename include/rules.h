#ifndef RULES
#define RULES

/* This is used by the arbiter to validate legality of bot moves.
 * It uses the board representation in board.h. This is NOT an efficient
 * board/move representation. Your bot is allowed to use it by including
 * moveGen.h and board.h, but for optimized bots this is not ideal. The API is
 * designed to allow you to create your own, more efficient board
 * representation
 */

#include "board.h"
#include "moveGen.h"

bool isCheck(char color, int psoX, int posY, const Board& board);

bool isCheckmate(char color, const Board& board);

bool legalMove(const Board& board, const Piece& piece, const Position& move);

#endif
