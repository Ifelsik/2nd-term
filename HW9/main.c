#include "main.h"

int main(int argc, char *argv[]) {
    int students_remained = 0;
    int students_returned = 0;
    char *line1 = NULL;
    char *line2 = NULL;
    char *path = NULL;
    FILE *file_p = NULL;
    Stack_t *bakery = NULL;
    Queue_t *students = queueInit();
    Data_t *students_data = dataInit();
    Data_t *bakery_data = dataInit();

    if (argc != 2) {
        fprintf(stderr, "In function main: incorrect number of arguments\n");
        exit(EXIT_FAILURE);
    }
    path = argv[1];

    file_p = fopen(path, "r");
    if (file_p == NULL) {
        fprintf(stderr, "File %s can't be opened\n", path);
        exit(EXIT_FAILURE);
    }
    line1 = readLine(file_p);
    line2 = readLine(file_p);
    fclose(file_p);

    students_data = dataParseFromString(students_data, line1, ",");
    bakery_data = dataParseFromString(bakery_data, line2, ",");

    students_remained = students_data->elements;
    for (int i = students_remained - 1; i >= 0; i--)
        stackPush(&bakery, dataRead(bakery_data, i));
    for (int i = 0; i < students_remained; i++)
        queuePush(students, dataRead(students_data, i));

    dataDestroy(students_data);
    dataDestroy(bakery_data);

    while (students_returned < students_remained) {
        int student = queuePop(students);
        int bun = stackPop(&bakery);
        if (student == bun) {
            students_remained--;
            students_returned = 0;
        }
        else {
            queuePush(students, student);
            stackPush(&bakery, bun);
            students_returned++;
        }
    }

    printf("There are %d students in queue remained\n", students_remained);
    queueDestroy(students);
    stackDestroy(bakery);
    return 0;
}
