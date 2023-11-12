#include "hardBot.h"
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

/*
precondition: node pointer to the node we wish to compare, an integer value and the spellsLeft array.
postcondition: will return 1 if the amount of spells left starting with the last letter of the spell in the given node is less than the bar. Otherwise it will return -1.

Test cases: 
1. The number of spells left is less than then bar: the function returns 1.
2. The number of spells is equal to the bar: the function returns 1.
3. The number of spells is larger than the bar: the function returns -1.
*/
int compareBarSpell(node *a, int bar, int spellsLeft[])
{ // compare spells; if a > b, returns 1, a < b, returns -1, else returns 0
    char* spellA = a->spell;
    char ALastLetter = spellA[strlen(spellA) - 1];

    if(spellsLeft[ALastLetter - 'a'] <= bar){       //compare the amount of spells left to the bar.
        return 1;
    }else //if (spellsLeft[ALastLetter - 'a'] > bar)
        return -1;
}

/*
precondition: node pointer, the last character of the previously used spell, an integer (the bar), an array of integers and a node pointer to the best choice to make so far.
postcondition: It'll return a node pointer to the best spell the bot can cast to win if such a move exists.

Test cases:
1. If there are no spells that start with the last letter of the opponent's spell: uses wingardiumLeviosa.
2. If there all spells starting with the previous letter were used: uses a used spell.
3. If there are spells to be cast: sometimes it chooses winning spells (when possible), other times chooses non-winning spells (even when there's a winning alternative).
*/
node *ModerateBotMoveHelper(node *root, char prev, int bar, int spellsLeft[], node *best)
{
    if (root != NULL)
    {
if (best->spell[0] != prev) best = root;
        // recursive call for left tree
        best = ModerateBotMoveHelper(root->left, prev, bar, spellsLeft, best);
        
    
        if (root->spell[0] == prev && compareBarSpell(root, bar, spellsLeft) > 0)
        {
            best = root;
            return best;        //we don't want to check further; return the first one that is below the bar.
        }

        // recurvise call for right tree
        best = ModerateBotMoveHelper(root->right, prev, bar, spellsLeft, best);
    }
    return best;
}

/*
precondition: an array of integers.
postcondition: the total amount of spells that haven't yet been used.

Test cases:
1. Before using any spell: gives back the total amount of spells originally (here 78).
2. After having used spells: gives back amount of spells left (unused).
*/
int totalSpellsLeft(int spellsLeft[]) {
    int total = 0;
    for (int i = 0; i < ARRAY_SIZE(spellsLeft); i++) {
        total += spellsLeft[i];
    }

    return total;
}

/*
precondition: node pointer to the root, a char (last letter of the spell used by the opponent), and an array of integers that stores how many spells are left for each letter.
postcondition: gives back a node pointer to the node containing the best spell the bot can cast in its situation.
*/
node *ModerateBotMove(node *root, char prev, int spellsLeft[])
{
    int total =  totalSpellsLeft(spellsLeft);
    int bar = total % randomNum(0, 26);     //bar will be like a fictional bar which will be used as a comparison tool: we want to choose a spell that has fewer than "bar" spells.

    return ModerateBotMoveHelper(root, prev, bar, spellsLeft, root);
}