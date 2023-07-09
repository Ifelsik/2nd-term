#include <stdio.h>
#include <stdlib.h>

#define ERROR 1

int main(int argc, char *argv[]) {
    int size = atoi(argv[1]);
    char *array = argv[2];

    if (argc != 3)
    {
        printf("incorrect number of arguments");
        return ERROR;
    }
    int real_len = 0;
    while (array[real_len] != '\0')
        real_len++;
    if (real_len != size)
    {
        printf("Incorrect number of array elements");
        return ERROR;
    }

    int inversions = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 1; j < size; j++) {
            if (array[j - 1] > array[j]) {
                char temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                inversions++;
            }
        }
    }

    printf("Number of inversions -> %d\n", inversions);
    printf("Array -> %s\n", array);

    return 0;
}
