#ifndef TASK_1_BST_H
#define TASK_1_BST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct Node {
    int value;
    struct Node *left, *right;
} BST_t;

// constructor
BST_t *tree_init();

// destructor
void tree_destroy(BST_t *vertex);

void tree_add(BST_t **vertex, int x);

int tree_maxDepth(BST_t *vertex);

BST_t *tree_find(BST_t *vertex, int x);

bool tree_isFound(BST_t *vertex, int x);

void tree_print(BST_t *vertex);

#endif //TASK_1_BST_H
