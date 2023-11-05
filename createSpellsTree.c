#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int printInOrder(node* root, int printed, int spellCount) { //helper function to print the spells by inorder traversal
    if (root != NULL) {
        //recursive call for left tree
        printed = printInOrder(root->left, printed, spellCount);
        //print the spell and increment the number of spells printed
        printf("%s\t", root->spell);
        printed++;
        //check if a multiple of 5 spells has been printed, print a new line if yes
        if (printed % 5 == 0 || printed == spellCount) {
            printf("\n");
        }
        //recurvise call for right tree
        printed = printInOrder(root->right, printed, spellCount);
    }
    return printed;
}

node* createAndPrintTree(char* fileName){ //function to create and fill a BST with the spells from txt file
    //opening the file
    FILE* filePointer;
    filePointer = fopen(fileName, "r"); //opening the txt file to read
    if (filePointer == NULL){
        perror("fopen"); //prints that error occurred during opening file
        exit(1);
    }
    
    //reading the number of spells, first line of the txt file
    int spellCount;
    fscanf(filePointer, "%d", &spellCount);
    //reading the spells from the file, and printing as it goes
    char spell[50];
    int spellsPrinted = 0;
    fscanf(filePointer, "%50s", spell); //takes the first spell from the file
    node* root = newNode(strdup(spell)); //initializes the tree using the first spell
    
    while(fscanf(filePointer, "%50s", spell) != EOF){ //repeats till end of file
        root = insert(root, strdup(spell)); //insert the spell that was just read
    }
    
    fclose(filePointer); //closes the file
    printInOrder(root, 0, spellCount);
    return root; //returns the root of the 
}