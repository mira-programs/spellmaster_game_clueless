#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "bot1.h"

int compareSpells(node *a, node *b, int spellsLeft[])
{ // compare spells; if a > b, returns 1, a < b, returns -1, else returns 0
    char* spellA = a->spell;
    char* spellB = b->spell;
    char ALastLetter = spellA[strlen(spellA) - 1];
    char BLastLetter = spellB[strlen(spellB) - 1];
    if(spellsLeft[ALastLetter - 'a'] < spellsLeft[BLastLetter - 'a']){
        return 1;
    }else return -1;
}

node *botMakeMoveHelper(node *root, char prev, int spellsLeft[], node *best)
{
    if (root != NULL)
    {
if (best->spell[0] != prev) best = root;
        // recursive call for left tree
        best = botMakeMoveHelper(root->left, prev, spellsLeft, best);
        
    
        if (root->spell[0] == prev && compareSpells(root, best, spellsLeft) > 0)
        {
            best = root;
        }

        // recurvise call for right tree
        best = botMakeMoveHelper(root->right, prev, spellsLeft, best);
    }
    return best;
}

node *botMakeMove(node *root, char prev, int spellsLeft[])
{
    return botMakeMoveHelper(root, prev, spellsLeft, root);
}

int main()
{
    int spellsLeft[26] = {0}; // creating and initiali zing array for spells count
    node *root = createAndPrintTree("spells.txt", spellsLeft);
    printf("\ncurrent spells count:\n");
    for (int i = 0; i < 26; i++)
    {
        printf("Count for '%c': %d\n", 'a' + i, spellsLeft[i]);
    }
    node *move = botMakeMove(root, 's', spellsLeft);
    printf("\nbot chose: %s\n", move->spell); 
    return 0;
}