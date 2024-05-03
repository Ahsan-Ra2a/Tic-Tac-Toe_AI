#include "tic-tac-toe.h"
#include <stdio.h>
#include <stdbool.h>

int main(void)
{

    char board[BOARD_SIZE][BOARD_SIZE] = 
    {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}
    };
    struct names_and_symbol player_1, player_2,AI;
    int choice;

    do 
    {
        printf("    TIC-TAC-TOE    \n");
        printf("-------------------\n");
        printf("| 1. ONE VS ONE   |\n");
        printf("| 2. VS AI        |\n");
        printf("-------------------\n");
        scanf("%d", &choice);
        getchar();

        switch (choice) 
        {
            case 1:
                board_print(board);
                printf("Enter Player 1 Name:");
                scanf(" %[^\n]s",&player_1.str1);
                getchar();
                printf("Select Symbol X or O:");
                scanf(" %c",&player_1.symbol);
                getchar();
                printf("Enter Player 2 Name:");
                scanf(" %[^\n]s",&player_2.str2);
                getchar();
                if (player_1.symbol == 'X') 
                {
                    player_2.symbol = 'O';
                }
                else 
                {
                    player_2.symbol = 'X';
                }
                while (true)
                {
                    printf("%s's Turn\n",player_1.str1);
                    player_turn(board,player_1.symbol);
                    board_print(board);
                    if (win_check(board,player_1.symbol)) 
                    {
                        printf("%s wins!\n",player_1.str1);
                        break;
                    }
                    if (is_tie(board)) 
                    {
                        printf("It's a tie!\n");
                        break;
                    }
                    printf("%s's Turn\n",player_2.str2);
                    player_turn(board,player_2.symbol);
                    board_print(board);
                    if (win_check(board,player_2.symbol)) 
                    {
                        printf("%s wins!\n",player_2.str2);
                        break;
                    }
                    if (is_tie(board)) 
                    {
                        printf("It's a tie!\n");
                        break;
                    }
                }
                break;
            case 2:
                printf("      MODES      \n");
                printf("-----------------\n");
                printf("|   1.EASY      |\n");
                printf("|   2.MEDIUM    |\n");
                printf("|   3.HARD      |\n");
                printf("-----------------\n");
                scanf("%d",&choice);
                board_print(board);
                printf("Enter Player Name\n");
                scanf(" %[^\n]s",&player_1.str1);
                getchar();
                printf("Select Symbol X or O:");
                scanf("%c",&player_1.symbol);

                if (player_1.symbol == 'X') 
                {
                    AI.symbol = 'O';
                }
                else 
                {
                    AI.symbol = 'X';
                }
                while (true)
                {
                    printf("%s's Turn\n",player_1.str1);
                    player_turn(board,player_1.symbol);
                    board_print(board);

                    if (win_check(board,player_1.symbol)) 
                    {
                        printf("%s wins!\n",player_1.str1);
                        break;
                    }

                    if (is_tie(board)) 
                    {
                        printf("It's a tie!\n");
                        break;
                    }

                    printf("AI's turn...\n");
                    switch (choice) 
                    {
                        case 1:
                            easy_mode(board,AI.symbol);
                            break;

                        case 2:
                            medium_mode(board,AI.symbol,player_1.symbol);
                            break;

                        case 3:
                            hard_mode(board,AI.symbol,player_1.symbol);
                            break;

                        default:
                            printf("Invalid choice!!\n");
                            break;
                    }
                    board_print(board);

                    if (win_check(board,AI.symbol)) 
                    {
                        printf("AI wins!\n");
                        break;
                    }

                    if (is_tie(board)) 
                    {
                        printf("It's a tie!\n");
                        break;
                    }
                }
                break;
            default:
                printf("Invalid Number!!\n");
                break;
        }
        reset_board(board);
        printf("Do you want to play again?\nEnter 1 for continue and 0 for exit:");
        scanf("%d",&choice);
        if (choice > 1 || choice < 0)
        {
            printf("Enter only 1 or 0:");
            scanf("%d",&choice);
        }

    } while (choice != 0);
}