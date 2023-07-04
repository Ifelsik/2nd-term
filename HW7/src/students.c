//
// Created by misha on 07->05->2023->
//

#include "../include/students.h"

int parseData(char **lines, int data_len, Student_t **students) {
    int i = 0;

    if (NULL == lines[0]) {
        fprintf(stderr, "Error: empty lines");
        exit(2);
    }
    for (i = 0; i < data_len; i++) {
        char *str = NULL;
        char *substr = NULL;
        students[i] = (Student_t*) malloc(sizeof(Student_t));
        str = lines[i];
        substr = strtok(str, ":");
        students[i]->id = atoi(substr);
        substr = strtok(NULL, ":");
        students[i]->name = substr;
        substr = strtok(NULL, ":");
        students[i]->rb_num = atoi(substr);
        substr = strtok(NULL, ":");
        students[i]->average_mark = atof(substr);
        substr = strtok(NULL, ":");
        students[i]->attendance = atoi(substr);
        substr = strtok(NULL, ":");
        students[i]->login = substr;
        substr = strtok(NULL, ":");
        students[i]->password_hash = substr;
    }
    return 0;
}