#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "runGame.h"
void theGame()
{
    printf("Welcome to the Spell Master game!\n"); // welcome message
    char player1[20];                              // to not repeat taking the first
    printf("Player, enter your name: ");
    scanf("%s", player1);
    // printing table of spells and creating the tree of spells
    printf("below is a list of spells you may use:\n");
    int spellsLeft[26] = {0}; // creating and initializing array for spells count
    node *spellsTreeRoot = createAndPrintTree("spells.txt", spellsLeft);
    int randNum = coinToss();
    printf("Do you want to play against 1.a friend or 2.a bot? ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        // inputting player 2 name
        char player2[20];
        printf("Player 2, enter your name: ");
        scanf("%s", player2);

        // tossing the coin to decide which player begins, and starting the game accordingly
        if (randNum == 0)
            runGame(player1, player2, spellsTreeRoot, spellsLeft);
        else
            runGame(player2, player1, spellsTreeRoot, spellsLeft);
    }
    else // in this version player one always starts
    {
        runGame2(player1, spellsTreeRoot, spellsLeft);
    }
    terminateTree(spellsTreeRoot);
}