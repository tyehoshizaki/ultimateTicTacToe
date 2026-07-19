#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint16_t xBoard;
    uint16_t oBoard;
} GameBoard;

void printBoard(GameBoard *board);
int checkOccupied(GameBoard *board, int position);
int playMove(GameBoard *board, int player, int position);
int checkWinner(GameBoard *board, int player);
int checkWin(uint16_t board);
int checkDraw(GameBoard *board);

#endif