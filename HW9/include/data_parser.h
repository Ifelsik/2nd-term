//
// Created by misha on 25.05.2023.
//

#ifndef HW9_DATA_PARSER_H
#define HW9_DATA_PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BASE_SIZE 64

typedef struct {
    int *array;
    int elements;
} Data_t;

Data_t* dataInit();

Data_t* dataParseFromString(Data_t *data, char *string, const char *sep);

int dataRead(Data_t *data, int index);

void dataDestroy(Data_t *data);

char* readLine(FILE *file_p);

#endif //HW9_DATA_PARSER_H
