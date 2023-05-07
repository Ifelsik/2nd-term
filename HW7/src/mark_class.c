//
// Created by misha on 07.05.2023.
//

#include "../include/mark_class.h"

// constructor
void StatsMark_init(Stats_t *this) {
    this->__impl = malloc(sizeof(StatsMark_t));
    StatsMark_t *mark_this = (StatsMark_t *) this->__impl;

    //init private attributes
    mark_this->students = NULL;
    mark_this->number_of_students = 0;
    mark_this->average_mark = 0;

    //init public methods
    this->set_attrs = &StatsMark_set;
    this->show_stats = &StatsMark_show_stats;
}

// setter
void StatsMark_set(Stats_t *this, Student_t **students, int total_students) {
    float summary_marks = 0;
    if (this->__impl == NULL) {
        fprintf(stderr, "ERROR: Uninitialized object of StatsMark_t class\n");
        exit(EXIT_FAILURE);
    }
    StatsMark_t *mark_this = (StatsMark_t *) this->__impl;
    mark_this->students = students;
    mark_this->number_of_students = total_students;
    for (int i = 0; i < total_students; i++) {
        summary_marks += students[i]->average_mark;
    }
    mark_this->average_mark = summary_marks / total_students;
}

void StatsMark_show_stats(Stats_t *this) {
    if (this->__impl == NULL) {
        fprintf(stderr, "ERROR: Uninitialized object of StatsMark_t class\n");
        exit(EXIT_FAILURE);
    }
    StatsMark_t *mark_this = (StatsMark_t *) this->__impl;
    Student_t **sorted_students = (Student_t **) malloc(sizeof(Student_t *) * mark_this->number_of_students);
    for (int i = 0; i < mark_this->number_of_students; i++) {
        sorted_students[i] = (Student_t *) malloc(sizeof(Student_t));
        *(sorted_students[i]) = *(mark_this->students[i]);
    }
    for (int i = 0; i < mark_this->number_of_students; i++) {
        for (int j = i; j < mark_this->number_of_students; j++) {
            if (sorted_students[j]->average_mark > sorted_students[i]->average_mark) {
                Student_t *tmp = sorted_students[i];
                sorted_students[i] = sorted_students[j];
                sorted_students[j] = tmp;
            }
        }
    }
    printf("Sorted by average mark\n");
    for (int i = 0; i < mark_this->number_of_students; i++) {
        printf("ID: %d\n", sorted_students[i]->id);
        printf("name: %s\n", sorted_students[i]->name);
        printf("Record number: %d\n", sorted_students[i]->rb_num);
        printf("Attendance: %d\n", sorted_students[i]->attendance);
        printf("Average mark: %.2f\n", sorted_students[i]->average_mark);
        printf("Login: %s\n\n", sorted_students[i]->login);
    }
}

// destructor
void StatsMark_free(Stats_t *this) {
    if (this->__impl == NULL) {
        fprintf(stderr, "ERROR: Uninitialized object of StatsMark_t class\n");
        exit(EXIT_FAILURE);
    }
    free(this->__impl);
}

