#include "ticTacToe.h"

int computerMove(GameBoard *board, int computerPlayer){
    
    int position = findBestMove(board, computerPlayer);
    if (position < 0 || position > 8) {
        return 1; // No valid moves available
    }

    if (playMove(board, computerPlayer, position)) {
        return 1; // Error making move
    }

    return 0; // Move made successfully
}


int main(int argc, char *argv[]) {

    // the board
    GameBoard board;
    board.xBoard = 0;
    board.oBoard = 0;

    int player = 1;
    int position = 0;
    
    int computerMode = 0; // 0 for two players, 1 for player vs computer
    int computerPlayer = 2; // Default computer player is 2 (O)

    printf("Select game mode:\n");
    printf("0: Two players\n");
    printf("1: Player vs Computer\n");
    if(scanf("%d", &computerMode) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    if(computerMode == 1) {
        printf("Select computer player (1 for X, 2 for O): ");
        if(scanf("%d", &computerPlayer) != 1) {
            printf("Error reading input.\n");
            return 1;
        }
        if(computerPlayer != 1 && computerPlayer != 2) {
            printf("Invalid selection. Defaulting to player 2 (O).\n");
            computerPlayer = 2;
        }
    }

    while (1) {
        
        printBoard(&board);

        if (computerMode == 1 && player == computerPlayer){
            printf("It's the computer's turn (Player %d).\n", computerPlayer);

            if (computerMove(&board, computerPlayer)) {
                printf("Error making computer move. Please try again.\n");
                continue;
            }
        } else {
            printf("Player %d's turn. Enter position (1-9): ", player);

            if (scanf("%d", &position) != 1) {
                printf("Error reading input.\n");
                break;
            }
            position--; // Convert to 0-based index
    
            if (position < 0 || position > 8) {
                printf("Invalid position. Please enter a number between 1 and 9.\n");
                continue;
            }
    
            if (playMove(&board, player, position)){
                printf("Error making move. Please try again.\n");
                continue;
            }
        }

        // Check for win or draw
        if (checkWin(&board, player)) {
            printf("Player %d wins!\n", player);
            printBoard(&board);
            break;
        }

        if (checkDraw(&board)) {
            printf("It's a draw!\n");
            printBoard(&board);
            break;
        }

        // Switch players
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
