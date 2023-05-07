//
// Created by misha on 07.05.2023.
//

#ifndef HW7_STATS_CLASS_H
#define HW7_STATS_CLASS_H

#include "students.h"

typedef struct Stats_t {
    //private
    void *__impl;

    //public
    void (*set_attrs)(struct Stats_t *, Student_t **students, int total_students);
    void (*show_stats)(struct Stats_t *);
} Stats_t;

#endif //HW7_STATS_CLASS_H
