#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "easyBot.h"

int compareSpells(node *a, node *b, int spellsLeft[])
{ // compare spells; if a > b, returns 1, a < b, returns -1, else returns 0
    char* spellA = a->spell;
    char* spellB = b->spell;
    char ALastLetter = spellA[strlen(spellA) - 1];
    char BLastLetter = spellB[strlen(spellB) - 1];
    if(spellsLeft[ALastLetter - 'a'] < spellsLeft[BLastLetter - 'a']){
        return 1;
    }else if (spellsLeft[ALastLetter - 'a'] > spellsLeft[BLastLetter - 'a'])
        return -1;
    else return (a->used > b->used) ? -1 : 1; //if a is used, return b, else return a 
}

node *MediumBotMoveHelper(node *root, char prev, int spellsLeft[], node *best)
{
    if (root != NULL)
    {
if (best->spell[0] != prev) best = root;
        // recursive call for left tree
        best = MediumBotMoveHelper(root->left, prev, spellsLeft, best);
        
    
        if (root->spell[0] == prev && compareSpells(root, best, spellsLeft) > 0)
        {
            best = root;
        }

        // recurvise call for right tree
        best = MediumBotMoveHelper(root->right, prev, spellsLeft, best);
    }
    return best;
}

node *MediumBotMove(node *root, char prev, int spellsLeft[])
{
    return MediumBotMoveHelper(root, prev, spellsLeft, root);
}