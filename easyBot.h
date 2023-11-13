#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "freeTree.h"
#include "coinToss.h"

/*
precondition: an array of integers.
postcondition: the total amount of spells that haven't yet been used.

Test cases:
1. Before using any spell: gives back the total amount of spells originally (here 78).
2. After having used spells: gives back amount of spells left (unused).
*/
int totalSpellsLeft(int spellsLeft[]) {
    int total = 0;
    for (int i = 0; i < 26; i++) { //26 letters in the alphabet, size of array is 26
        total += spellsLeft[i];
    }
    return total;
}

/*
Precondition: int min and int max with min < max and both < number of nodes in BST
Postcondition:returns random number, used for modified search

Test cases:
1. Run the function: gives a random number between the maximum and minimum.
(To make sure it works we ran it many times).
*/
int randomNum(int min, int max)
{
    int random_number = rand() % (max - min + 1) + min; //random number between min and max inclusive
    return random_number;
}

/*
Precondition: pointer to a node in BST, character prev not equal to null and array of the number of spells left depending on the letter of size 26
Postcondition: returns a node pointer to a spell in the tree.

Test cases:
1. Given a null node pointer: prints error message.
2. Given a tree containing only one node: gives back the root.
3. Given a tree containing more than one node: 
    a. If there exists a spell starting with the letter we want: returns a valid spell (except when prev = 's').
    b. If there isn't a single spell that matches the requirements: returns a random spell.
*/
node *modifiedSearch(node *root, char prev, int spellsLeft[])
{ 

    if (root == NULL)
        return NULL; // should never be reached, possible error, but included this line for ensuring
    if (root->left == NULL && root->right == NULL) //if no children left, return root
        return root;

    //if bot is making the first move, the 'prev' will be ' ' a white space
    if(prev == ' '){ //in this case, the bot can just choose a random spell
        int num;
        num = randomNum(1, totalSpellsLeft(spellsLeft)); // random num to decide how far to go
        for (int i = 1; i <= num; i++)
        {
            if (root->left == NULL && root->right == NULL)
                break; // nowhere else to go, pick the root spell
            if (root->left == NULL)
                root = root->right; // can't go left, go right
            else if (root->right == NULL)
                root = root->left; // can't go right, go left
            else
            { // can go either way, random choice
                if (coinToss() == 0)
                {
                    root = root->right;
                }
                else
                {
                    root = root->left;
                }
            }
        }
        return root;
    }

    if (root->spell[0] == prev) //reached median of possible valid spells
    {
        int randnum;
        randnum = randomNum(1, spellsLeft[prev - 'a']); // random num to decide which of the spells to use
        for (int i = 1; i <= randnum; i++)
        {
            if (root->left == NULL && root->right == NULL)
                break; // nowhere else to go, pick the root spell
            if (root->left == NULL)
                root = root->right; // can't go left, go right
            else if (root->right == NULL)
                root = root->left; // can't go right, go left
            else
            { // can go either way, random choice
                if (coinToss() == 0)
                {
                    root = root->right;
                }
                else
                {
                    root = root->left;
                }
            }
        }
        return root;
    }
    else if (root->spell[0] > prev) //case to go left
        return modifiedSearch(root->left, prev, spellsLeft);
    else //case to go right
        return modifiedSearch(root->right, prev, spellsLeft);
}
