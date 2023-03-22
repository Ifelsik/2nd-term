//
// Created by misha on 18.03.2023.
//

#ifndef FOO_H
#define FOO_H

#include <stdlib.h>
#include <string.h>

typedef struct date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
} date_t;

date_t set_date(const char data[]);

date_t difference(date_t begin, date_t end);

#endif //FOO_H
