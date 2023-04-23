#include "../include/tools.h"


void insert(tNode **head, char *value, int id) {
    tNode *temp = NULL;
    temp = (tNode*) malloc(sizeof(tNode));
    temp->next = *head;
    temp->value = value;
    temp->node_index = id;
    *head = temp; 
}

tNode *search_by_id(tNode *head, int id) {
    int head_id;
    head_id = head->node_index;
    if (id > head_id) {
        return NULL;
    }
    for (; head_id >= 0; head_id--) {
        if (head_id == id)
            break;
        head = head->next;
    }
    return head;
}

int readfile(char *path, char **filebuf) {
    FILE *file_p = NULL;
    file_p = fopen(path, "r");
    if (file_p != NULL) {
        fseek(file_p, 0, SEEK_END);
        int len = ftell(file_p);
        fseek(file_p, 0, SEEK_SET);

        *filebuf = (char*) malloc(sizeof(char) * (len + 1));
        if (NULL == *filebuf) {
            puts("OS didn't gave memory...");
            return 1;
        }
        fread(*filebuf, sizeof(char), len + 1, file_p);
        fclose(file_p);
    } else {
        puts("ERROR: File ptr is NULL");
        return 1;
    }
    return 0;
}

int replace(char *str, char from, char to) {
    for (int i = 0; str[i] != '\0' &&  str[i] != EOF; i++) {
        if (str[i] == from)
            str[i] = to;
    }
    return 0;
}
