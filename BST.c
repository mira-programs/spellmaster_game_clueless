#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node { //defines a BST node
    char* spell;
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
 
    return root; //returns the (unchanged) root pointer
}

//printing inorder traversal of tree
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->spell);
        inorder(root->right);
    }
}
 
//temp main to test AVL tree
int main() {
    struct node *root = NULL;
 
    root = insert(root, "a");
    root = insert(root, "b");
    root = insert(root, "c");
    root = insert(root, "d");
    root = insert(root, "e");
    root = insert(root, "f");

 
    printf("in order traversal of the avl tree is \n");
    inorder(root);
 
    return 0;
}


