#include "include/db_utils.h"
#include "include/file_utils.h"

// login: admin, password: admin
int main(int argc, char **argv) {
    char *path = argv[1];
    char **lines = NULL;
    char *login = NULL;
    char *password = NULL;
    char *filebuf = NULL;
    int number_of_lines = 0;

    int res1 = 0;
    int res2 = 0;
    int auth_res = 0;

    tStudent students[DB_SIZE];
    for (int i = 0; i < DB_SIZE; ++i) {
        students[i] = empty_note;
    }

    if (readFile(path, &filebuf) != 0) {
        printf("Error during reading file");
        return 1;
    }
    for (int i = 0; filebuf[i] != '\0'; i++) {
        if (filebuf[i] == '\n' || filebuf[i + 1] == '\0')
            number_of_lines++;
    }

    res1 = readLinesFromFile(path, &lines);
    assert(res1 == 0);

    res2 = parseData(lines, number_of_lines, students);
    assert(res2 == 0);

/*    FILE *file_p = NULL;
    file_p = fopen(path, "a+");
    add((void *) &students);
    tStudent student = students[get_max_id(students)];
    if (NULL == file_p)
        return 1;
    fprintf(file_p, "\n%d:%s:%d:%.2f:%s:", student.id, student.name, student.rb_num,
            student.avrg_mark, student.login);
    fprintf(file_p,"%s", student.password_hash);
    fclose(file_p);
*/

    login = (char*) malloc(sizeof(char) * BASE_LEN);
    password = (char*) malloc(sizeof(char) * BASE_LEN);
    do {
        printf("Enter login:\n");
        scanf("%s", login);
        printf("Enter password:\n");
        scanf("%s", password);
        fflush(stdin);
        auth_res = auth(students, login, password);
    } while (auth_res != 0);
    free(login);
    free(password);

    puts("Enter 1 to add new record to db");
    puts("Enter 2 to view record by id");
    puts("Enter 3 to delete record by id");
    puts("Enter 4 to show all records");
    puts("Enter Q to quit");
    char cmd;
    while ((cmd = getchar()) && cmd != 'Q') {
        fflush(stdin);
        switch (cmd) {
            case '1': {
                FILE *file_p = NULL;
                file_p = fopen(path, "a+");
                add((void *) &students);
                tStudent student = students[get_max_id(students)];
                if (NULL == file_p)
                    return 1;
                fprintf(file_p, "\n%d:%s:%d:%.2f:%s:%s", student.id, student.name, student.rb_num,
                        student.avrg_mark, student.login, student.password_hash);
                fclose(file_p);
                break;
            }
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
