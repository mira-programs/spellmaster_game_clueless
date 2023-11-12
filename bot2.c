#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "freeTree.h"
#include "coinToss.h"
#include "bot1.h"

//moderate bot: only check opponent's move.
//will be copied into bot1 once it works.

node *newSearch(int index, node * root) {        //to find a spell based on it's place in the tree following an in-order traversal (not too sure about this still testing)
    int count = 0; //to keep track of which index we're at in the in-order traversal of the tree.
    bool isFound = false;

    while (!isFound) {    
        if (count == index) //here is where we reach the spell in the tree, so we return the node.
            return root;
        else 
            if (root->left != NULL) {
                //more code to add here: in order traversal if possible?
                count++;
            }
    }
}

//make the bot choose a spell
node *botMakesMove(node *spellTree, char previousChar, char *spell, int spellsLeft[]) {
    if (previousChar == ' ') {      //if the bot starts previousChar would be ' ' as we've initialized it to be.
        //wanted to use modifiedSearch but it won't work.
        int rand = randomNum(0, height(spellTree)); //we're using the entire tree since we have no restrictions yet.

        //this is random, can't think of a better way without having the bot choose an impossible spell.
    }
    else {  //if previousChar isn't ' ', means it was changed and therefore the bot has to take it into consideration when making its next move.

    }
};