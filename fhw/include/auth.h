#ifndef AUTH_H
#define AUTH_H

#include "../sha-2/sha-256.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define BASE_LEN 32

#define err_msg(error) fprintf(stderr, "%s\n", error)

#define log_msg(msg) do {\
        FILE *f = fopen("files/library.log", "a+");\
        if (f == NULL)\
            fprintf(stderr, "ERROR: can't open log file\n");\
        time_t now;\
        time(&now);\
        char time_s[24];\
        strftime(time_s, 24, "%d.%m.%Y %X", localtime(&now));\
        fprintf(f, "%s,%s\n", time_s, msg);\
        fclose(f);\
    } while(0)

typedef struct User_t {
    char *login;
    char *password_hash;
    int students_access;
    int books_access;
    struct User_t *next;
    struct User_t *prev;
} User_t;

User_t* auth_init(char *users_path);

User_t* auth_findUserByLogin(User_t *users_list, char *login);

int auth_checkUser(User_t *users_list, char *login, char *password_hash);

User_t* auth(User_t *users_list);

void auth_save(User_t *users_list, char *saving_path);

#endif