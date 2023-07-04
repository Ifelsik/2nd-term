//
// Created by misha on 24.05.2023.
//

#ifndef HW9_STACK_H
#define HW9_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack_s {
    int value;
    struct Stack_s *next;
} Stack_t;

typedef struct Queue_s {
    Stack_t *left;
    Stack_t *right;
} Queue_t;

void stackPush(Stack_t **head, int value);

int stackPop(Stack_t **head);

void stackDestroy(Stack_t *head);

Queue_t *queueInit();

bool queueIsEmpty(Queue_t *queue);

void queuePush(Queue_t *queue, int value);

int queuePop(Queue_t *queue);

void queueDestroy(Queue_t *queue);

#endif //HW9_STACK_H
