#ifndef MINIMAX_H
#define MINIMAX_H

#include "game.h"

int checkResult(GameBoard *board);

int minimax(GameBoard *board, int isMaximizing, int player);

int findBestMove(GameBoard *board, int player);

#endif