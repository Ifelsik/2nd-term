#include "main.h"


int main(int argc, char *argv[]) {
    BST_t *tree = NULL;
    BST_t *found_vertex = NULL;
    FILE *file_p = NULL;
    char *str = NULL;
    char *substr = NULL;
    char *path = NULL;
    int size = 0;
    int number_to_search = 0;

    // I believe you won't put strange program args
    number_to_search = atoi(argv[1]);
    path = argv[2];

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
    substr = strtok(str, ",");
    while (substr != NULL) {
        if (strcmp(substr, "null"))
            tree_add(&tree, atoi(substr));
        substr = strtok(NULL, ",");
    }

    if (tree_isFound(tree, number_to_search)) {
        found_vertex = tree_find(tree, number_to_search);
        tree_print(found_vertex);
    } else
        printf("Not found ...\n");

    tree_destroy(tree);
    return 0;
}
