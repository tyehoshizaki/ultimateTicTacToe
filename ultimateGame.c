#include "ultimateGame.h"

int playUltimateGame(){

    UltimateGameBoard board;
    board.xBoard = 0;
    board.oBoard = 0;
    board.fullBoards = 0;
    board.nextBoard = -1;

    for(int i = 0; i < 9; i++) {
        board.boards[i].xBoard = 0;
        board.boards[i].oBoard = 0;
    }

    printf("Welcome to Ultimate Tic Tac Toe!\n");

    printBoardUlt(&board);

    int player = 1;
    int position, boardIndex;
    
    printf("Player 1 is X and Player 2 is O.\n");
    
    while(1){

        printBoardUlt(&board);

        int ifWon = 0;
        
        printf("Player %d's turn.\n", player);

        if (board.nextBoard != -1) {
            printf("You must play in board %d.\n", board.nextBoard + 1);
            boardIndex = board.nextBoard;
        } else {
            printf("You can play in any board. Pick a board (1-9): ");
            if(scanf("%d", &boardIndex) != 1) {
                printf("Invalid input. Please enter a number.\n");
                continue;
            }
            boardIndex--;
            if (boardIndex < 0 || boardIndex > 8) {
                printf("Invalid board index. Please enter a number between 1 and 9.\n");
                continue;
            }
            if(checkIfBoardFinished(&board, boardIndex)) {
                printf("Board %d is already finished. Please choose another board.\n", boardIndex + 1);
                continue;
            }
        }


        printf("Enter position (1-9) in board %d: ", boardIndex + 1);
        if(scanf("%d", &position) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        position--;
        if (position < 0 || position > 8) {
            printf("Invalid position. Please enter a number between 1 and 9.\n");
            continue;
        }

        if (playMoveUlt(&board, player, boardIndex, position)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (checkWinner(&board.boards[boardIndex], player)){
            printf("Player %d wins board %d!\n", player, boardIndex + 1);
            playerWonBoard(&board, player, boardIndex);
            ifWon = 1;
            
        }

        if (!ifWon && checkDraw(&board.boards[boardIndex])) {
            printf("Board %d is full!\n", boardIndex + 1);
            boardIsFull(&board, boardIndex);
        }

        if (checkWinnerUlt(&board, player)) {
            printf("Player %d wins the game!\n", player);
            break;
        }

        if (checkDrawUlt(&board)) {
            printf("The game is a draw!\n");
            break;
        }

        changeNextBoard(&board, position);

        player = (player == 1) ? 2 : 1;

    }

    printBoardUlt(&board);

    return 0;
}