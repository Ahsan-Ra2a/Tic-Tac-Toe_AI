#include "tic-tac-toe.h"
#include <stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
int easy_mode(char board[BOARD_SIZE][BOARD_SIZE], char symbol)
{
    srand(time(NULL));
    int x,y;
    do {

        x = rand() % 3;
        y = rand() % 3;

    } while (board[x][y] != EMPTY_CELL);

    board[x][y] = symbol;
}
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
// Board print function 
void board_print(char board[BOARD_SIZE][BOARD_SIZE])
{
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
    printf("\n");
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

int player_turn(char board[BOARD_SIZE][BOARD_SIZE], char symbol)
{
    int player_row,player_colm;
    printf("Enter Row (0, 1 or 2):");
    scanf("%d",&player_row);
    printf("Enter column (0, 1 or 2):");
    scanf("%d",&player_colm);

    if ((player_row > 2 || player_row < 0) || (player_colm > 2 || player_colm < 0))
    {
        printf("Out of bound Enter only (0,1,2)!!\n");
        player_turn(board,symbol);
    }
    else if (board[player_row][player_colm] == EMPTY_CELL) 
    {
        board[player_row][player_colm] = symbol;
    } 
    else 
    {
        printf("Cell already taken. Try again.\n");
        player_turn(board,symbol);
    }
}
//end of player turn function
