#ifndef STUDENT_H
#define STUDENT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define BASE_STRING_LEN 128

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


typedef struct Student_t {
    char *rb_num;
    char *name;
    char *surname;
    char *faculty;
    char *speciality;
    struct StudentBook_t *book_list;
    struct Student_t *prev;
    struct Student_t *next;
} Student_t;

typedef struct StudentBook_t {
    unsigned long long isbn;
    char *return_date;
    struct StudentBook_t *prev;
    struct StudentBook_t *next;
} StudentBook_t;


Student_t* student_init(const char *student_path, const char *student_book_path);

Student_t* student_find(Student_t *students_list, const char *rb_num);

void student_add(Student_t **students_list_ptr);

void student_del(Student_t **students_list_ptr, const char* rb_num);

void student_edit(Student_t *students_list, char *rb_num);

void student_info(Student_t *students_list, char *rb_num);

void student_findBySurname(Student_t *students_list, char *surname);

void student_save(Student_t *students_list,
                const char *students_saving_path,
                const char *students_book_saving_path);

#endif