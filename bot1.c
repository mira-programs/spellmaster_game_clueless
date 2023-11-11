#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TESTING STAGE - NOT A BOT YET
int main(){
    int alphabet [26] = {0};
    char word []= "hello";
    char firstLetter = word[0];
    // Check if the first letter is a lowercase letter
    if ('a' <= firstLetter && firstLetter <= 'z') {
        // Update the count in the alphabet array
        alphabet[firstLetter - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        printf("Count for '%c': %d\n", 'a' + i, alphabet[i]);
    }
}