//
// Created by misha on 07.05.2023.
//

#include "../include/attendance_class.h"

// constructor
void StatsAttendance_init(Stats_t *this) {
    this->__impl = malloc(sizeof(StatsAttendance_t));
    StatsAttendance_t *attendance_this = (StatsAttendance_t *) this->__impl;

    //init private attributes
    attendance_this->students = NULL;
    attendance_this->number_of_students = 0;
    attendance_this->average_attendance = 0;

    //init public methods
    this->set_attrs = &StatsAttendance_set;
    this->show_stats = &StatsAttendance_show_stats;
}

// setter
void StatsAttendance_set(Stats_t *this, Student_t **students, int total_students) {
    int summary_attendance = 0;
    if (this->__impl == NULL) {
        fprintf(stderr, "ERROR: Uninitialized object of StatsAttendance_t class\n");
        exit(EXIT_FAILURE);
    }
    StatsAttendance_t *attendance_this = (StatsAttendance_t *) this->__impl;
    attendance_this->students = students;
    attendance_this->number_of_students = total_students;
    for (int i = 0; i < total_students; i++) {
        summary_attendance += students[i]->attendance;
    }
    attendance_this->average_attendance = (float) summary_attendance / total_students;
}

void StatsAttendance_show_stats(Stats_t *this) {
    if (this->__impl == NULL) {
        fprintf(stderr, "ERROR: Uninitialized object of StatsAttendance_t class\n");
        exit(EXIT_FAILURE);
    }
    StatsAttendance_t *attendance_this = (StatsAttendance_t *) this->__impl;
    Student_t **sorted_students = (Student_t **) malloc(sizeof(Student_t *) * attendance_this->number_of_students);
    for (int i = 0; i < attendance_this->number_of_students; i++) {
        sorted_students[i] = (Student_t *) malloc(sizeof(Student_t));
        *(sorted_students[i]) = *(attendance_this->students[i]);
    }
    for (int i = 0; i < attendance_this->number_of_students; i++) {
        for (int j = i; j < attendance_this->number_of_students; j++) {
            if (sorted_students[j]->attendance > sorted_students[i]->attendance) {
                Student_t *tmp = sorted_students[i];
                sorted_students[i] = sorted_students[j];
                sorted_students[j] = tmp;
            }
        }
    }
    printf("Sorted by attendance\n");
    for (int i = 0; i < attendance_this->number_of_students; i++) {
        printf("ID: %d\n", sorted_students[i]->id);
        printf("name: %s\n", sorted_students[i]->name);
        printf("Record number: %d\n", sorted_students[i]->rb_num);
        printf("Attendance: %d\n", sorted_students[i]->attendance);
        printf("Average mark: %.2f\n", sorted_students[i]->average_mark);
        printf("Login: %s\n\n", sorted_students[i]->login);
    }
}

// destructor
void StatsAttendance_free(Stats_t *this) {
    if (this->__impl == NULL) {
        fprintf(stderr, "ERROR: Uninitialized object of StatsAttendance_t class\n");
        exit(EXIT_FAILURE);
    }
    free(this->__impl);
}
