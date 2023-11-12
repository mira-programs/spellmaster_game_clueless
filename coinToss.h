#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Precondition:nothing
Postcondition: returns a random number 0,1 deciding who starts
*/
int coinToss()
{                     
    srand(time(NULL)); // seed with the current time to get different results at different runs
    int randomnumber;
    randomnumber = rand() % 2;
    return randomnumber;
}
