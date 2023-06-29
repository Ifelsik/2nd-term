#include "db_utils.h"


int main() {
    tStudent students[50];
    for (int i = 0; i < DB_SIZE; ++i) {
        students[i] = empty_note;
    }
    #if DEBUG

    students[1].id = 3;
    strcpy(students[1].name, "Suleyman");
    students[1].rb_num = 3;
    students[1].avrg_mark = 4.9;
    students[0].id = 1;
    strcpy(students[0].name, "Misha");
    students[0].rb_num = 1;
    students[0].avrg_mark = 5.0;
    view_all((void*) &students);

    #endif

    puts("Enter 1 to add new record to db");
    puts("Enter 2 to view record by id");
    puts("Enter 3 to delete record by id");
    puts("Enter 4 to show all records");
    puts("Enter Q to quit");
    char cmd;
    while ((cmd = getchar()) && cmd != 'Q') {
        fflush(stdin);
        switch (cmd) {
            case '1':
                add((void*) &students);
                break;
            case '2':
                view((void*) &students);
                break;
            case '3':
                del((void*) &students);
                break;
            case '4':
                view_all((void*) &students);
                break;
            default:
                puts("Wrong operation. Try again");
        }
        puts("What do you want to do?");
    }
    return 0;
}
