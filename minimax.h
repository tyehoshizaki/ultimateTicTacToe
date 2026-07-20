#ifndef MINIMAX_H
#define MINIMAX_H

#include "game.h"

uint16_t possibleMoves(GameBoard *board);
int possibleNextMove(GameBoard *board);
int checkResult(GameBoard *board);
int minimax(GameBoard *board, int isMaximizing, int player);
int findBestMove(GameBoard *board, int player);

#endif