/*
  ~clueless
  Mira Hussein
  Haya Mouneimne
  Mariam Sonji

  checkMove() function - DRAFT #1
  
  this file contains our first draft for the checkMove() function along with a main function solely for testing the function
*/

#include <stdio.h>
#include <string.h>

//function to check the validity and result of a move
char * checkMove(char (*spells)[2][20], int spellCount, char previousChar, char move[]){
    
    //creating integers to record if the spell is in the list, was not cast before, and starts with the right char
    int isFound = 0;
    int wasCast = 0;
    int isCorrectChar = 1;
    int isValid = 1;
    //looping through the rows (spells); checks if it was found and if it was cast
    for(int i = 0; i < spellCount; i++){
        //checking if the spell cast is in the list
        if(strcmp(spells[i][0], move) != 0){ //if the spell is found, goes on to check if it has been used
            isFound = 1; //updates that it has been found
            if(strcmp(spells[i][1], "1") == 0){ //if the spell has been used before
                wasCast = 1; //updates that it was already cast before
                isValid = 0; //update that the spell is invalid
            }else{
                strcpy(spells[i][1], "1"); //if the spell was not used before, modifies array to update it
                //note that it keeps the wasCast variable to 0 since it was not previously cast till now
            }
            break; //ends the loop since the spell was found
        }
    }
    //checks if the first character was correct
    if(move[0] != previousChar && previousChar != ' '){ //checks the first char against the previous char
        isCorrectChar = 0; //if they are different, updates the information
        isValid = 0; //update validity
    } 
    //final checks for validity
    if(isValid == 1){
        return "valid spell!";
    }else if(isFound == 0){
        return "spell is not in the list! you lose!";
    }else if(wasCast == 1){
        return "spell was already used! you lose!";
    }else if(isCorrectChar == 0){
        return "spell starts with the wrong character! you lose!";
    }else{
        return "error";
    }
}

int main(){
    
    //creating a spells array for testing the function
    char spells[77][2][20] = {
        {"accio","0"},
        {"bombarda","0"},
        {"colloportus","0"},
        {"deletrius","0"},
        {"enervate","0"},
        {"feraVerto","0"},
        {"geminio","0"},
        {"homorphus","0"},
        {"immobulus","0"},
        {"legilimens","0"},
        {"mobiliarbus","0"},
        {"nox","0"},
        {"obliviate","0"},
        {"petrificusTotalus","0"},
        {"quietus","0"},
        {"reducio","0"},
        {"salvioHexia","0"},
        {"tarantallegra","0"},
        {"waddiwasi","0"}
    };

    //creating a pointer to the spells array
    char (*spellsPTR)[2][20] = spells;

    //calling the function and printing the result
    printf("%s", checkMove(spellsPTR, 77, ' ', "accio"));

    return 0;
}
