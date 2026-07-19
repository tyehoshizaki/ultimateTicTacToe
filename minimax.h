#ifndef MINIMAX_H
#define MINIMAX_H

#include "game.h"

int minimax(GameBoard *board, int depth, int isMaximizing, int player);

int findBestMove(GameBoard *board, int player);

#endif