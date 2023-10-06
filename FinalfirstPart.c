#include <stdio.h>
#include <stdlib.h>

typedef struct Element elements;
struct Element
{
    char name[50];
    int used;
};
int getRowNumber(char fileName[])
{
    FILE *sptr;
    sptr = fopen(fileName, "r");
    if (sptr == NULL)
    {
        perror("fopen");
        exit(1);
    }
    int lines = 0;
    int ch;
    int prev = EOF;                   // Initialize to end of file
    while ((ch = fgetc(sptr)) != EOF) // To get the number of lines in the file
    {
        if (ch == '\n')
        {
            lines++;
        }
        prev = ch;
    }
    if (prev != '\n' && prev != EOF) // to get the last element
    {
        lines++;
    }
    fclose(sptr);
    return lines;
}

elements *createAndFill(char fileName[], int rowNumber)
{
    FILE *sptr;
    int maxLength = 50; // string maximum number of character
    elements *spell = (elements *)malloc(sizeof(elements) * rowNumber);
    sptr = fopen("spells.txt", "r");
    if (sptr == NULL)
    {
        perror("fopen");
        exit(1);
    }
    int i = 0;

    while (i < rowNumber && fscanf(sptr, "%s", spell[i].name) == 1) // returns 1 if the scan is succesful so if file was not read 0 will be returned instead
    {
        spell[i].used = 0;
        i++;
    }
    fclose(sptr);
    return spell;
}

void printArray(elements *spell, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        printf("%s\t", spell[i].name);
        if ((i + 1) % columns == 0)
        {
            printf("\n");
        }
    }
    free(spell);
}

int main()
{
    printArray(createAndFill("spells.txt", getRowNumber("spells.txt")), getRowNumber("spells.txt"), 5);
    return 0;
}
