#include <stdio.h>
#include <stdlib.h>

// Array
char square2[10] = {'N', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char square[10] = {'N', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// structure to store player names
struct name
{
    char player1[20];
    char player2[20];
};

void personalSleep(double a)
{
    for (double i = 0; i < a * 99999990; i++)
        ;
}

// function definitions
int result();
void board(char placeholder[10], struct name player); //
void lostAnalysis();

// using extern keyword to export this function
extern int multiPlay()
{
    int player = 1, check, choice;
    char mark;
    struct name p;
    system("clear");
    printf("To start the game enter the following:- \n\n ");
    printf("enter the name of player 1: ");
    scanf("%s", p.player1);
    printf("enter the name of player 2: ");
    scanf("%s", p.player2);
    do
    {
        system("clear");
        board(square2, p);
        player = (player % 2) ? 1 : 2;
        if (player == 1)
            printf("Move for %s: ", p.player1);
        else
            printf("Move for %s: ", p.player2);

        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O'; // changing player

        // marking index
        if (choice == 1 && square[1] == '1')
        {
            square[1] = mark;
            square2[1] = mark;
        }
        else if (choice == 2 && square[2] == '2')
        {
            square[2] = mark;
            square2[2] = mark;
        }
        else if (choice == 3 && square[3] == '3')
        {
            square[3] = mark;

            square2[3] = mark;
        }

        else if (choice == 4 && square[4] == '4')
        {
            square[4] = mark;
            square2[4] = mark;
        }

        else if (choice == 5 && square[5] == '5')
        {
            square[5] = mark;
            square2[5] = mark;
        }

        else if (choice == 6 && square[6] == '6')
        {
            square[6] = mark;
            square2[6] = mark;
        }

        else if (choice == 7 && square[7] == '7')
        {
            square[7] = mark;
            square2[7] = mark;
        }

        else if (choice == 8 && square[8] == '8')
        {
            square[8] = mark;
            square2[8] = mark;
        }

        else if (choice == 9 && square[9] == '9')
        {
            square[9] = mark;
            square2[9] = mark;
        }
        else
        {
            printf("Invalid move ");

            player--;
        }

        check = result(); // calling function to check if someone won
        player++;         // increasing player to change the chance of the player
    } while (check == -1);
    board(square2, p);

    // if someone won
    if (check == 1)
    {
        --player;
        if (player == 1)
        {
            printf("==>\a %s wins\a ", p.player1);
            lostAnalysis(p.player2);
        }
        else
        {
            printf("==>\a %s wins\a ", p.player2);
            lostAnalysis(p.player1);
        }
    }
    else
        printf("==>\aGame draw");

    return 0;
}

// a function just for fun
void lostAnalysis(char name[20])
{
    printf("\n\nAnalyzing why %s lost", name);
    for (int i = 0; i < 5; i++)
    {
        printf("\nLoading...");
        personalSleep(4);
    }
    printf("\nUnfortunately %s is a noob ", name);
}

// winning and drawing conditions
int result()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

// board
void board(char placeholder[10], struct name player)
{

    system("clear");
    printf("\n\n\tTic Tac Toe\n\n");

    printf(" %s (X)  -  %s (O)\n\n\n", player.player1, player.player2);

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", placeholder[1], placeholder[2], placeholder[3]);

    printf("_____|_____|_____\n");

    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", placeholder[4], placeholder[5], placeholder[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", placeholder[7], placeholder[8], placeholder[9]);

    printf("     |     |     \n\n");
}
