//
// Created by misha on 04.05.2023.
//

#include "../include/student.h"

Student_t* findStudentByID(Student_t **students_array, int array_size, int id) {
    for (int i = 0; i < array_size; i++) {
        if (students_array[i]->student_id == id)
            return students_array[i];
    }
    printf("Student with this ID doesn't exist!\n");
    return NULL;
}

void printStudent(Student_t* student) {
    printf("ID: %d\n", student->student_id);
    printf("name: %s\n", student->student_name);
    printf("record_number: %d\n", student->student_record_number);
    printf("rating: %.2f\n", student->student_rating);
    printf("attendance: %d\n", student->student_attendance);
    printf("login: %s\n", student->student_login);
    putchar('\n');
}

void printStudentAll(Student_t **students, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printStudent(students[i]);
    }
}