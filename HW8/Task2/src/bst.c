//
// Created by misha on 23.05.2023.
//

#include "../include/bst.h"

//BST_t *tree_init() {
//    BST_t *tree_root = (BST_t*) malloc(sizeof(BST_t));
//    tree_root->value = -INT_MAX;
//    tree_root->left = NULL;
//    tree_root->right = NULL;
//    return tree_root;
//}

void tree_destroy(BST_t *vertex) {
    if (vertex == NULL)
        return;
    tree_destroy(vertex->left);
    tree_destroy(vertex->right);
    free(vertex);
}

void tree_add(BST_t **vertex, int x) {
    if (*vertex == NULL) {
        *vertex = (BST_t*) malloc(sizeof(BST_t));
        (*vertex)->left = NULL;
        (*vertex)->right = NULL;

        (*vertex)->value = x;
        return;
    }
    return (x <= (*vertex)->value) ? tree_add(&((*vertex)->left), x) : tree_add(&((*vertex)->right), x);
}

BST_t *tree_find(BST_t *vertex, int x) {
    if (vertex == NULL)
        return NULL;
    if (vertex->value == x)
        return vertex;

    return (x <= vertex->value) ? tree_find(vertex->left, x) : tree_find(vertex->right, x);
}

bool tree_isFound(BST_t *vertex, int x) {
    return (tree_find(vertex, x) != NULL) ? true : false;
}

// special function
int __maxDepth(BST_t *vertex, int depth, int max_depth) {
    if (vertex == NULL) {
        return max_depth;
    }
    max_depth = (depth > max_depth ? depth : max_depth);
    max_depth = __maxDepth(vertex->left, depth + 1, max_depth);
    max_depth = __maxDepth(vertex->right, depth + 1, max_depth);
    return max_depth;
}

int tree_maxDepth(BST_t *vertex) {
    return __maxDepth(vertex, 0, 0);
}


// also special function
void __print_level(BST_t *vertex, int lvl, int cur_lvl) {
    if (vertex == NULL) {
        for (int i = 0; i < pow(2, lvl - cur_lvl); i++)
            printf("null,");
        return;
    }
    if (cur_lvl == lvl) {
        printf("%d,", vertex->value);
        return;
    }
    __print_level(vertex->left, lvl, cur_lvl + 1);
    __print_level(vertex->right, lvl, cur_lvl + 1);

}

void tree_print(BST_t *vertex) {
    for (int i = 0; i <= __maxDepth(vertex, 0, 0); i++)
        __print_level(vertex, i, 0);
}

BST_t *tree_slice(BST_t *vertex, int min, int max) {
    if (vertex == NULL)
        return vertex;
    vertex->left = tree_slice(vertex->left, min, max);
    vertex->right = tree_slice(vertex->right, min, max);
    if (vertex->value < min) {
        BST_t *temp = vertex->right;
        free(vertex);
        return temp;
    }
    if (vertex->value > max) {
        BST_t *temp = vertex->left;
        free(vertex);
        return temp;
    }
    return vertex;
}
