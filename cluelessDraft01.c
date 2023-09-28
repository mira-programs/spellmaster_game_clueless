#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *sptr;     // file pointer
    char c;         // reading the characters individually instead of strings because we don't know how long the array length is
    char name1[20]; // scanning the players' names
    printf("Player one name: ");
    scanf("%s", name1);
    char name2[20];
    printf("\nPlayer two name: ");
    scanf("%s", name2);
    int s1 = 5;
    int s2 = 16;
    char **a = (char **)malloc(s1 * sizeof(char *));
    for (int i = 0; i < s1; i++)
        a[i] = (char *)malloc(s2 * sizeof(char));
    sptr = fopen("spells.txt", "r");
    while (!feof(sptr)) // while pointer is not pointing to the end of the file (file end of file)
    {
        for (int i = 0; i < 16; i++)
            for (int j = 0; j < 5; j++)
            {
                char line[1000];
                a[i][j] = fgets(20, sizeof line, sptr);
            }
    }
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    int i;
    for (i = 0; i < s1; i++)
        free(a[i]);
    free(a);
    fclose(sptr);
    return 0;
}