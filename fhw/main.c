#include "main.h"

//login admin2
//password admin
int main() {
    // mem leak
    User_t *users_list = auth_init("files/users.csv");

    // !55!!memory leak!!!
    Book_t *books_list = book_init("files/books.csv");

    // mem leak!!
    Student_t *students_list = student_init("files/students.csv",
                                            "files/student_books.csv");
    
    User_t *user = auth(users_list);
    cli(user, &students_list, &books_list);

    book_save(books_list, "files/books.csv");
    student_save(students_list, "files/students.csv",
                                "files/student_books.csv");
    auth_save(users_list, "files/users.csv");
    log_msg("Terminated\n");
    return 0;
}
