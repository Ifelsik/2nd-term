#include "main.h"


int main(int argc, char *argv[]) {
    BST_t *tree = NULL;
    BST_t *found_vertex = NULL;
    FILE *file_p = NULL;
    char *str = NULL;
    char *substr = NULL;
    char *path = NULL;
    int size = 0;
    int left = 0;
    int right = 0;

    // I believe you won't put strange program args
    path = argv[1];
    left = atoi(argv[2]);
    right = atoi(argv[3]);
    if (left > right) {
        int temp = left;
        left = right;
        right = temp;
    }

    file_p = fopen(path, "r");
    if (file_p == NULL) {
        fprintf(stderr, "Can't open file\n");
        exit(EXIT_FAILURE);
    }
    fseek(file_p, 0, SEEK_END);
    size = ftell(file_p);
    fseek(file_p, 0, SEEK_SET);
    str = (char*) calloc(size, sizeof(char));

    fscanf(file_p, "%s", str);
    fclose(file_p);
    substr = strtok(str, ",");
    while (substr != NULL) {
        int num = atoi(substr);
        if (strcmp(substr, "null"))
            tree_add(&tree, num);
        substr = strtok(NULL, ",");
    }

    printf("Tree before\n");
    tree_print(tree);
    tree = tree_slice(tree, left, right);
    printf("\nTree after\n");
    tree_print(tree);
    tree_destroy(tree);
    return 0;
}
