#include "runGame.h"
void terminateTree(node *root)
{ // in order traversal to free the nodes of the tree
    if (root != NULL)
    {
        return;
    }
    terminateTree(root->left);
    terminateTree(root->right);
    free(root);
}