#include <stdio.h>
int main()
{
    FILE *sptr; // file pointer
    char c;     // reading the characters individually instead of strings because we don't know how long the array length is
    sptr = fopen("spells.txt", "r");
    while (!feof(sptr)) // while pointer is not pointing to the end of the file (file end of file)
    {
        c = fgetc(sptr);
        printf("%c", c);
    }
    fclose(sptr);
    return 0;
}