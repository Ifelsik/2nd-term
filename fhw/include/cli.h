#ifndef CLI_H
#define CLI_H

#include "auth.h"

#include "student_book.h"

void cli(User_t *user, Student_t **students_list_ptr, Book_t **books_list_ptr);

void cli_studentsMenu(Student_t **students_list_ptr); 

void cli_booksMenu(Book_t **books_list_ptr, Student_t **students_list_ptr);

#endif