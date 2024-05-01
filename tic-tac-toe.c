#include "tic-tac-toe.h"
#include <stdio.h>
#include<stdbool.h>

void medium_mode(char board[BOARD_SIZE][BOARD_SIZE], char symbol, char p_symbol)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY_CELL)
            {
                board[i][j] = symbol;
                if (win_check(board, symbol))
                    return;
                board[i][j] = EMPTY_CELL; 
            }
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY_CELL)
            {
                board[i][j] = p_symbol;
                if (win_check(board, p_symbol))
                {
                    board[i][j] = symbol;
                    return;
                }
                board[i][j] = EMPTY_CELL;
            }
        }
    } 
    easy_mode(board, symbol);
}

void hard_mode(char board[BOARD_SIZE][BOARD_SIZE], char symbol , char p_symbol) 
{
    int best_value = -1;
    int best_move_row = -1;
    int best_move_colm = -1;

    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            if (board[i][j] == EMPTY_CELL) 
            {
                board[i][j] = symbol;
                int move = minimax(board,0, 0,p_symbol,symbol);
                board[i][j] = EMPTY_CELL;
                if (move > best_value) 
                {
                    best_value = move;
                    best_move_row = i;
                    best_move_colm = j;
                }
            }
        }
    }

    board[best_move_row][best_move_colm] = symbol;
}

int minimax(char board[BOARD_SIZE][BOARD_SIZE],int d, int maxp , char p_symbol, char symbol) 
{
    if (win_check(board,p_symbol)) 
    {
        return -1;
    }
    else if (win_check(board,symbol)) 
    {
        return 1;
    } 
    else if (is_tie(board)) 
    {
        return 0;
    }

    if (maxp) 
    {
        return maximum(board,symbol,p_symbol);
    } 
    else 
    {
        return minimum(board,p_symbol,symbol);
    }
}
int maximum(char board[BOARD_SIZE][BOARD_SIZE],char symbol,char p_symbol) {
    int max_val = -1;

    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            if (board[i][j] == EMPTY_CELL) 
            {
                board[i][j] = symbol;
                int evaluate = minimax(board,0, 0,p_symbol,symbol);
                board[i][j] = EMPTY_CELL;
                if (evaluate > max_val) 
                {
                    max_val = evaluate;
                }
            }
        }
    }

    return max_val;
}
int minimum(char board[BOARD_SIZE][BOARD_SIZE], char p_symbol,char symbol) {
    int min_val = 1;

    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            if (board[i][j] == EMPTY_CELL) 
            {
                board[i][j] = p_symbol ;
                int evaluate = minimax(board,0, 1,p_symbol,symbol);
                board[i][j] = EMPTY_CELL;
                if (evaluate < min_val) 
                {
                    min_val = evaluate;
                }
            }
        }
    }

    return min_val;
}
//win check function by urooj baloch

bool win_check(char board[BOARD_SIZE][BOARD_SIZE], char symbol) {
    
    for (int i = 0; i < BOARD_SIZE; ++i) {
        // Check if the player is wining by row
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true; 
        }
       
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true; 
        }
    }
    
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true; 
    }
    return false; 

}//end of win check function

void board_print(char board[BOARD_SIZE][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE+1; i++)
    {
		if(i % 2 == 0 ) 
        {
			printf("\n---|---|---\n");
		}
		else 
        {
			printf(" %c | %c | %c",board[i][0],board[i][1],board[i][2]);
		}
	}
}
void reset_board(char board[BOARD_SIZE][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++)
 	{
		for(int j = 0; j < BOARD_SIZE; j++)
		{
 			board[i][j]=EMPTY_CELL;
		}
	}
}
//tie function by urooj baloch

bool is_tie(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '.')
                return false; 
        }
    }
    return true; 
}
//end of tie function

//player turn function by urooj baloch

int player_turn(char board[BOARD_SIZE][BOARD_SIZE], char symbol) {
    int row, col;
    printf("Enter your move (row column): ");
    scanf("%d %d", &row, &col);

    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        printf("Invalid move. Please enter row and column numbers between 0 to 2 i.e (0,1,2)");
        return 0; 
    }

   
    if (board[row][col] != '.') {
        printf("cell is already occupied. Please choose another\n");
        return 0; 
    }

   
    board[row][col] = symbol;
    return 1; 
}

//end of player turn function
