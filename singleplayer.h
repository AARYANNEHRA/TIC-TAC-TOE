#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool validPos[10] = {false, true, true, true, true, true, true, true, true, true};
char user = 'O', computer = 'X';

void boardSingle(char placeholder[3][3], char user, char computer);
void startGame(char game[3][3], const char turn);
int gameStatus();
int isComplete();
int calcMove();

// using extern keyword to export function
extern int singlePlay()
{
    // A two-dimensional array depicting the game.
    char game[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char choice;
    system("clear");
    // Asks user for a valid input.

    do
    {
        printf("Choose your sign X or O ?\n");
        scanf(" %c", &choice);

    } while (choice != 'X' && choice != 'O' && choice != 'x' && choice != 'o');

    if (choice == 'x' || choice == 'X')
    {
        user = 'X';
        computer = 'O';
    }

    startGame(game, user);
    return 0;
}

void startGame(char game[3][3], const char turn)
{
    system("clear");
    int i, j;
    int pos;
    boardSingle(game, user, computer);
    srand((unsigned)time(NULL));
    if (turn == user)
    {
        // asks the user for a valid input.
        do
        {
            printf("Your turn : ");
            scanf("%d", &pos);

        } while ((pos > 9 || pos < 1) || !validPos[pos]);
    }

    else
    {
        do
        {
            // calculates a good and valid move for the computer.
            pos = rand() % 10;
        } while ((pos > 9 || pos < 1) || !validPos[pos]);
        pos = calcMove(game, pos);
    }

    // makes the position chosen invalid.
    validPos[pos] = false;

    // Assigns 'X' or 'O' to the chosen position.
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (game[i][j] - '0' == pos)
                game[i][j] = turn;

    // prints the game onto the screen.
    boardSingle(game, user, computer);

    // checks if the player or computer has won or not.
    if (gameStatus(game))
    {
        if (turn == user)
            printf("You Win !\n\n");

        else
            printf("Computer Wins !\n\n");

        return;
    }

    // checks if there are any further moves possible.
    // also acts as the base case for the game to end.
    if (isComplete(game))
    {
        printf("Game Draw!\nNo More Possible Moves\n\n");
        return;
    }

    // recursive call to continue the game.
    if (turn == user)
    {
        startGame(game, computer);
    }

    if (turn == computer)
    {
        startGame(game, user);
    }
}

int gameStatus(char placeholder[3][3])
{
    if (placeholder[0][0] == placeholder[0][1] && placeholder[0][1] == placeholder[0][2])
        return true;

    else if (placeholder[1][0] == placeholder[1][1] && placeholder[1][1] == placeholder[1][2])
        return true;

    else if (placeholder[2][0] == placeholder[2][1] && placeholder[2][1] == placeholder[2][2])
        return true;

    else if (placeholder[0][0] == placeholder[1][0] && placeholder[1][0] == placeholder[2][0])
        return true;

    else if (placeholder[0][1] == placeholder[1][1] && placeholder[1][1] == placeholder[2][1])
        return true;

    else if (placeholder[0][2] == placeholder[1][2] && placeholder[1][2] == placeholder[2][2])
        return true;

    else if (placeholder[0][0] == placeholder[1][1] && placeholder[1][1] == placeholder[2][2])
        return true;

    else if (placeholder[0][2] == placeholder[1][1] && placeholder[1][1] == placeholder[2][0])
        return true;
    else
        return 0;
}

int isComplete(char placeholder[3][3])
{
    if (placeholder[0][0] != '1' && placeholder[0][1] != '2' && placeholder[0][2] != '3' &&
        placeholder[1][0] != '4' && placeholder[1][1] != '5' && placeholder[1][2] != '6' && placeholder[2][0] != '7' && placeholder[2][1] != '8' && placeholder[2][2] != '9')
        return 1;
    else
        return 0;
}

int calcMove(char game[][3], int pos)
{
    int i, j;
    int move = 0;

    // If there is any move along a row that is a winning move for the computer
    // then take it or block the winning move of the user along a row.
    for (i = 0; i < 3; i++)
    {
        if (game[i][0] == game[i][1] && validPos[game[i][2] - '0'])
        {
            move = game[i][2] - '0';
            if (game[i][0] == computer)
                return move;
        }

        if (game[i][0] == game[i][2] && validPos[game[i][1] - '0'])
        {
            move = game[i][1] - '0';
            if (game[i][0] == computer)
                return move;
        }

        if (game[i][1] == game[i][2] && validPos[game[i][0] - '0'])
        {
            move = game[i][0] - '0';
            if (game[i][1] == computer)
                return move;
        }
    }

    // If there is any move along a column that is a winning move for the computer
    // then take it or block the winning move of the user along a column.
    for (j = 0; j < 3; j++)
    {
        if (game[0][j] == game[1][j] && validPos[game[2][j] - '0'])
        {
            move = game[2][j] - '0';
            if (game[0][j] == computer)

                return move;
        }

        if (game[1][j] == game[2][j] && validPos[game[0][j] - '0'])
        {
            move = game[0][j] - '0';
            if (game[1][j] == computer)
                return move;
        }

        if (game[0][j] == game[2][j] && validPos[game[1][j] - '0'])
        {
            move = game[1][j] - '0';
            if (game[0][j] == computer)
                return move;
        }
    }
    // checks for the winning move along the right diagonal.
    // preference is given to the winning move for the computer.
    if (game[0][0] == game[1][1] && validPos[game[2][2] - '0'])
    {
        move = game[2][2] - '0';
        if (game[0][0] == computer)
            return move;
    }

    if (game[0][0] == game[2][2] && validPos[game[1][1] - '0'])
    {
        move = game[1][1] - '0';
        if (game[0][0] == computer)
            return move;
    }

    if (game[1][1] == game[2][2] && validPos[game[0][0] - '0'])
    {
        move = game[0][0] - '0';
        if (game[1][1] == computer)
            return move;
    }

    // checks for the winning move along the left diagonal.
    // preference is given to the winning move for the computer.
    if (game[0][2] == game[1][1] && validPos[game[2][0] - '0'])
    {

        move = game[2][0] - '0';
        if (game[0][2] == computer)
            return move;
    }

    if (game[0][2] == game[2][0] && validPos[game[1][1] - '0'])
    {
        move = game[1][1] - '0';
        if (game[0][2] == computer)
            return move;
    }

    if (game[1][1] == game[2][0] && validPos[game[0][2] - '0'])
    {
        move = game[0][2] - '0';
        if (game[1][1] == computer)
            return move;
    }

    // if there was any such move in which either the player or
    // the computer would win, then return it.
    if (move != 0)
        return move;

    // if there was no such move, then select any of the corners
    // or the center randomly.
    switch (rand() % 4)
    {

    case 1:
        if (validPos[7] && validPos[3])
            return 7;

    case 2:
        if (validPos[3] && validPos[7])
            return 3;

    case 3:
        if (validPos[1] && validPos[9])
            return 1;

    case 4:
        if (validPos[5])
            return 5;

    default:
        return pos;
    }
}

void boardSingle(char placeholder[3][3], char user, char computer)
{
    printf("\n\n\tTic Tac Toe\n\n");

    printf("User  (%c)  -  Computer (%c)\n\n\n", user, computer);

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", placeholder[0][0], placeholder[0][1], placeholder[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", placeholder[1][0], placeholder[1][1], placeholder[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", placeholder[2][0], placeholder[2][1], placeholder[2][2]);

    printf("     |     |     \n\n");
}
