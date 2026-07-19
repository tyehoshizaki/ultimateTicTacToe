#include "minimax.h"

int minimax(GameBoard *board, int depth, int isMaximizing, int player) {
    if (checkWin(board, 1)) {
        return -10 + depth; // Player 1 (X) wins
    }
    if (checkWin(board, 2)) {
        return 10 - depth; // Player 2 (O) wins
    }
    if (checkDraw(board)) {
        return 0; // Draw
    }

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 9; i++) {
            if (!checkOccupied(board, i)) {
                playMove(board, player, i);
                int score = minimax(board, depth + 1, 0, player == 1 ? 2 : 1);
                board->xBoard &= ~(1 << i); // Undo move
                board->oBoard &= ~(1 << i); // Undo move
                bestScore = score > bestScore ? score : bestScore;
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 9; i++) {
            if (!checkOccupied(board, i)) {
                playMove(board, player, i);
                int score = minimax(board, depth + 1, 1, player == 1 ? 2 : 1);
                board->xBoard &= ~(1 << i); // Undo move
                board->oBoard &= ~(1 << i); // Undo move
                bestScore = score < bestScore ? score : bestScore;
            }
        }
        return bestScore;
    }
}