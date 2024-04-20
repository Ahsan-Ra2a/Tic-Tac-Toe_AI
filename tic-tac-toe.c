#include "tic-tac-toe.h"

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
