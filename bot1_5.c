#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "bot1.h"

int compareSpells(node *a, int bar, int spellsLeft[])
{ // compare spells; if a > b, returns 1, a < b, returns -1, else returns 0
    char* spellA = a->spell;
    char ALastLetter = spellA[strlen(spellA) - 1];

    if(spellsLeft[ALastLetter - 'a'] <= bar){       //compare the amount of spells left to the bar.
        return 1;
    }else //if (spellsLeft[ALastLetter - 'a'] > bar)
        return -1;
}

node *MediumBotMoveHelper(node *root, char prev, int bar, int spellsLeft[], node *best)
{
    if (root != NULL)
    {
if (best->spell[0] != prev) best = root;
        // recursive call for left tree
        best = MediumBotMoveHelper(root->left, prev, bar, spellsLeft, best);
        
    
        if (root->spell[0] == prev && compareSpells(root, bar, spellsLeft) > 0)
        {
            best = root;
        }

        // recurvise call for right tree
        best = MediumBotMoveHelper(root->right, prev, bar, spellsLeft, best);
    }
    return best;
}

int totalSpellsLeft(int spellsLeft[]) {
    int total = 0;
    for (int i = 0; i < sizeof(spellsLeft); i++) {
        total += spellsLeft[i];
    }

    return total;
}

node *MediumBotMove(node *root, char prev, int spellsLeft[])
{
    int total =  totalSpellsLeft(spellsLeft);
    int bar = total % randomNum(0, 26);

    return MediumBotMoveHelper(root, prev, bar, spellsLeft, root);
}