#include "fillingArray.h"
int checkMove(elements *spell, int spellCount, char previousChar, char move[])
{
    // looping through the rows (spells); checks if it was found and if it was cast
    for (int i = 0; i < spellCount; i++)
    {
        // checking if the spell cast is in the list
        if (strcmp(spell[i].name, move) == 0)
        { // if the spell is found, goes on to check if it has been used
            if (spell[i].used == 1)
            { // if the spell has been used before
                printf("spell was already used! you lose!\n");
                return -1;
            }
            else
            {
                spell[i].used = 1;                                  // if the spell was not used before, modifies array to update it
                if (move[0] != previousChar && previousChar != ' ') // checks the first char against the previous char
                {
                    printf("spell starts with the wrong character! you lose!\n");
                    return -1;
                }
                else
                {
                    printf("valid spell!\n");
                    return 1; // returns 1 for valid spell
                }
            }
        }
    }
    printf("spell is not in the list! you lose!\n");
    return -1;
}