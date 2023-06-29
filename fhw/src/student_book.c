#include "../include/student_book.h"

void studentbook_takeBook(
                    Student_t *students_list, Book_t *books_list,
                    char *rb_num, unsigned long long isbn) {
    Student_t *student = student_find(students_list, rb_num);
    if (NULL == student) {
        err_msg("'studentbook_take': student isn't found");
        log_msg("'studentbook_take': student isn't found");
        return;
    }
    Book_t *book = book_find(books_list, isbn); 
    if (NULL == book) {
        err_msg("'studentbook_take': book isn't found");
        log_msg("'studentbook_take': book isn't found");
        return;
    }
    
    if (book->availible == 0) {
        err_msg("'studentbook_take': there isn't availible books");
        log_msg("'studentbook_take': there isn't availible books");
        return;
    }

    book->availible--;

    StudentBook_t *temp = student->book_list;
    student->book_list = (StudentBook_t*) malloc(sizeof(StudentBook_t));
    if (NULL == student->book_list) {
        err_msg("'studentbook_take': 'student->book_list' malloc err");
        log_msg("'studentbook_take': 'student->book_list' malloc err");
        return;
    }
    student->book_list->isbn = book->isbn;
    student->book_list->return_date = (char*) calloc(DATE_SIZE, sizeof(char));
    if (NULL == student->book_list->return_date) {
        err_msg("'studentbook_take': \
                'student->book_list->return_date' calloc err");
        log_msg("'studentbook_take': \
                'student->book_list->return_date' calloc err");
        return;
    }

    printf("Enter return date:\n");
    scanf("%s", student->book_list->return_date);
    student->book_list->next = temp;
    if (temp != NULL)  // temp can be a NULL when the user have no books before
        temp->prev = student->book_list;
    printf("'studentbook_take': the book has been issued\n");
    log_msg("'studentbook_take': success");
}

void studentbook_returnBook(
                    Student_t *students_list, Book_t *books_list,
                    char *rb_num, unsigned long long isbn) {
    Student_t *student = student_find(students_list, rb_num);
    if (NULL == student) {
        err_msg("'studentbook_returnBook': student isn't found");
        log_msg("'studentbook_returnBook': student isn't found");
        return;
    }
    Book_t *book = book_find(books_list, isbn); 
    if (NULL == book) {
        err_msg("'studentbook_returnBook': book isn't found");
        log_msg("'studentbook_returnBook': book isn't found");
        return;
    }
    
    StudentBook_t *student_books = student->book_list;

    bool have_book = false;
    while (student_books != NULL) {
        if (student_books->isbn == book->isbn) {
            have_book = true;
            break;
        }
        student_books = student_books->next;
    }
    
    if (!have_book) {
        err_msg("'studentbook_returnBook': student have no such book");
        log_msg("'studentbook_returnBook': student have no such book");
        return;
    }

    // left edge (head)
    if (student_books->prev == NULL && student_books->next != NULL) {
        student->book_list->next->prev = NULL;
        student->book_list = student_books->next;
    } 
    // right edge
    else if (student_books->next == NULL && student_books->prev != NULL){
        student_books->prev->next = NULL;
    }
    // for any
    else if (student_books->next != NULL && student_books->prev != NULL){
        student_books->prev->next = student_books->next;
        student_books->next->prev = student_books->prev;
    } else {
        student->book_list = NULL;
    }
    
    book->availible++;
    free(student_books->return_date);
    free(student_books);
    printf("'studentbook_returnBook': Success!\n");
    log_msg("'studentbook_returnBook': Success!");
}

void studentbook_showAllBooksAtStudent(
                    Student_t *students_list, Book_t *books_list,
                    char *rb_num) {
    Student_t *student = student_find(students_list, rb_num);
    if (NULL == student) {
        err_msg("'studentbook_showAllBooksAtStudent': student isn't found");
        log_msg("'studentbook_showAllBooksAtStudent': student isn't found");
        return;
    }

    StudentBook_t *book = student->book_list;
    while (book != NULL) {
        book_info(books_list, book->isbn);
        printf("Return date: %s\n", book->return_date);
        book = book->next;
    }
    log_msg("'studentbook_showAllBooksAtStudent': Success!");
}

void studentbook_showAllStudentsWithBook(
                    Student_t *students_list, Book_t *books_list,
                    unsigned long long isbn) {
    Book_t *book = book_find(books_list, isbn);
    if (NULL == book) {
        err_msg("'studentbook_showAllStudentsWithBook' err: book isn't found");
        log_msg("'studentbook_showAllStudentsWithBook' err: book isn't found");
        return;
    }
    if (book->total == book->availible) {
        err_msg("'studentbook_showAllStudentsWithBook': students haven't books");
        log_msg("'studentbook_showAllStudentsWithBook': students haven't books");
        return;
    }

    while (NULL != students_list) {
        StudentBook_t *books_at_student = students_list->book_list;
        while (NULL != books_at_student) {
            if (books_at_student->isbn == isbn) {
                printf("Return date: %s\n", books_at_student->return_date);
                student_info(students_list, students_list->rb_num);
            }
        }
    }
    log_msg("'studentbook_showAllStudentsWithBook': success");
}
