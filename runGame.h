//#include "bot2.h"
#include "bot1_5.h"

/*
Precondition: two strings of the players' names, a node pointer to the BST root and array of the number of spells left depending on the letter of size 26
Postcondition: return 0 if player 1 wins and 1 if player 2 wins
*/
int runGame(char player1[], char player2[], node *spellsTreeRoot, int spellsLeft[])
{

    char prev = ' ';
    char move[50];

    // starting the game with first player
    printf("\n%s starts!\nEnter your first move: ", player1);
    scanf("%s", move);
    int result1 = checkMove(spellsTreeRoot, prev, move, spellsLeft);
    // int result1 = checkMove(spell, row, prev, move);

    // continuing the game with second player
    while (result1 == 1)
    {
        printf("%s's turn!\n", player2);
        prev = move[strlen(move) - 1];
        printf("%s! Enter your next move: ", player2);
        scanf("%s", move);
        int result2 = checkMove(spellsTreeRoot, prev, move, spellsLeft);
        prev = move[strlen(move) - 1];
        if (result2 == -1)
        {
            printf("%s loses! %s wins! congratulations!", player2, player1);
            return 0; // player 1 wins
        }
        else
        {
            printf("%s!\nEnter your next move: ", player1);
            scanf("%s", move);
            result1 = checkMove(spellsTreeRoot, prev, move, spellsLeft);
            prev = move[strlen(move) - 1];
        }
    }
    printf("%s loses! %s wins! congratulations!", player1, player2); // player 2 wins
    return 1;
}
/*
Precondition: one string of the player's name, a node pointer to the BST root and array of the number of spells left depending on the letter of size 26
Postcondition: returns 0 if player 1 wins and 1 if bot wins
*/
int runGame2(char player1[], node *spellsTreeRoot, int spellsLeft[])
{ // modified version with the bot
    char prev = ' ';
    char move[50];
    printf("%s\nEnter your first move: ", player1);
    scanf("%s", move);
    int result1 = checkMove(spellsTreeRoot, prev, move, spellsLeft);
    while (result1 == 1)
    {
        printf("bot's turn!\n");
        prev = move[strlen(move) - 1];

        //HERE IS WHERE THE BOT MAKES A MOVE

        //WE SHOULD ADD THE THREE DIFFICULTIES AS OPTIONS MAYBE THIS CODE? (BEFORE "printf("bot's tur!")"):
        /*
        printf(Please choose difficulty level: \n1. Easy \n2. Moderate \n3. Hard);
        int difficuty;
        scanf("%d", &difficulty);

        if (difficulty == 1) {
            BOT1 
        }
        else if (difficulty == 2) {
            BOT1_5
        }
        else if (diffculty == 3) {
            BOT2
        }
        else {
            printf("Invalid difficulty. Please choose either 1 (easy), 2 (moderate) or 3 (hard)");
        }
        */

        //node *spell = modifiedSearch(spellsTreeRoot, prev, spellsLeft); EASY MODE
        //node *spell = MediumBotMove(spellsTreeRoot, prev, spellsLeft); //medium mode (now hard mode)
        node *spell = ModerateBotMove(spellsTreeRoot, prev, spellsLeft); //moderate
        printf("bot chose: %s\n", spell->spell);


        int result2 = checkMove(spellsTreeRoot, prev, spell->spell, spellsLeft);
        prev = spell->spell[strlen(spell->spell) - 1];

        if (result2 == -1)
        {
            printf("bot loses! %s wins! congratulations!", player1);
            return 0; // player 1 wins
        }
        else
        {
            printf("%s!\nEnter your next move: ", player1);
            scanf("%s", move);
            result1 = checkMove(spellsTreeRoot, prev, move, spellsLeft);
            prev = move[strlen(move) - 1];
        }
    }
    printf("%s loses! bot wins! congratulations!", player1);
    return 1;
}
