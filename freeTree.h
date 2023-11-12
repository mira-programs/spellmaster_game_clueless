#include "checkMove.h"
/*
Precondition:node pointer to the root of the BST
Postcondition:nothing
*/
void terminateTree(node *root)
{ 
    if (root != NULL)
    {
        return;
    }
    terminateTree(root->left);
    terminateTree(root->right);
    free(root);
}
