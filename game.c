#include "game.h"

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

int checkOccupied(GameBoard *board, int position) {
    if ((board->xBoard | board->oBoard) & (1 << position)) {
        return 1;
    }
    return 0;
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

int checkWin(uint16_t board) {
    if(
        (board & 0b111000000) == 0b111000000 ||
        (board & 0b000111000) == 0b000111000 ||
        (board & 0b000000111) == 0b000000111 ||
        (board & 0b100100100) == 0b100100100 ||
        (board & 0b010010010) == 0b010010010 ||
        (board & 0b001001001) == 0b001001001 ||
        (board & 0b100010001) == 0b100010001 ||
        (board & 0b001010100) == 0b001010100
    ) {
        return 1;
    }else{
        return 0;
    }
}

int checkWinner(GameBoard *board, int player) {
    uint16_t playerBoard = (player == 1) ? board->xBoard : board->oBoard;
    return checkWin(playerBoard);
}

int checkDraw(GameBoard *board) {
    if ((board->xBoard | board->oBoard) == 0b111111111) {
        return 1;
    }

    return 0;
}
