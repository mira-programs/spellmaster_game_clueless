#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *sptr; // file pointer
    // char c;     // reading the characters individually instead of strings because we don't know how long the array length is
    char name1[20]; // scanning the players' names
    printf("Player one name: ");
    scanf("%s", name1);
    char name2[20];
    printf("\nPlayer two name: ");
    scanf("%s", name2);
    int s1 = 5;
    int s2 = 16;
    char **a = (char **)malloc(s1 * sizeof(int *));
    for (int i = 0; i < s1; i++)
        a[i] = (char *)malloc(s2 * sizeof(int));
    sptr = fopen("spells.txt", "r");
    while (!feof(sptr)) // while pointer is not pointing to the end of the file (file end of file)
    {
        for (int i = 0; i < 16; i++)
            for (int j = 0; j < 5; j++)
                a[i][j] = fgetc(sptr);
    }
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }

    fclose(sptr);
    return 0;
}