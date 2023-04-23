#ifndef DB_UTILS_H
#define DB_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>
#include "../sha256/sha-256.h"

#define DB_SIZE 50
#define BASE_LEN 256

typedef struct Student {
    int id;
    char *name;
    int rb_num;
    float avrg_mark;
    char *login;
    char *password_hash;
} tStudent;


static tStudent empty_note = {-1, NULL, -1, -1, NULL, NULL};

int auth(tStudent *students, char *login, char *password);

int parseData (char **data, int data_len, tStudent *students);

int get_max_id(tStudent *students);

void add(tStudent *students);

void view(tStudent *students);

void del(tStudent *students);

void view_all(tStudent *students);

#endif //DB_UTILS_H
