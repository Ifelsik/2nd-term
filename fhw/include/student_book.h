#ifndef STUDENT_BOOK_H
#define STUDNET_BOOK_H

#include "book.h"
#include "student.h"

#define DATE_SIZE 16

void studentbook_takeBook(
                    Student_t *students_list, Book_t *books_list,
                    char *rb_num, unsigned long long isbn);

void studentbook_returnBook(
                    Student_t *students_list, Book_t *books_list,
                    char *rb_num, unsigned long long isbn);

void studentbook_showAllBooksAtStudent(
                    Student_t *students_list, Book_t *books_list,
                    char *rb_num);

void studentbook_showAllStudentsWithBook(
                    Student_t *students_list, Book_t *books_list,
                    unsigned long long isbn);

#endif