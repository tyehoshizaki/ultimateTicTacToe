#include "minimax.h"

int checkResult(GameBoard *board) {
    if (checkWinner(board, 1)) {
        return 1; // X wins
    } else if (checkWinner(board, 2)) {
        return -1; // O wins
    } else if (checkDraw(board)) {
        return 0; // Draw
    }
    return 2; // Game is still ongoing
}

int minimax(GameBoard *board, int isMaximizing, int player) {
    int result = checkResult(board);
    if (result != 2) {
        return result;
    }

    uint16_t freeMoves = possibleMoves(board);
    int score, bestScore;

    if (isMaximizing) {
        bestScore = -1000;
    } else {
        bestScore = 1000;
    }

    for(int i = 0; i < 9; i++) {
        if ((1 << i) & freeMoves) {
            GameBoard newBoard = *board;
            playMove(&newBoard, player, i);

            score = minimax(&newBoard, !isMaximizing, player == 1 ? 2 : 1);

            if (isMaximizing) {
                bestScore = score > bestScore ? score : bestScore;
            } else {
                bestScore = score < bestScore ? score : bestScore;
            }
        }
    }

    return bestScore;
}

int findBestMove(GameBoard *board, int player) {
    int bestMove = -1;
    int bestScore;
    if (player == 1) {
        bestScore = -1000;
    } else {
        bestScore = 1000;
    }

    uint16_t freeMoves = possibleMoves(board);

    for (int i = 0; i < 9; i++) {
        if ((1 << i) & freeMoves){
            GameBoard newBoard = *board;
            playMove(&newBoard, player, i);

            int score = minimax(&newBoard, player == 1 ? 0 : 1, player == 1 ? 2 : 1);

            if (player == 1) {
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = i;
                }
            } else {
                if (score < bestScore) {
                    bestScore = score;
                    bestMove = i;
                }
            }
        }
    }
    return bestMove;
}