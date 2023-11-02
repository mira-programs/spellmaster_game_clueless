/*
clueless ~ Mira Hussein, Haya Mouneimne, Mariam Sonji
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "runGame.h"
#include "coinToss.h"
int main()
{

    printf("Welcome to the Spell Master game!\n"); // welcome message

    // inputting player names
    char player1[20];
    char player2[20];
    printf("Player 1, enter your name: ");
    scanf("%s", player1);
    printf("Player 2, enter your name: ");
    scanf("%s", player2);

    // printing table of spells
    printf("below is a list of spells you may use:\n");
    int row = getRowNumber("spells.txt");
    elements *spell = createAndFill("spells.txt");
    printArray(spell, row, 5);

    // tossing the coin to decide which player begins
    int randNum = coinToss();
    if (randNum == 0)
    {
        runGame(player1, player2, spell, row);
    }
    else
    {
        runGame(player2, player1, spell, row);
    }

    return 0;
}