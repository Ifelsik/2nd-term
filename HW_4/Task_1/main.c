#include "main.h"

int main(int argc, char *argv[]) {
    const char *date_begin = argv[1];
    const char *date_end = argv[2];
    date_t begin = set_date(date_begin);
    date_t end = set_date(date_end);
    if (begin.status && end.status) {
        date_t dif = difference(begin, end);
        printf("Difference between %s and %s (30 days in month!!)\n", date_end, date_begin);
        printf("%d.%d.%d %d:%d:%d\n", dif.day, dif.month, dif.year, dif.hour, dif.minute, dif.second);
    }
    else {
        puts("Doesn't conform to pattern or wrong data");
    }
    return 0;
}