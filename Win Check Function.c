
#include <stdbool.h>

// using bool.h library because i have use true and false here
//board will be of 3x3

// Function to check if a player has won
bool win_check(char board[BOARD_SIZE][BOARD_SIZE], char symbol) {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        // Check if the player is wining by row
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true; 
        }
        // Check if player is wining by column
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true; 
        }
    }
    // Check if the player is wining by diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true; 
    }
    return false; //return false if no one wins 

}
