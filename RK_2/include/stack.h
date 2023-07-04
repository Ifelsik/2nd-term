//
// Created by misha on 04.05.2023.
//

#ifndef RK_2_STACK_H
#define RK_2_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/student.h"

typedef struct Stack_s {
    void *value;
    struct Stack_s *next;
} Stack_t;

void stackPush(Stack_t **head, void *value);

void* stackPop(Stack_t **head);

void stackPopAll(Stack_t **head, void (*printing_function)(Student_t *student));

#endif //RK_2_STACK_H
