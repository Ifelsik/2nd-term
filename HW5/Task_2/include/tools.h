#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct sNode {
    struct sNode *next;
    char *value;
    int node_index;
} tNode;

void insert(tNode **head, char *value, int id);

tNode *search_by_id(tNode *head, int id);

int readfile(char *path, char **filebuf);

int replace(char *str, char from, char to);

#endif
