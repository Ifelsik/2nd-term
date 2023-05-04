//
// Created by misha on 04.05.2023.
//

#ifndef RK_2_STUDENT_H
#define RK_2_STUDENT_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int student_id;
    int student_record_number;
    int student_attendance;
    double student_rating;
    char *student_name;
    char *student_login;
} Student_t;

Student_t* findStudentByID(Student_t **students_array, int array_size, int id);

void printStudent(Student_t* student);

void printStudentAll(Student_t **students, int array_size);

#endif //RK_2_STUDENT_H
