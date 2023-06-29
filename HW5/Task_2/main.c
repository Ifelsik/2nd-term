#include "./include/main.h"


int main() {
    tNode *head = NULL;
    char *buf = NULL;
    char *str;
    int id = 0;
    
    readfile("..\\files\\file.txt", &buf);

    replace(buf, '\n', ' ');
    
    str = strtok(buf, " ");

    while (str != NULL) {
        int j = 0;
        for (; str[j] != '\0'; j++) {
            if (isdigit(str[j])) {
                break;
            }
        }
        if (!isdigit(str[j])) {
            insert(&head, str, id++);
        }
        str = strtok(NULL, " ");
    }

    printf("Before:\n");
    tNode* cur = head;
    while (cur != NULL) {
        printf("id: %d, value: %s\n", cur->node_index, cur->value);
        cur = cur->next;
    }

    tNode* current = head;
    tNode* tmp = head->next;
    while (tmp != NULL && tmp->next != NULL) {
        tNode* pre_end = head;
        while (pre_end->next->next != NULL) {
            pre_end = pre_end->next;
        }
        current->next = pre_end->next;
        current->next->next = tmp;
        pre_end->next = NULL;
        current = tmp;
        tmp = tmp->next;
    }
    
    printf("\nAfter:\n");
    cur = head;
    while (cur != NULL) {
        printf("id: %d, value: %s\n", cur->node_index, cur->value);
        cur = cur->next;
    }
    
    return 0;
}
