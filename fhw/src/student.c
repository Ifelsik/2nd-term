#include "../include/student.h"

Student_t* student_init(const char *student_path, const char *student_book_path) {
    FILE *file = fopen(student_path, "r");
    
    if (NULL == file) {
        err_msg("In func 'student_init': 'file' opening err");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    int file_len = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *line = (char*) calloc(file_len, sizeof(char));
    
    if (NULL == line) {
        err_msg("In func 'student_init': 'line' calloc err");
        exit(EXIT_FAILURE);
    }

    Student_t *students_list = NULL;
    Student_t *temp = NULL;

    while (fgets(line, file_len, file) != NULL) {
        students_list = (Student_t*) malloc(sizeof(Student_t));
        if (NULL == students_list) {
            err_msg("In func 'student_list': 'students_list' malloc err");
            exit(EXIT_FAILURE);
        }
        students_list->next = temp;
        students_list->prev = NULL;
        if (NULL != temp) {
            temp->prev = students_list;
        }
        temp = students_list;

        students_list->rb_num = (char*) calloc(file_len, sizeof(char));
        students_list->name = (char*) calloc(file_len, sizeof(char));
        students_list->surname = (char*) calloc(file_len, sizeof(char));
        students_list->faculty = (char*) calloc(file_len, sizeof(char));
        students_list->speciality = (char*) calloc(file_len, sizeof(char));
        
        if (NULL == students_list->rb_num) {
            err_msg("In func 'student_init': 'students_list->rb_num' calloc err");
            exit(EXIT_FAILURE);
        }
        if (NULL == students_list->name) {
            err_msg("In func 'student_init': 'students_list->name' calloc err");
            exit(EXIT_FAILURE);
        }
        if (NULL == students_list->surname) {
            err_msg("In func 'student_init': 'students_list->surname' calloc err");
            exit(EXIT_FAILURE);
        }
        if (NULL == students_list->faculty) {
            err_msg("In func 'student_init': 'students_list->faculty' calloc err");
            exit(EXIT_FAILURE);
        }
        if (NULL == students_list->speciality) {
            err_msg("In func 'student_init': 'students_list->speciality' calloc err");
            exit(EXIT_FAILURE);
        }

        char *substr = (char*) calloc (file_len, sizeof(char));
        if (NULL == substr) {
            err_msg("In func 'student_init': 'substr' calloc err");
            exit(EXIT_FAILURE);
        }
        strcpy(substr, line);
        
        students_list->rb_num = strtok(substr, ",");
        students_list->name = strtok(NULL, ","); //  what?
        students_list->surname = strtok(NULL, ",");
        students_list->faculty = strtok(NULL, ",");
        students_list->speciality = strtok(NULL, ",");
        // yeah, memory leak!!!!
        //free(substr);  // what the fuck is going here?
        substr = NULL;
    }
    log_msg("'student_init': success");
    fclose(file);


    FILE *file_sb = fopen(student_book_path, "r"); 
    if (NULL == file_sb) {
        err_msg("In func 'student_init': 'file_sb' opening err");
        exit(EXIT_FAILURE);
    }

    fseek(file_sb, 0, SEEK_END);
    int file_sb_len = ftell(file_sb);
    fseek(file_sb, 0, SEEK_SET);


    while (fgets(line, file_sb_len, file_sb) != NULL) {
        char *substr = (char*) calloc(file_sb_len, sizeof(char));  // memory leak!!!
        if (NULL == substr) {
            err_msg("In func 'student_init': 'substr' calloc err");
            exit(EXIT_FAILURE);
        }
        strcpy(substr, line);

        unsigned long long isbn = atoll(strtok(substr, ","));

        char *rb_num = (char*) calloc(file_sb_len, sizeof(char));
        if (NULL == rb_num) {
            err_msg("In func 'student_list': 'rb_num' calloc err");
            exit(EXIT_FAILURE);
        }
        rb_num = strtok(NULL, ",");

        Student_t *student = student_find(students_list, rb_num);
        if (NULL == student) {
            err_msg("In func 'student_init': 'student' isn't found");
            exit(EXIT_FAILURE);
        }

        StudentBook_t *temp = student->book_list;  // can be a NULL

        student->book_list = (StudentBook_t*) malloc(sizeof(StudentBook_t));
        student->book_list->isbn = isbn;
        student->book_list->return_date = (char*) calloc(sizeof(file_sb_len), sizeof(char));

        if (NULL == student->book_list->return_date) {
            err_msg("In func 'student_init': 'student->book_list->return_date' calloc err");
            exit(EXIT_FAILURE);
        }

        student->book_list->return_date = strtok(NULL, ",");

        if (temp != NULL)
            temp->prev = student->book_list;
        student->book_list->next = temp;
    }

    free(line);
    return students_list;
}

Student_t* student_find(Student_t *students_list, const char *rb_num) {
    while (students_list != NULL) {
        if (!strcmp(students_list->rb_num, rb_num))
            return students_list;
        students_list = students_list->next;
    }
    return NULL;
} 

void student_add(Student_t **students_list_ptr) {
    char *rb_num = (char*) calloc(BASE_STRING_LEN, sizeof(char));
    if (NULL == rb_num) {
        err_msg("'student_add': 'rb_num' calloc err");
        log_msg("'student_add': 'rb_num' calloc err");
        return;
    }
    printf("Enter record book:\n");
    scanf("%s", rb_num);
    if (student_find(*students_list_ptr, rb_num) != NULL) {
        err_msg("'student_add': student exists");
        log_msg("'student_add': student exists");
        return;
    }

    Student_t *student = (Student_t*) malloc(sizeof(Student_t));
    if (NULL == student) {
        err_msg("'student_add': 'student' malloc err");
        log_msg("'student_add': 'student' malloc err");
        return;
    }
    
    student->rb_num = rb_num;
    student->surname = (char*) calloc(BASE_STRING_LEN, sizeof(char));
    student->name = (char*) calloc(BASE_STRING_LEN, sizeof(char));
    student->faculty = (char*) calloc(BASE_STRING_LEN, sizeof(char));
    student->speciality = (char*) calloc(BASE_STRING_LEN, sizeof(char));
    
    if (NULL == student->surname) {
        err_msg("'student_add': 'student->surname' calloc err");
        log_msg("'student_add': 'student->surname' calloc err");
        return;
    }
    if (NULL == student->name) {
        err_msg("'student_add': 'student->name' calloc err");
        log_msg("'student_add': 'student->name' calloc err");
        return;
    }
    if (NULL == student->faculty) {
        err_msg("'student_add': 'student->faculty' calloc err");
        log_msg("'student_add': 'student->faculty' calloc err");
        return;
    }
    if (NULL == student->speciality) {
        err_msg("'student_add': 'student->speciality' calloc err");
        log_msg("'student_add': 'student->speciality' calloc err");
        return;
    }

    printf("Enter surname:\n");
    scanf("%s", student->surname);
    printf("Enter name:\n");
    scanf("%s", student->name);
    printf("Enter faculty:\n");
    scanf("%s", student->faculty);
    printf("Enter speciality:\n");
    scanf(" %[^\n]s", student->speciality);

    
    student->next = (*students_list_ptr);
    (*students_list_ptr)->prev = student;
    (*students_list_ptr) = student;

    log_msg("'student_add': success");
}

/**
 * @brief deletes student
 * @param students_list ptr to head of students list (Student_t *)
 * @param rb_num record book's number (char *)
*/
void student_del(Student_t **students_list_ptr, const char* rb_num) {
    Student_t *student = student_find(*students_list_ptr, rb_num);
    if (NULL == student) {
        err_msg("'student_del' - The operation can't be executed:\
                a student with such rb_num doesn't exists");
        return;
    }

    if (NULL != student->book_list) {
        err_msg("'student_del' - The operation can't be executed:\
                a student have at least one book");
        return;
    }

    // left edge (head)
    if (student->prev == NULL && student->next != NULL) {
        (*students_list_ptr)->next->prev = NULL;
        (*students_list_ptr) = student->next;
    } 
    // right edge
    else if (student->next == NULL && student->prev != NULL){
        student->prev->next = NULL;
    }
    // for any
    else {
        student->prev->next = student->next;
        student->next->prev = student->prev;
    }

    free(student->rb_num);
    free(student->name);
    free(student->surname);
    free(student->faculty);
    free(student->speciality);
    
    log_msg("'student_del' - success");
}

void student_edit(Student_t *students_list, char *rb_num) {
    Student_t *student = student_find(students_list, rb_num);
    if (NULL == student) {
        err_msg("'student_edit' err: student doesn't exist");
        log_msg("'student_edit' err: student doesn't exist");
        return;
    }    
    printf("Enter new student's surname:\n");
    scanf("%s", student->surname);
    printf("Enter new student's name:\n");
    scanf("%s", student->name);
    printf("Enter new student's faculty:\n");
    scanf("%s", student->faculty);
    printf("Enter new student's speciality:\n");
    scanf("%s", student->speciality);

    printf("edited successfully\n");
    log_msg("'student_edit' edited successfully");
}

void student_info(Student_t *students_list, char *rb_num) {
    Student_t *student = student_find(students_list, rb_num);
    if (NULL == student) {
        log_msg("'student_info' err: the student doesn't exist\n");
        err_msg("'student_info' err: the student doesn't exist\n");
    }

    printf("Record book: %s\n", student->rb_num);
    printf("Surname: %s\n", student->surname);
    printf("Name: %s\n", student->name);
    printf("Faculty: %s\n", student->faculty);
    printf("Speciality: %s\n", student->speciality);
    
}

void student_findBySurname(Student_t *students_list, char *surname) {
    int counter = 0;
    while (students_list != NULL) {
        if (!strcmp(students_list->surname, surname)) {
            printf("%d. \n", counter++);
            student_info(students_list, students_list->rb_num);
            printf("====================\n\n");
        }
        students_list = students_list->next;
    }
    if (counter == 0) {
        log_msg("'student_findBySurname' err: the student doesn't exist");
        err_msg("'student_findBySurname' err: the student doesn't exist");
        return;
    }
    log_msg("'student_findBySurname' success");
}

void student_save(Student_t *students_list,
                const char *students_saving_path,
                const char *students_book_saving_path) {
    if (NULL == students_list) {
        err_msg("'student_save': 'students_list' is NULL");
        log_msg("'student_save': 'students_list' is NULL");
        return;
    }

    FILE *file_students = fopen(students_saving_path, "w+");
    if (NULL == file_students) {
        err_msg("'student_save': 'file_students' opening err");
        log_msg("'student_save': 'file_students' opening err");
        return;
    }
    
    Student_t *student = students_list;
    while (student != NULL) {
        fprintf(file_students, "%s,%s,%s,%s,%s",
                student->rb_num,
                student->name,
                student->surname,
                student->faculty,
                student->speciality);
        student = student->next;
    }
    
    fclose(file_students);
    printf("'student_save': students' data successfully saved\n");
    log_msg("'student_save': students' data successfully saved");


    FILE *file_studentsBooks = fopen(students_book_saving_path, "w+");
    if (NULL == file_studentsBooks) {
        err_msg("'student_save': 'file_studentsBooks' opening err");
        log_msg("'student_save': 'file_studentsBooks' opening err");
        return;
    }
    while (students_list != NULL) {
        StudentBook_t *books_list = students_list->book_list;
        while (books_list != NULL) {
            fprintf(file_studentsBooks, "%llu,%s,%s",
                    books_list->isbn,
                    students_list->rb_num,
                    books_list->return_date);
            books_list = books_list->next; 
        }
        students_list = students_list->next;
    }
    fclose(file_studentsBooks);
    printf("'student_save': students' book data successfully saved\n");
    log_msg("'student_save': students' book data successfully saved");
}
