#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 32

int main(int argc, char *argv[]) {
    FILE *file_p = NULL;
    char *path = NULL;
    char *string = NULL;
    long long abs_min = MAX_LEN;
    long long max = MAX_LEN;
    long long *positive = NULL;
    long long *negative = NULL;

    if (argc != 2) {
        fprintf(stderr, "Incorrect number of argments\n");
        exit(EXIT_FAILURE);
    }
    path = argv[1];

    file_p = fopen(path, "r");
    if (file_p == NULL) {
        fprintf(stderr, "Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    string = (char*) calloc(MAX_LEN, sizeof(char));
    if (string == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    positive = (long long *) calloc(max, sizeof(long long));
    if (positive == NULL) {
                fprintf(stderr, "positive has Null pointer\n");
                exit(EXIT_FAILURE);
            }
    negative = (long long *) calloc(abs_min, sizeof(long long));
    while (fgets(string, MAX_LEN, file_p) != NULL) {
        long long num = 0;
        sscanf(string, "%lld", &num);
        if (num > max) {
            max = num + 1;
            positive = (long long *) realloc(positive, max * sizeof(long long));
            if (positive == NULL) {
                fprintf(stderr, "positive has Null pointer\n");
                exit(EXIT_FAILURE);
            }
        } else if (-num > abs_min) {
            abs_min = -num + 1;
            negative = (long long *) realloc(negative, abs_min * sizeof(long long));
            if (negative == NULL) {
                fprintf(stderr, "negative has Null pointer\n");
                exit(EXIT_FAILURE);
            }
        }
        if (num >= 0)
            positive[num]++;
        else
            negative[-num]++;
    }

    fclose(file_p);

    return 0;
}
