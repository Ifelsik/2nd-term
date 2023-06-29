#include "foo.h"


date_t set_date(const char data[]) {
    date_t date;
    date.day = 0, date.month = 0, date.year = 0;
    date.hour = -1, date.minute = -1, date.second = -1;
    date.status = 1;
    for (int i = 0; data[i] != '\0'; i++) {
        if (!('0' <= data[i] && data[i] <= '9' || data[i] == '.' || data[i] == ':' || data[i] == ' ')) {
            date.status = 0;
            return date;
        }
    }
    for (int i = 0; data[i] != '\0'; i++) {
        char slice[5]; // because only 4 digits allowed by pattern
        int sub_date_i = 0;
        if (!date.day || !date.month || !date.year) {
            for (int j = i; data[j] != '.' && data[j] != ' ' && data[j] != '\0'; j++) {
                slice[sub_date_i] = data[j];
                sub_date_i++;
            }
            i += sub_date_i;
            if (!date.day) {
                date.day = atoi(slice);
            } else if (!date.month) {
                date.month = atoi(slice);
            } else if (!date.year) {
                date.year = atoi(slice);
            }
            memset(slice, '\0', strlen(slice));
        } else if (date.hour < 0 || date.minute < 0 || date.second < 0) {
            for (int k = i; data[k] != ':' && data[k] != ' ' && data[k] != '\0'; k++) {
                slice[sub_date_i] = data[k];
                sub_date_i++;
            }
            i += sub_date_i;
            if (date.hour < 0) {
                date.hour = atoi(slice);
            } else if (date.minute < 0) {
                date.minute = atoi(slice);
            } else if (date.second < 0) {
                date.second = atoi(slice);
            }
        }
    }
    if (date.day > 31 || date.month > 12 || date.hour > 23 || date.minute > 59 || date.second > 59) {
        date.status = 0;
    }
    return date;
}

date_t difference(date_t begin, date_t end) {
    date_t result;
    result.day = 0, result.month = 0, result.year = 0;
    result.hour = 0, result.minute = 0, result.second = 0;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dif_in_days = (end.year - begin.year) * 365 + (end.day - begin.day);
    for (int i = 0; i < end.month; i++) {
        dif_in_days += days_in_month[i];
    }
    for (int i = 0; i < begin.month; i++) {
        dif_in_days -= days_in_month[i];
    }
    int dif_in_time = (end.hour - begin.hour) * 60 * 60 + (end.minute - begin.minute) * 60 + (end.second - begin.second);
    if (dif_in_time < 0) {
        dif_in_days--;
        dif_in_time = 24 * 60 * 60 + dif_in_time;
    }
    result.hour = dif_in_time / 60 / 60;
    result.minute = dif_in_time % 60 / 60;
    result.second = dif_in_time % 60;
    result.year = dif_in_days / 365;
    result.month = dif_in_days % 365 / 30;
    result.day = dif_in_days % 365 % 30;
    return result;
}
