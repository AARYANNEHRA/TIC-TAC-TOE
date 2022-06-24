#include <stdio.h>
#include <stdlib.h>
#include "multiplayer.h"  // including external file
#include "singleplayer.h" // including external file
int main()
{
    int type;
    char c;
a:
    system("cls");
    printf("          _       _   _         _      _ _  _\n");
    printf(" \\    /  |_  |   |   | | |\\/|  |_  __   |  | |\n");
    printf("  \\/\\/   |_  |_  |_  |_| |  |  |_       |  |_|\n\n");
    printf("******\n");
    printf(" _ _ _ _   _      _ _  _   _     _ _  _   _\n");
    printf("  |   |   |    _   |  |_| |    _  |  | | |_\n");
    printf("  |  _|_  |_       |  | | |_      |  |_| |_\n\n");
    printf("*******");
    printf("");

    printf("\n\t\t Single Player - 1  || Multiplayer - 2 || exit-3\n\n");
    printf("\t\t\t        Enter your choice: ");
    scanf("%d", &type);
    switch (type)
    {
    case 1:
    b:
        printf("\n\t\tDo you want to proceed the game in single player mode?(Y/N) ");
        scanf(" %c", &c);
        if (c == 'y' || c == 'Y')
            singlePlay(); // calling function from singplayer.h file
        else
            goto a;
        break;
    case 2:
        printf("\n\t\tDo you want to proceed the game in multiplayer mode?(Y/N)");
        scanf(" %c", &c);
        if (c == 'y' || c == 'Y')
            multiPlay(); // calling function from multiplayer.h file
        else
            goto a;
    case 3:
        exit(0);

    default:
        printf("\nInvalid move");
        personalSleep(2);
        goto a;
    }
    return 0;
}
