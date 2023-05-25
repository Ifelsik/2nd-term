//
// Created by misha on 25.05.2023.
//

#include "../include/data_parser.h"

Data_t* dataInit() {
    Data_t *data = (Data_t*) malloc(sizeof(Data_t));
    if (data == NULL) {
        fprintf(stderr, "Can't initialize Data_t object\n");
        exit(EXIT_FAILURE);
    }
    data->array = NULL;
    data->elements = 0;
    return data;
}

Data_t* dataParseFromString(Data_t *data, char *string, const char *sep) {
    char *substr = NULL;
    int array_size = BASE_SIZE;
    if (string == NULL) {
        fprintf(stderr, "In function dataParseFromString: parsing error\n");
        exit(EXIT_FAILURE);
    }
    data->array = (int*) malloc(sizeof(int) * array_size);
    if (data == NULL) {
        fprintf(stderr, "In function dataParseFromString: memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    substr = strtok(string, sep);
    while (substr != NULL) {
        if (data->elements >= array_size) {
            array_size *= 2;
            data->array = (int*) realloc(data->array, sizeof(int) * array_size);
            if (data == NULL) {
                fprintf(stderr, "In function dataParseFromString: reallocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        data->array[data->elements] = atoi(substr);
        data->elements++;
        substr = strtok(NULL, sep);
    }
    return data;
}

int dataRead(Data_t *data, int index) {
    if (data == NULL || data->array == NULL) {
        fprintf(stderr, "In function dataRead: empty or uninitialized Data_t object\n");
        exit(EXIT_FAILURE);
    }
    if (index >= data->elements) {
        fprintf(stderr, "In function dataRead: element index out of range\n");
        exit(EXIT_FAILURE);
    }
    return data->array[index];
}

void dataDestroy(Data_t *data) {
    free(data->array);
    free(data);
}

char* readLine(FILE *file_p) {
    int c = 0;
    char *buff = NULL;
    int buff_size = BASE_SIZE;
    int total_chars = 0;


    buff = (char*) calloc(buff_size, sizeof(char));
    if (buff == NULL) {
        fprintf(stderr, "In function readLine: memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(file_p)) != '\n' && c != EOF) {
        if (total_chars >= buff_size) {
            buff_size *= 2;
            buff = (char *) realloc(buff, buff_size * sizeof(char));
            if (buff == NULL) {
                fprintf(stderr, "In function readLine: memory reallocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        buff[total_chars++] = (char) c;
    }
    return buff;
}