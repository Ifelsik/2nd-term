#ifndef DB_UTILS_H
#define DB_UTILS_H

#include <stdio.h>
#include <string.h>

#define DB_SIZE 50

#define DEBUG 1

typedef struct Student {
    int id;
    char name[50];
    int rb_num;
    float avrg_mark;
} tStudent;

static tStudent empty_note = {-1, "", -1, -1};

int get_max_id(tStudent *students);

void add(tStudent *students);

void view(tStudent *students);

void del(tStudent *students);

void view_all(tStudent *students);

#endif //DB_UTILS_H
