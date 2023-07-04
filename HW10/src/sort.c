#include "../include/sort.h"

long long* sort(long long arr[], unsigned len, long long min, long long max) {
    int temp_length = fabs(min) + fabs(max) + 1;
    int *temp = (int*) calloc(temp_length, sizeof(int));
    if (NULL == temp) {
        fprintf(stderr, "Can't allocate memory 'temp'\n");
        exit(EXIT_FAILURE);
    }

    int elements = 0;
    for (int i = 0; i < len; i++) {
        if (min <= arr[i] && arr[i] <= max) {
            temp[arr[i] + (int) fabs(min)]++;
            elements++;
        }
    }

    long long *sorted = (long long*) calloc(len, sizeof (long long));
    if (NULL == sorted) {
        fprintf(stderr, "Can't allocate memory for 'sorted'\n");
        exit(EXIT_FAILURE);
    }

    int sorted_array_index = 0;
    for (int i = 0; i < temp_length; i++) {
        for (int j = 0; j < temp[i]; j++) {
            sorted[sorted_array_index++] = i - fabs(min);
        }
    }

    free(temp);
    return sorted;
}
