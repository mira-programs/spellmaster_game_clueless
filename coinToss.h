#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BST.h"

int coinToss()
{                      // function to decide which player goes first by 'tossing a coin' by generating a random number
    srand(time(NULL)); // seed with the current time to get different results at different runs
    int randomnumber;
    randomnumber = rand() % 2;
    return randomnumber;
}