#include "minimax.h"

int minimax(GameBoard *board, int depth, int isMaximizing, int player) { // ignoring depth for now, but it can be used to limit the search depth
    int result = finishedBoard(board);
    if (result != 2) {
        return result;
    }

    uint16_t freeMoves = possibleMoves(board);
    int score, bestScore;

    if (isMaximizing) {
        bestScore = -1000; // Initialize to a very low value
    } else {
        bestScore = 1000; // Initialize to a very high value
    }

    for(int i = 0; i < 9; i++) {
        if ((1 << i) & freeMoves) {
            GameBoard newBoard = *board;
            playMove(&newBoard, player, i);

            score = minimax(&newBoard, depth, !isMaximizing, player == 1 ? 2 : 1);

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
        bestScore = -1000; // Initialize to a very low value
    } else {
        bestScore = 1000; // Initialize to a very high value
    }

    uint16_t freeMoves = possibleMoves(board);

    for (int i = 0; i < 9; i++) {
        if ((1 << i) & freeMoves){
            GameBoard newBoard = *board;
            playMove(&newBoard, player, i);

            int score = minimax(&newBoard, 0, player == 1 ? 0 : 1, player == 1 ? 2 : 1);

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