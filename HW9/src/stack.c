#include "../include/stack.h"

void stackPush(Stack_t **head, int value) {
    Stack_t *new_head = NULL;
    new_head = (Stack_t*) malloc (sizeof(Stack_t));
    if (new_head == NULL) {
        fprintf(stderr, "Can't push into the stack!\n");
        exit(EXIT_FAILURE);
    }
    new_head->value = value;
    new_head->next = *head;
    *head = new_head;
}

int stackPop(Stack_t **head) {
    int value = (*head)->value;
    *head = (*head)->next;
    return value;
}

void stackDestroy(Stack_t *head) {
    while (head != NULL) {
        Stack_t *next = head->next;
        free(head);
        head = next;
    }
}

Queue_t *queueInit() {
    Queue_t *queue = (Queue_t*) malloc(sizeof(Queue_t));
    queue->left = NULL;
    queue->right = NULL;
    return queue;
}

bool queueIsEmpty(Queue_t *queue) {
    return (queue->left == NULL && queue->right == NULL) ? true : false;
}

void queuePush(Queue_t *queue, int value) {
    stackPush(&(queue->left), value);
}

int queuePop(Queue_t *queue) {
    if (queue->right == NULL) {
        if (queue->left == NULL) {
            fprintf(stderr, "queue is empty!\n");
            exit(EXIT_FAILURE);
        }
        while (queue->left != NULL)
            stackPush(&(queue->right), stackPop(&(queue->left)));
    }
    return stackPop(&(queue->right));
}

void queueDestroy(Queue_t *queue) {
    stackDestroy(queue->left);
    stackDestroy(queue->right);
    free(queue);
}