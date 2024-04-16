#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#define BOARD_SIZE 3
#define EMPTY_CELL '.'

struct names_and_symbol {

    char str1[20];
    char str2[20];
    char symbol;
};

void board_print(char board[BOARD_SIZE][BOARD_SIZE]);
void reset_board(char board[BOARD_SIZE][BOARD_SIZE]);
int is_tie(char board[BOARD_SIZE][BOARD_SIZE]);
int win_check(char board[BOARD_SIZE][BOARD_SIZE], char symbol);
int player_turn(char board[BOARD_SIZE][BOARD_SIZE], char symbol);
int easy_mode(char board[BOARD_SIZE][BOARD_SIZE], char symbol);
void medium_mode(char board[BOARD_SIZE][BOARD_SIZE], char symbol,char p_symbol);
void hard_mode(char board[BOARD_SIZE][BOARD_SIZE], char symbol ,char p_symbol);
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int d ,int maxp, char p_symbol , char symbol);
int maximum(char board[BOARD_SIZE][BOARD_SIZE], char symbol, char p_symbol);
int minimum(char board[BOARD_SIZE][BOARD_SIZE], char p_symbol, char symbol);

#endif