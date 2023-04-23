//
// Created by misha on 20.04.2023.
//

#ifndef TASK_3_FILE_UTILS_H
#define TASK_3_FILE_UTILS_H

#include <stdlib.h>
#include <stdio.h>

#define BASE_LEN 256

int readFile(char *path, char **filebuf);

int appendToFile(char *path, char *text);

int readLinesFromFile(char *path, char ***lines);



#endif //TASK_3_FILE_UTILS_H
