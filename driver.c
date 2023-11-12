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

    // printing table of spells and creating the tree of spells
    printf("below is a list of spells you may use:\n");
    int spellsLeft [26] = {0}; //creating and initializing array for spells count
    node *spellsTreeRoot = createAndPrintTree("spells.txt", spellsLeft);

//just for testing
printf("\ncurrent spells count:\n");
for (int i = 0; i < 26; i++) {
    printf("Count for '%c': %d\n", 'a' + i, spellsLeft[i]);
}

    // tossing the coin to decide which player begins, and starting the game accordingly
    int randNum = coinToss();
    if (randNum == 0)
        runGame(player1, player2, spellsTreeRoot, spellsLeft);
    else
        runGame(player2, player1, spellsTreeRoot, spellsLeft);

//just for testing
printf("\nend of game spells count:\n");
for (int i = 0; i < 26; i++) {
    printf("Count for '%c': %d\n", 'a' + i, spellsLeft[i]);
}

    return 0;
}
