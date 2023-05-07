//
// Created by misha on 07.05.2023.
//

#ifndef HW7_ATTENDANCE_CLASS_H
#define HW7_ATTENDANCE_CLASS_H

#include "class.h"
#include "students.h"

typedef struct {
    Student_t **students;
    int number_of_students;
    float average_attendance;
} StatsAttendance_t;

void StatsAttendance_init(Stats_t *this);

void StatsAttendance_set(Stats_t *this, Student_t **students, int total_students);

void StatsAttendance_show_stats(Stats_t *this);

void StatsAttendance_free(Stats_t *this);

#endif //HW7_ATTENDANCE_CLASS_H
