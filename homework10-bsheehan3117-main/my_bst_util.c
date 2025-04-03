/** Implementation of BST utility functions.
 * These functions provide the ability to retrieve data from 
 * a binary search tree.
 * Functions include:
 * sum
 * min
 * max
 *
 *  @author Brendan Sheehan
 * Semester Summer 2023
 *
*/


#include "my_bst_util.h"

/**
* Helper function to recursively sum values.
*/

int sum_helper(Node *node) {

    // Base case null node = o
    if (node == NULL) return 0;
    
    // Sum current node and left/right
    return node->data + sum_helper(node->left) + sum_helper(node->right);
}

/**
 * Returns the sum of all the values in the tree.
*/
int sum(BST *tree) {

    return sum_helper(tree->root);
}


/**
* Helper function to find min.
*/

int min_helper(Node *node) {

    // Base case null node = 0
    if (node == NULL) return 0; 
    
    // Traverse left node with lowest value for min
    while (node->left != NULL) node = node->left;
    return node->data;
}


/**
 * Returns the minimum value in the tree. 
*/
int min(BST *tree) {
    
return min_helper(tree->root);
}


/**
* Helper function to find max.
*/ 

int max_helper(Node *node) {

    // Base case null node = 0
    if (node == NULL) return 0;
    
    // Traverse right node with highest value for max
    while (node->right != NULL) node = node->right;
    return node->data;
}


/**
 * Returns the maximum value in the tree.
*/
int max(BST *tree) {
    
return max_helper(tree->root);
}
