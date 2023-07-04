//
// Created by misha on 07.05.2023.
//

#ifndef HW7_MARK_CLASS_H
#define HW7_MARK_CLASS_H

#include "class.h"
#include "students.h"

typedef struct {
    Student_t **students;
    int number_of_students;
    float average_mark;
} StatsMark_t;

void StatsMark_init(Stats_t *this);

void StatsMark_set(Stats_t *this, Student_t **students, int total_students);

void StatsMark_show_stats(Stats_t *this);

void StatsMark_free(Stats_t *this);

#endif //HW7_MARK_CLASS_H
