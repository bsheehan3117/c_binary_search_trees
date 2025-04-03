/**
 * Student Name: Brendan Sheehan
 * Semester: Summer 2023
 * 
 * This file is to test the functions in my_bst.c, my_bst_util.c, and my_bst_printer.c. 
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_bst_printer.c"
#include "my_bst.h"
#include "my_bst_util.h"


// a helper to get a range  of numbers
int *get_range_array(int start, int end) {
    int *arr = (int*) malloc(sizeof(int) * (end - start));
    int j = 0;
    for (int i = start; i < end; i++, j++) arr[j] = i;
    return arr;
}

// sample helper function to help you create random int arrays
int *get_random_array(int size) {
    int *arr = (int *)malloc(sizeof(int) * size);
    srand(time(NULL)); // seed the random number generator

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    return arr;
}

// Test for an empty tree
int test_empty_tree(int status) {

    BST *tree = create_bst();

    if (bst_size(tree) != 0) {
        printf("Failed Test\n");
        return 0;
    }

    if (bst_exists(tree, 10)) {
        printf("Failed Test\n");
        return 0;
    }

    bst_free(tree);
    return 1;
}

// Test for a node that does not exist
int test_non_existent_node(int status) {

    BST *tree = create_bst();
    int *values = get_range_array(0, 100);

    for (int i = 0; i < 100; i++) {
        bst_add(tree, values[i]);
    }

    if (bst_exists(tree, 101)) {
        printf("Failed Test\n");
        free(values);
        return 0;
    }

    bst_free(tree);
    free(values);
    return 1;
}

// Tests the add function
int test_add(int status) {

    BST *tree = create_bst();
    int *values = get_range_array(1, 101);

    for (int i = 0; i < 100; i++) {
        if (bst_add(tree, values[i]) != 1) {
            printf("Failed Test\n");
            free(values);
            return 0;
        }
    }

    if (bst_size(tree) != 100) {
        printf("Failed Test\n");
        free(values);
        return 0;
    }

    for (int i = 0; i < 100; i++) {
        if (!bst_exists(tree, values[i])) {
            printf("Failed Test\n");
            free(values);
            return 0;
        }
    }

    bst_free(tree);
    free(values);
    return 1;
}

// Tests the sum function
int test_sum(int status) {

    BST *tree = create_bst();
    int *values = get_range_array(0, 100);

    for (int i = 0; i < 100; i++) {
        bst_add(tree, values[i]);
    }

    if (sum(tree) != 4950) {
        printf("Failed Test\n");
        free(values);
        return 0;
    }

    bst_free(tree);
    free(values);
    return 1;
}

// Tests the min function
int test_min(int status) {

    BST *tree = create_bst();
    int *values = get_range_array(0, 100);

    for (int i = 0; i < 100; i++) {
        bst_add(tree, values[i]);
    }

    if (min(tree) != 0) {
        printf("Failed Test\n");
        free(values);
        return 0;
    }

    bst_free(tree);
    free(values);
    return 1;
}

// Tests the max function
int test_max(int status) {

    BST *tree = create_bst();
    int *values = get_range_array(0, 100);

    for (int i = 0; i < 100; i++) {
        bst_add(tree, values[i]);
    }

    if (max(tree) != 99) {
        printf("Failed Test\n");
        free(values);
        return 0;
    }

    bst_free(tree);
    free(values);
    return 1;
}

// Tests the add function
int test_add_edge_case(int status) {

    BST *tree = create_bst();
    int values[] = {50, 25, 75, 10, 5, 5}; 

    for (int i = 0; i < 6; i++) {
        bst_add(tree, values[i]);
    }

    if (bst_size(tree) != 5) {
        printf("Failed Test\n");
        bst_free(tree);
        return 0;
    }

    bst_free(tree);
    return 1;
}

// Tests the sum function
int test_sum_edge_case(int status) {

    BST *tree = create_bst();
    if (sum(tree) != 0) {
        printf("Failed Test\n");
        bst_free(tree);
        return 0;
    }

    bst_add(tree, 42);
    if (sum(tree) != 42) {
        printf("Failed Test\n");
        bst_free(tree);
        return 0;
    }

    bst_free(tree);
    return 1;
}

// Tests the min function
int test_min_edge_case(int status) {

    BST *tree = create_bst();

    if (min(tree) != 0) {
        printf("Failed Test\n");
        bst_free(tree);
        return 0;
    }

    bst_add(tree, 42);
    if (min(tree) != 42) {
        printf("Failed Test\n");
        bst_free(tree);
        return 0;
    }

    bst_free(tree);
    return 1;
}

// Tests the max function
int test_max_edge_case(int status) {

    BST *tree = create_bst();

    if (max(tree) != 0) {
        printf("Failed Test\n");
        bst_free(tree);
        return 0;
    }

    bst_add(tree, 42);
    if (max(tree) != 42) {
        printf("Failed Test\n");
        bst_free(tree);
        return 0;
    }

    bst_free(tree);
    return 1;
}

// Tests adding a duplicate
int test_duplicate(int status) {
    BST *tree = create_bst();
    bst_add(tree, 5);
    if (bst_add(tree, 5) != 0) { 
        printf("Failed Test\n");
        bst_free(tree);
        return 0;
    }
    bst_free(tree);
    return 1;
}

// Tests operations on a single node tree
int test_single_node_tree(int status) {
    BST *tree = create_bst();
    bst_add(tree, 42);
    if (bst_size(tree) != 1 || !bst_exists(tree, 42) || sum(tree) != 42 || min(tree) != 42 || max(tree) != 42) {
        printf("Failed Test\n");
        bst_free(tree);
        return 0;
    }
    bst_free(tree);
    return 1;
}

// Tests operations on a tree with negative values
int test_negative(int status) {
    BST *tree = create_bst();
    int *values = get_range_array(-50, 0);
    for (int i = 0; i < 50; i++) {
        bst_add(tree, values[i]);
    }
    if (min(tree) != -50 || max(tree) != -1 || sum(tree) != -1275) {
        printf("Failed Test\n");
        free(values);
        bst_free(tree);
        return 0;
    }
    free(values);
    bst_free(tree);
    return 1;
}

// Tests operations with positive and negative values in tree
int test_mix_values(int status) {
    BST *tree = create_bst();
    int values[] = {-20, -10, 0, 10, 20};
    for (int i = 0; i < 5; i++) {
        bst_add(tree, values[i]);
    }
    if (min(tree) != -20 || max(tree) != 20 || sum(tree) != 0) { 
        printf("Failed Test\n");
        bst_free(tree);
        return 0;
    }
    bst_free(tree);
    return 1;
}

// Tests freeing an empty tree
int test_free_empty_tree(int status) {
    BST *tree = create_bst();
    bst_free(tree);  
    return 1;
}


// Test operations on tree with null root
int test_tree_with_null_root(int status) {
    BST *tree = create_bst();
    tree->root = NULL;

    if (bst_size(tree) != 0) {
        printf("Failed size null\n");
        bst_free(tree);
        return 0;
    }

    if (bst_exists(tree, 10)) {
        printf("Failed exists null\n");
        bst_free(tree);
        return 0;
    }

    bst_add(tree, 42);
    if (tree->root->data != 42) {
        printf("Failed add null\n");
        bst_free(tree);
        return 0;
    }

    if (sum(tree) != 42) {
        printf("Failed sum null\n");
        bst_free(tree);
        return 0;
    }

    if (min(tree) != 42) {
        printf("Failed min null\n");
        bst_free(tree);
        return 0;
    }

    if (max(tree) != 42) {
        printf("Failed max null\n");
        bst_free(tree);
        return 0;
    }

    bst_free(tree);
    return 1;
}


// Print functions to be checked when run for correctness
void example_prints() {

    BST *tree = create_bst();
    int *values = get_range_array(1, 101);

    for (int i = 0; i < 100; i++) {
        bst_add(tree, values[i]);
    }

    printf("In Order: ");
    bst_print(tree, "inorder");
    printf("\n");

    printf("Pre Order: ");
    bst_print(tree, "preorder");
    printf("\n");

    printf("Post Order: ");
    bst_print(tree, "postorder");
    printf("\n");

    printf("Breadth First: ");
    bst_print(tree, "breadthfirst");
    printf("\n");

    bst_free(tree);
    free(values);
}




int (*unitTests[])(int) = {
    test_empty_tree,
    test_add,
    test_sum,
    test_min,
    test_max,
    test_non_existent_node,
    test_duplicate,
    test_single_node_tree,
    test_negative,
    test_mix_values,
    test_free_empty_tree,
    test_add_edge_case,
    test_sum_edge_case,
    test_min_edge_case,
    test_max_edge_case,
    test_tree_with_null_root,

    NULL
};

/**
* Main function for the test file.
*/
int main() {
    unsigned int testsPassed = 0;
    int counter = 0;
    while (unitTests[counter] != NULL) {
        printf("========unitTest %d========\n", counter);
        if (1 == unitTests[counter](1)) {
            printf("passed test\n");
            testsPassed++;
        } else {
            printf("failed test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    example_prints();

    return 0;
}