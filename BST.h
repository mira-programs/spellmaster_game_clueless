#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node { //defines a BST node
    char* spell;
    int used; //used variable indicates if spell was cast before. set to 1 if cast before, 0 otherwise
    struct node* left;
    struct node* right;
    int height;
}node;

node* newNode(char* s){ //creates a new node. s is the spell being added
    node* n = (node*)malloc(sizeof(node)); //creates pointer to new node n and allocates memory
    n->spell = s; //defines the new node with the new spell
    n->left = NULL; //initializes pointers to left and right children to NULL
    n->right = NULL;
    n->height = 1; //initializes height to 1
    n->used = 0; //initializes used to 0, initially all spells are not cast yet
    return n;
}

int height(node* n){ //gets the height of a node
    if(n == NULL) return 0;
    return n->height;
}

int getBalance(node* n){ //calculates balance factor of node n
    if(n == NULL)
        return 0; 
    return height(n->left) - height(n->right);
}

int max(int a, int b){ //max function, used to calculate height in insert function
    return (a > b) ? a : b; //returns the max of the two integers
}

node* leftRotate(node* x){ //left-roation performed on (sub)tree of root x
    //creating pointers to the relevent subtrees/nodes
    node *y = x->right;
    node *T2 = y->left;
    //performing rotation
    y->left = x;
    x->right = T2;
    //updating heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; //returns y, the new root
}

node* rightRotate(node* y){ //right-rotation performed on (sub)tree of root y
    //creating pointers to the relevant subtrees/nodes
    node* x = y->left;
    node* T2 = x->right;
    
    //performing rotation
    x->right = y;
    y->left = T2;
    
    //updating heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x; //returns x, the new root
}

node* insert(node* root, char* spell){ //recursively insert a new node, passing root node and the spell to add
    //normal insertion of the node in the right place
    if(root == NULL)
        return newNode(spell); //base case: creates the node
    else if(strcmp(spell, root->spell) < 0) //compares the spells of the root and new node
        root->left = insert(root->left,spell); //insert to the left if the new spell comes first
    else
        root->right = insert(root->right,spell); //insert to the right if the root spell comes first

    root->height = max(height(root->left), height(root->right)) + 1; //updating height of the root nodes

    //balancing the tree
    int balance = getBalance(root);
    //left-left case
    if (balance > 1 && strcmp(spell, root->left->spell) < 0)
        return rightRotate(root);
    //right-right case
    if (balance < -1 && strcmp(spell, root->right->spell) > 0)
        return leftRotate(root);
    //left-right case
    if (balance > 1 && strcmp(spell, root->left->spell) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //right-left case
    if (balance < -1 && strcmp(spell, root->right->spell) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; //returns the root pointer
}

node* search(node* root, char* spell){ //recursive search function to find a spell in the tree
    if(root == NULL || strcmp(root->spell, spell) == 0)
        return root; //returns the node with the spell if found, otherwise will be NULL
    if(strcmp(root->spell, spell) > 0)
        return search(root->left, spell);
    else return search(root->right, spell);
}

node* delete(node* root, char* spell){
    if (root == NULL) //if spell to be deleted is not in tree, returns root as-is
        return root;

    //recursively calling the delete function to find node to be deleted
    if (strcmp(spell, root->spell) < 0){
        root->left = delete(root->left, spell);
    } else if (strcmp(spell, root->spell) > 0) {
        root->right = delete(root->right, spell);
    } else{ //when the node is found, this part deletes it
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->spell = temp->spell;
        root->right = delete(root->right, temp->spell);
    }

    if (root == NULL) {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1; //updating height of the root node

    //balancing the tree
    int balance = getBalance(root);
    //left-left case
    if (balance > 1 && strcmp(spell, root->left->spell) < 0)
        return rightRotate(root);
    //right-right case
    if (balance < -1 && strcmp(spell, root->right->spell) > 0)
        return leftRotate(root);
    //left-right case
    if (balance > 1 && strcmp(spell, root->left->spell) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //right-left case
    if (balance < -1 && strcmp(spell, root->right->spell) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}