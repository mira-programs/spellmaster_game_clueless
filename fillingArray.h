#include <string.h>

// defining a custom datatype to store the spells and whether they have been used
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
    return lines - 1;
}

elements *createAndFill(char fileName[])
{

    FILE *sptr;
    int maxLength = 50; // string maximum number of character
    sptr = fopen("spells.txt", "r");
    if (sptr == NULL)
    {
        perror("fopen");
        exit(1);
    }
    int i = 0;
    int rowNumber = getw(sptr);
    elements *spell = (elements *)malloc(sizeof(elements) * rowNumber);
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
}