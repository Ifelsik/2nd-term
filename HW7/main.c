#include "main.h"

int main() {
    char *path = "../files/students.txt";
    char **lines = NULL;
    int number_of_students = 0;
    Student_t **students = NULL;

    lines = readLinesFromFile(path);
    number_of_students = getNumberOfLines(path);
    students = (Student_t**) malloc(sizeof(Student_t*) * number_of_students);
    parseData(lines, number_of_students, students);

    Stats_t stats_mark;  // Object declaration
    StatsMark_init(&stats_mark);  // Object initialization
    StatsMark_set(&stats_mark, students, number_of_students);  // Set object value
    StatsMark_show_stats(&stats_mark);
    StatsMark_free(&stats_mark);  // Object destruction

    Stats_t stats_attendance;  // Object declaration
    StatsAttendance_init(&stats_attendance);  // Object initialization
    StatsAttendance_set(&stats_attendance, students, number_of_students);  // Set object value
    StatsAttendance_show_stats(&stats_attendance);
    StatsAttendance_free(&stats_attendance);  // Object destruction
    return 0;
}