#include "createSpellsTree.h"

int checkMove(node *spellTree, char previousChar, char *spell)
{
    // searching the tree for the spell that was cast
    node *move = search(spellTree, spell);
    if (move != NULL)
    { // if found...
        if (move->used == 1)
        { // if spell was cast before (invalid)
            printf("spell was already used! you lose!\n");
            return -1;
        }
        else
        {                                // if spell was not cast before (valid)
            deleteNode(spellTree, move); // deletes the spell from the tree
            if (spell[0] != previousChar && previousChar != ' ')
            { // if spell starts with the wrong char (invalid)
                printf("spell starts with the wrong character! you lose!\n");
                return -1;
            }
            else
            { // if spell is valid
                printf("valid spell!\n");
                return 1; // returns 1 for valid spell
            }
        }
    }
    else
    { // if the spell is not found...
        printf("spell is not in the list! you lose!\n");
        return -1;
    }
}
