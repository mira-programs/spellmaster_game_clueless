#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "freeTree.h"
#include "coinToss.h"
#include "bot1.h"

int compareSpells(node* a, node* b, int spellsLeft[]){ //compare spells; if a > b, returns 1, a < b, returns -1, else returns 0
    return (spellsLeft[a->spell[0] - 'a'] > spellsLeft[b->spell[0]] - 'a') ? 1 : -1;
}

node *botMakeMoveHelper(node *root, char prev, int spellsLeft[], node *best)
{
    if (root != NULL)
    {
        // recursive call for left tree
        best = botMakeMoveHelper(root->left, prev, spellsLeft, best);
        //check if root is better than best
        if(compareSpells(root, best, spellsLeft) > 0){
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

int main(){
    
    return 0;
}


// moderate bot: only check opponent's move.
// will be copied into bot1 once it works.

// following commented code is useless for now
/* node *newSearch(int index, node * root) {        //to find a spell based on it's place in the tree following an in-order traversal (not too sure about this still testing)
    int count = 0; //to keep track of which index we're at in the in-order traversal of the tree.
    bool isFound = false;

    while (!isFound) {
        if (count == index)     //here is where we reach the spell in the tree, so we return the node.
            return root;
        else
            if (root->left != NULL) {
                                //more code to add here: in order traversal if possible?
                count++;
            }
    }
} */

/*

//make the bot choose a spell
node *botMakesMove(node *root, char previousChar, int spellsLeft[]) {
    if (previousChar == ' ') {      //if the bot starts previousChar would be ' ' as we've initialized it to be.
                                    //wanted to use modifiedSearch but it won't work.
        int rand = randomNum(0, height(root)); //we're using the entire tree since we have no restrictions yet.

        //this is random, can't think of a better way without having the bot choose an impossible spell.
        //same idea as implementation of easy bot.
    }

    else {      //if previousChar isn't ' ', means it was changed and therefore the bot has to take it into consideration when making its next move.
        node * current = root;      //will be the one moving over.
        node * bestChoice =root;    //keep track of which spell is the best.
        node * pre;

        int count = 0;
        while (count <= spellsLeft[previousChar]) {
            char c = current->spell[strlen(current->spell) - 1];
            char best = bestChoice->spell[strlen(bestChoice->spell) - 1];

            if (bestChoice->spell[0] != previousChar && current->spell[0] == previousChar)  //when initializing the bestChoice spell we didn't take into consideration the requirements (whether the first letter is the same as the previous spell's last letter).
                bestChoice = current;
            else if (current->left == NULL) {   //starting here we're doing an in-order traversal of the tree which should ensure that once we get to the first work starting with the previousChar the next ones should as well.
                if (current->spell[0] == previousChar && spellsLeft[c]<spellsLeft[best])
                    bestChoice = current;
                current = current->right;
            }
            else {

                //find the in-order ancestor of current
                pre = current->left;
                while (pre->right != NULL && pre->right != current)
                    pre = pre->right;

                //make current the right child of its in-order ancestor
                if (pre->right == NULL) {
                    pre->right = current;
                    current = current->left;
                }

                //reverting the changes made in the 'if' part to restore the original tree i.e., fix the right child of predecessor
                else {
                    pre->right = NULL;
                    current = current->right;
                }
            }
        }
    }
}

*/

/*
while (count <= spellsLeft[previousChar]) { //we'l keep looking as long as we haven't gone over all the spells that start with the letter "previousChar".
            char c = current->spell[strlen(current->spell) - 1];
            char best = bestChoice->spell[strlen(bestChoice->spell) - 1];

            if (bestChoice->spell[0] != previousChar) {     //when initializing bestChoice we didn't check if the spell fits the requirements. (first letter same as last letter )
                bestChoice = current;
            }
            else if (spellsLeft[c] == 0) {
                return current;       //if there are no spells in the list that start with the letter then that would be the best choice.
            }
            else if (spellsLeft[c] < spellsLeft[best])
                bestChoice = current;
            else {      //check both children and compare? but this won't work: I'll choose one of the two then throw away the descendants of the other.


            }
        }
*/