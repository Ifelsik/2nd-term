#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int readfile(char *path, char **filebuf) {
    FILE *file_p = NULL;
    file_p = fopen(path, "r");
    if (file_p != NULL) {
        fseek(file_p, 0, SEEK_END);
        int len = ftell(file_p);
        fseek(file_p, 0, SEEK_SET);

        *filebuf = (char*) malloc(sizeof(char) * (len + 1));
        if (NULL == *filebuf) {
            puts("OS didn't gave memory...");
            return 1;
        }
        fread(*filebuf, sizeof(char), len + 1, file_p);
        fclose(file_p);
        return 0;
    } else {
        puts("ERROR: File ptr is NULL");
        return 1;
    }
}

/*
Checking all amounts for results. Returns the number of such combinations,
or 0 if they do not exist
@param comb: Array of different combinations of indexes
@param nums: Array of numbers by line
@param comb_len: Length of each combination
@param required_sum: Required result (sum of numbers)
@param pos: Position in combination
*/
int comb_gen(int *comb, int **nums, int comb_len, int required_sum, int pos) {
    int res = 0;
    if (pos < 0) {
        int sum = 0;
        for (int i = 0; i < comb_len; i++) {
            sum += nums[i][comb[i] + 1];
        }
        if (sum == required_sum) {
            for (int j = 0; j < comb_len; j++)
                printf("%d: %d, ", comb[j], nums[j][comb[j] + 1]);
            putchar('\n');
            return 1;
        }
        return 0;
    }
    for (int i = 0; i < nums[pos][0]; i++) {
        comb[pos] = i;
        res += comb_gen(comb, nums, comb_len, required_sum, pos-1);
    }
    return res;
}

int main(int argc, char **argv) {
    char *buf = NULL;
    int req_sum = 0;
    readfile("..\\file2.txt", &buf);

    req_sum = atoi(argv[1]);
    int lines_count = 1;
    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '\n')
            lines_count++;
    }
    
    int *lines[lines_count];
    int j = 0;
    for (int i = 0; i < lines_count; i++) {
        char *str = (char*) malloc(sizeof(char) * strlen(buf));
        int numbers_count = 1;
        int k = 0;
        for (; buf[j] != '\n' && buf[j] != '\0'; k++, j++) {
            str[k] = buf[j];
            if (buf[j] == ',')
                numbers_count++;
        }
        str[k + 1] = '\0';
        j++;

        lines[i] = (int*) malloc(sizeof(int) * (numbers_count + 1));
        lines[i][0] = numbers_count;  // First element of dynmaic array is count of numbers in line

        char *split = NULL;
        split = strtok(str, ",");
        for (int k = 1; k < numbers_count + 1; k++) {
            lines[i][k] = atoi(split);
            split = strtok(NULL, ",");
        }
    }

    int *comb = (int*) calloc(lines_count, sizeof(int));
    printf("index: value\n");
    int res;
    res = comb_gen(comb, lines, lines_count, req_sum, lines_count - 1);
    if (res == 0)
        printf("There are no such combinations(\n");
    return 0;
}
