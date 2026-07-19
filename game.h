#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint16_t xBoard;
    uint16_t oBoard;
} GameBoard;

int checkOccupied(GameBoard *board, int position);

int checkWin(GameBoard *board, int player);

int checkDraw(GameBoard *board);

void printBoard(GameBoard *board);

uint16_t possibleMoves(GameBoard *board);

int possibleNextMove(GameBoard *board);

int finishedBoard(GameBoard *board);

int playMove(GameBoard *board, int player, int position);

#endif