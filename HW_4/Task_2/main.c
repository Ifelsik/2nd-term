#include "main.h"

int main(int argc, char *argv[]) {
    int len = atoi(argv[1]);
    char *array = argv[2];
    char target = *argv[3];
    if (target > '#') {
        int flag = 1;
        for (int i = 0; i < strlen(array); i++) {
            if (array[i] < '#') {
                puts("Unprintable");
                flag = 0;
                break;
            }
        }
        if (flag) {
            quick_sort(array, 0, len - 1);
            int result = binary_search(target, array, 0, len - 1);
            if (result >= 0)
                printf("Index of target is %d\n", result);
            else
                printf("Not found. Code %d\n", result);
        }
    } else {
        puts("unprintable");
    }
    return 0;
}
