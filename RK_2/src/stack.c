//
// Created by misha on 04.05.2023.
//

#include "../include/stack.h"

void stackPush(Stack_t **head, void *value) {
    Stack_t *new_head = NULL;
    new_head = (Stack_t*) malloc (sizeof(Stack_t));
    assert(new_head != NULL);
    new_head->value = value;
    new_head->next = *head;
    *head = new_head;
}

void* stackPop(Stack_t **head) {
    void *element_p = NULL;
    element_p = (*head)->value;
    *head = (*head)->next;
    return element_p;
}

void stackPopAll(Stack_t **head, void (*printing_function)(Student_t *student)) {
    while (*head != NULL) {
        void *element = stackPop(head);
        printing_function((Student_t*) element);
    }
}