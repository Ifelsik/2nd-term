//
// Created by misha on 07.05.2023.
//

#ifndef HW7_FILE_H
#define HW7_FILE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BASE_LEN 256

char* readFile(char *path);

int appendToFile(char *path, char *text);

int getNumberOfLines(char *path);

char** readLinesFromFile(char *path);

#endif //HW7_FILE_H
