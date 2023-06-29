#include "include/sort.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "args error\n");
        exit(EXIT_FAILURE);
    }

    const char *path = argv[1];

    long long min = atoll(argv[2]);
    long long max = atoll(argv[3]);

    if (max <= min) {
        fprintf(stderr, "min number can't be bigger than max\n");
        exit(EXIT_FAILURE);
    }

    FILE *file_in = fopen(path, "r");
    if (file_in == NULL) {
        fprintf(stderr, "Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    char *string = (char*) calloc(MAX_LEN, sizeof(char));
    if (string == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    int arr_len = 0;
    while (fgets(string, MAX_LEN, file_in) != NULL) {
        arr_len++;
    }

    long long arr[arr_len];
    if (arr_len > MAX_ELEMENT_NUMBER) {
        fprintf(stdin, "WARNING: May work incorrectly");
    } else if (arr_len == 0) {
        fprintf(stderr, "ERROR: strange file!\n");
        exit(EXIT_FAILURE);
    }

    fseek(file_in, 0, SEEK_SET);
    int i = 0;
    while (fgets(string, MAX_LEN, file_in) != NULL) {
        long long num = 0;
        sscanf(string, "%lld", &num);
        arr[i++] = num;
    }
    fclose(file_in);

    long long *sortedArr = sort(arr, arr_len, min, max);

    FILE *file_out = fopen("../out.txt", "w");
    if (file_out == NULL) {
        fprintf(stderr, "Failed to open file 'file_out'\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < arr_len; i++) {
        fprintf(file_out, "%lld\n", sortedArr[i]);
    }
    fclose(file_out);

    printf("Success. Result saved as 'out.txt'\n");
    return 0;
}
