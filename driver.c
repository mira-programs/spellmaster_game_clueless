#include <stdio.h>
// #include "putElements.h"
#include "checkMove.h"
#include <stdbool.h>
int main()
{
    int row = getRowNumber("spells.txt");
    elements *spell = createAndFill("spells.txt,", row);
    printArray(spell, row, 5);
    char prev = ' ';
    char move[50];
    bool p = true;
    printf("insert spell:\n ");
    scanf("%s", &move);
    while (strcmp(checkMove(spell, row, prev, move, p), "valid spell!") == 0)
    {
        printf("%s", checkMove(spell, row, prev, move, p));
        prev = move[strlen(move) - 1];
        printf("\ninsert spell: ");
        scanf("%s", &move);
        p = !p;
    }
    if (p == true)
    {
        printf("\ncongrats player 1");
    }
    else
    {
        printf("\ncongrats player 2");
    }
    return 0;
}
