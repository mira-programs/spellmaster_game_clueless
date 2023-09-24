#include <stdio.h>
#include <stdlib.h>
/*
  a)    takes the name of a text file
  b)    prints the spells in a table format with 5 words
  per line separated by tab spaces
  c)    returns a (pointer to a) 2D array containing the
  spells from the file in one column and 1’s in the other
  (returns void right now)
note:   the 2D array acts as a hashmap, with the spell name
as the key and the binary (0,1) to show whether the spell
has been used before. the spells will have initially have
1 as the corresponding value*/
int main()
{
  int s1 = 20;
  int s2 = 20;
  char **a = (char **)malloc(s1 * sizeof(int *));
  FILE *sptr;
  sptr = fopen("spells.txt", "r");
  if (sptr == NULL)
  {
    perror("fopen");
    exit(1);
  }
  while (!feof(sptr))
  {
    for (int i = 0; i < s2; i++)
      for (int j = 0; j < s1; j++)
        fgets(a[i], 50, sptr);
  }
  for (int i = 0; i < s2; i++)
  {
    for (int j = 0; j < s1; j++)
    {
      printf("%c", a[i][j]);
    }
    printf("\n");
  }
  int i;
  for (i = 0; i < s1; i++)
    free(a[i]);
  free(a);
  return 0;
}