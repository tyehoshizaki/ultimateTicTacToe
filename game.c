#include "game.h"

int checkOccupied(GameBoard *board, int position) {
    if ((board->xBoard | board->oBoard) & (1 << position)) {
        return 1; // Position is occupied
    }
    return 0; // Position is free
}

int checkWin(GameBoard *board, int player) {
    if (player == 1) {
        if ((board->xBoard & 0b111000000) == 0b111000000 ||
            (board->xBoard & 0b000111000) == 0b000111000 ||
            (board->xBoard & 0b000000111) == 0b000000111 ||
            (board->xBoard & 0b100100100) == 0b100100100 ||
            (board->xBoard & 0b010010010) == 0b010010010 ||
            (board->xBoard & 0b001001001) == 0b001001001 ||
            (board->xBoard & 0b100010001) == 0b100010001 ||
            (board->xBoard & 0b001010100) == 0b001010100 ) {
            return 1;
        }
    } else {
        if ((board->oBoard & 0b111000000) == 0b111000000 ||
            (board->oBoard & 0b000111000) == 0b000111000 ||
            (board->oBoard & 0b000000111) == 0b000000111 ||
            (board->oBoard & 0b100100100) == 0b100100100 ||
            (board->oBoard & 0b010010010) == 0b010010010 ||
            (board->oBoard & 0b001001001) == 0b001001001 ||
            (board->oBoard & 0b100010001) == 0b100010001 ||
            (board->oBoard & 0b001010100) == 0b001010100) {
            return 1;
        }
    }
    return 0; // No winner yet
}

int checkDraw(GameBoard *board) {
    if ((board->xBoard | board->oBoard) == 0b111111111) {
        return 1;
    }

    return 0;
}

int finishedBoard(GameBoard *board) {
    if (checkWin(board, 1)){
        return 1;
    }
    if (checkWin(board, 2)){
        return -1;
    }
    if (checkDraw(board)){
        return 0;
    }
    return 2;
}

void printBoard(GameBoard *board) {
    for (int i = 0; i < 9; i++) {
        if (board->xBoard & (1 << i)) {
            printf("X ");
        } else if (board->oBoard & (1 << i)) {
            printf("O ");
        } else {
            printf("%d ", i + 1);
        }

        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
}

uint16_t possibleMoves(GameBoard *board) {
    uint16_t occupied = board->xBoard | board->oBoard;
    uint16_t freePositions = ~occupied & 0b111111111; // Only consider the first 9 bits

    return freePositions;
}

int possibleNextMove(GameBoard *board){
    uint16_t freePositions = possibleMoves(board);
    int nextAvailableMove = __builtin_ctz(freePositions);

    return nextAvailableMove;
}

int playMove(GameBoard *board, int player, int position) {
    if (checkOccupied(board, position)) {
        return 1;
    }

    if (player == 1) {
        board->xBoard |= (1 << position);
        return 0;
    } else {
        board->oBoard |= (1 << position);
        return 0;
    }

    return 1;
}