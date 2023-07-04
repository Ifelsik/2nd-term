//
// Created by misha on 07.05.2023.
//

#ifndef HW7_STUDENTS_H
#define HW7_STUDENTS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int id;
    int rb_num;
    int attendance;
    float average_mark;
    char *name;
    char *login;
    char *password_hash;
} Student_t;

int parseData(char **lines, int data_len, Student_t **students);

#endif //HW7_STUDENTS_H
