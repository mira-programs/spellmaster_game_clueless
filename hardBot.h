#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "easyBot.h"

/*
precondition: two node pointers to two different possible spells, an array of integers (stores the number of spells left for each letter).
postcondition: will return which spell is the better choice out of the two: if it's the first one (a), it will return 1 and if it's b it'll return -1. In the case where they're both the same, check the used variables of each: if both were used or none were used give back the first one, if one of them wasn't used give back the non-used one.
*/
int compareSpells(node *a, node *b, int spellsLeft[])
{ // compare spells; if a > b, returns 1, a < b, returns -1, else returns 0
    char *spellA = a->spell;
    char *spellB = b->spell;
    char ALastLetter = spellA[strlen(spellA) - 1];
    char BLastLetter = spellB[strlen(spellB) - 1];
    if (spellsLeft[ALastLetter - 'a'] < spellsLeft[BLastLetter - 'a'])
    {
        return 1;
    }
    else if (spellsLeft[ALastLetter - 'a'] > spellsLeft[BLastLetter - 'a'])
        return -1;
    else
        return (a->used > b->used) ? -1 : 1; // if a is used, return b, else return a
}

/*
precondition: node pointer to the root, character (last letter of the opponent's spell), and array of integers (that sotres the number of spells left with each letter) and another node pointer to the best choice so far.
postcondition: returns the best choice out of all the possible spells, and if such a choice doesn't exist (no matter what you choose you loose) it gives back a non-valid spell.
*/
node *MediumBotMoveHelper(node *root, char prev, int spellsLeft[], node *best)
{
    if (root != NULL)
    {
        if (prev != ' ' && best->spell[0] != prev)
            best = root;
        // recursive call for left tree
        best = MediumBotMoveHelper(root->left, prev, spellsLeft, best);

        // comparing current root to last updated best choice of spell
        if (root->spell[0] == prev && compareSpells(root, best, spellsLeft) > 0)
        {
            best = root; // update best if root is better choice
        }
        else if (prev == ' ')
        { // bot is making first move, so pick spell with least counterspells
            if (compareSpells(root, best, spellsLeft) > 0)
            {
                best = root;
            }
        }
        // recurvise call for right tree
        best = MediumBotMoveHelper(root->right, prev, spellsLeft, best);
    }
    return best;
}

/*
precondition: node pointer to the root of the BST, a character (last letter of the opponent's spell) and an array of integers (that stores the number of spells left for each letter).
postcondition: returns the best spell to cast if there is one, if not returns a non-valid spell.
*/
node *MediumBotMove(node *root, char prev, int spellsLeft[])
{
    return MediumBotMoveHelper(root, prev, spellsLeft, root);
}