//
// Created by misha on 04.05.2023.
//

#ifndef RK_2_FILE_H
#define RK_2_FILE_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define BASE_LEN 256

char* readFile(char *path);

int appendToFile(char *path, char *text);

char** readLinesFromFile(char *path);

#endif //RK_2_FILE_H
