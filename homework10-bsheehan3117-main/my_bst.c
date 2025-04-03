/** Implementation of the BST data structure.
 * This file contains functions for creating a BST,
 * determining if a tree is empty, checking if a value in the
 * tree exists, checking the size of the tree, adding to a tree, 
 * and freeing memory from a tree.
 *
 * Functions include:
 * bst_is_empty
 * bst_exists
 * bst_size
 * bst_add
 * bst_free
 * create_bst
 * 
 * @author Brendan Sheehan
 * Semester Summer 2023
*/

#include "my_bst.h"


/**
 * Checks to see if the tree is empty
 * by looking at the tree size.
 * returns true if the tree is empty.
 * False otherwise.
*/
bool bst_is_empty(BST *tree) {

    return tree == NULL || tree->size == 0;
}

/**
* Recursive helper function to see if bst exists
*/
bool bst_exists_helper(Node *node, int value) {

    // Return false if node is null
    if (node == NULL) return false;
    
    // If node data == value return true
    if (node->data == value) return true;
    
    // Recursively search tree based on value and data
    if (value < node->data) {
        return bst_exists_helper(node->left, value);
    } else {
        return bst_exists_helper(node->right, value);
    }
}


/**
 * Checks to see if the value exists in the tree.
 * returns true if the value exists in the tree.
 * False otherwise.
*/
bool bst_exists(BST *tree, int value)
{
    // Return false for null tree
    if (tree == NULL) return false;
    
    // Helper function to search for value
    return bst_exists_helper(tree->root, value);
}

/**
 * Returns the size of the tree.
*/
unsigned int bst_size(BST *tree) {

    if (tree == NULL) {
        return 0;
    } else {
        return tree->size;
    }
}

/**
* Helper function to add a value to a tree.
*/ 
Node *bst_add_helper(Node *node, int value, int *result) {

    // Check if null node
    if (node == NULL) {

        // Allocate mem for node
        node = (Node*)malloc(sizeof(Node));
        
        // If node node null set result to -1 return null
        if (node == NULL) {
            *result = -1;
            return NULL;
        }
        
        // Init new node and set null pointers for l/r
        node->data = value;
        node->left = node->right = NULL;

        *result = 1;
        
        return node;
    }
    
    // Result == 0 if value exists already
    if (value == node->data) {
        *result = 0;
        return node;
    }
    
    // L/R addition based on data and return
    if (value < node->data) node->left = bst_add_helper(node->left, value, result);
    else node->right = bst_add_helper(node->right, value, result);
    
    return node; 
}

/**
 * Adds a value to the tree.
 * returns 1 if the value was added successfully.
 * returns 0 if the value already exists in the tree.
 * returns -1 if the value could not be added due to errors. (malloc failed)
*/
int bst_add(BST *tree, int value) {

    // Return -1 if null
    if (tree == NULL) return -1;
    
    // Result default set to 0
    int result = 0; 
    
    // Call helper function
    tree->root = bst_add_helper(tree->root, value, &result);
    
    // Increase tree size and return 1 added
    if (result == 1) tree->size++;
    
    return result; 
}

/**
* Helper function to recursively free nodes.
*/ 
void bst_free_helper(Node *node) {
    
    // Return if null
    if (node == NULL) return;   

    // Free left side        
    bst_free_helper(node->left);
    
    // Free right side
    bst_free_helper(node->right);      
    free(node);                        
}

/**
 * Frees the memory allocated for the tree.
*/
void bst_free(BST *tree) {

    // Return if null
    if (tree == NULL) return;  

    // Free nodes        
    bst_free_helper(tree->root);    
    
    // Free tree
    free(tree);                        
}

/**
 * Creates a new BST.
 * returns a pointer to the new BST.
 * The root node will still be NULL until the first bst_add is called
*/
BST *create_bst() {

    // Allocate mem for new bst
    BST *tree = (BST*)malloc(sizeof(BST));

    // Null check for mem alloc
    if (tree == NULL) return NULL; 
    
    // Set size to 0
    tree->size = 0; 

    // Set root to null
    tree->root = NULL; 
    
    return tree; 
}

