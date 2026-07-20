#ifndef ULTIMATE_H
#define ULTIMATE_H

#include "game.h"

typedef struct {
    GameBoard boards[9];
    uint16_t xBoard;
    uint16_t oBoard;
    uint16_t fullBoards;
    int nextBoard;
} UltimateGameBoard;

void printBoardUlt(UltimateGameBoard *board);
int checkOccupiedUlt(UltimateGameBoard *board, int boardIndex, int position);
int checkIfBoardFinished(UltimateGameBoard *board, int boardIndex);
int playMoveUlt(UltimateGameBoard *board, int player, int boardIndex, int position);
int changeNextBoard(UltimateGameBoard *board, int position);
int checkWinUlt(uint16_t board);
int checkWinnerUlt(UltimateGameBoard *board, int player);
int playerWonBoard(UltimateGameBoard *board, int player, int boardIndex);
int boardIsFull(UltimateGameBoard *board, int boardIndex);
int checkDrawUlt(UltimateGameBoard *board);

#endif