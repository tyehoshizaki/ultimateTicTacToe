#include "ultimate.h"

void printFullBoard(UltimateGameBoard *board) {
    printf("Full Board:\n");
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

void printBoardUlt(UltimateGameBoard *board) {
    for (int i = 0; i < 9; i++) {
        printf("Board %d:\n", i + 1);
        printBoard(&board->boards[i]);
        printf("\n");
    }
    printf("Full Board\n");
    printFullBoard(board);
}

int checkOccupiedUlt(UltimateGameBoard *board, int boardIndex, int position) {
    if (boardIndex < 0 || boardIndex >= 9) {
        return 1;
    }
    return checkOccupied(&board->boards[boardIndex], position);
}

int checkIfBoardFinished(UltimateGameBoard *board, int boardIndex){
    if (boardIndex < 0 || boardIndex >= 9) {
        return 1;
    }
    if((board->xBoard | board->oBoard | board->fullBoards) & (1 << boardIndex)) {
        return 1;
    }
    return 0;
}

int playMoveUlt(UltimateGameBoard *board, int player, int boardIndex, int position){
    if (boardIndex < 0 || boardIndex >= 9) {
        return 1;
    }
    if (position < 0 || position > 8) {
        return 1;
    }
    if (checkOccupiedUlt(board, boardIndex, position)) {
        return 1;
    }
    if (boardIndex != board->nextBoard && board->nextBoard != -1) {
        return 1;
    }

    if (player == 1) {
        board->boards[boardIndex].xBoard |= (1 << position);
    } else {
        board->boards[boardIndex].oBoard |= (1 << position);
    }

    return 0;
}

int changeNextBoard(UltimateGameBoard *board, int position) {
    if (position < 0 || position > 8) {
        return 1;
    }
    if ((board->fullBoards | board->xBoard | board->oBoard) & (1 << position)) {
        board->nextBoard = -1;
    } else {
        board->nextBoard = position;
    }

    return 0;
}

int checkWinUlt(uint16_t board) {
    return checkWin(board);
}

int checkWinnerUlt(UltimateGameBoard *board, int player) {
    uint16_t playerBoard = (player == 1) ? board->xBoard : board->oBoard;
    return checkWinUlt(playerBoard);
}

int playerWonBoard(UltimateGameBoard *board, int player, int boardIndex) {
    if (boardIndex < 0 || boardIndex >= 9) {
        return 1;
    }
    if (player == 1) {
        board->xBoard |= (1 << boardIndex);
    } else {
        board->oBoard |= (1 << boardIndex);
    }
    return 0;
}

int boardIsFull(UltimateGameBoard *board, int boardIndex) {
    if (boardIndex < 0 || boardIndex >= 9) {
        return 1;
    }
    board->fullBoards |= (1 << boardIndex);
    return 0;
}

int checkDrawUlt(UltimateGameBoard *board) {
    if ((board->xBoard | board->oBoard | board->fullBoards) == 0b111111111) {
        return 1;
    }

    return 0;
}
