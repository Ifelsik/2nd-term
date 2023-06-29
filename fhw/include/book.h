#ifndef BOOK_H
#define BOOK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

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


#define BOOK_H_BASE_LEN 128
#define BOOK_H_BASE_ARRAY_LEN 64

typedef struct Book_s {
    unsigned long long isbn;
    char *authors;
    char *title;
    unsigned int total;
    unsigned int availible;
    struct Book_s *next;
    struct Book_s *prev;
} Book_t;

struct ArrayBook_s {
    Book_t **books_array;
    int size;
};

Book_t* book_init(const char *books_path);

Book_t* book_find(Book_t *books_list, unsigned long long isbn);

bool book_isExist(Book_t *books_list, unsigned long long isbn);

void book_add(Book_t **books_list_ptr); // probably should be changed

void book_del(Book_t **books_list_ptr, unsigned long long isbn);

void book_info(Book_t *books_list, unsigned long long isbn);

void book_infoAll(Book_t *books_list);

void book_edit(Book_t *books_list, unsigned long long isbn);

void book_save(Book_t *books_list, const char *saving_path);

#endif
