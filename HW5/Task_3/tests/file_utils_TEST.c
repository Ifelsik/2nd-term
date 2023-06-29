//
// Created by misha on 22.04.2023.
//
#include "../include/file_utils.h"

int main() {
    char *path = "../files/database1.txt";
    char *filebuf = NULL;
    char **lines = NULL;
    int res = 0;
    res = readFile(path, &filebuf);
    puts(filebuf);
    printf("Exit status: %d\n", res);
    readLinesFromFile(path, &lines);
    puts(lines[0]);
    return 0;
}
