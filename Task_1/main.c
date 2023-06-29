#include <stdio.h>
#include <stdlib.h>

#define ERROR 1

// If you see  " -> 1 times", it means a backspace character
// Quotes are not taken into account

int main(int argc, char *argv[]) {
    int arr_len = atoi(argv[1]);
    char * arr = argv[2];
    char symbols_amount[256] = {0};

    if (argc != 3)
    {
        printf("incorrect number of arguments");
        return ERROR;
    }
    int real_len = 0;
    while (arr[real_len] != '\0')
        real_len++;
    if (real_len != arr_len)
    {
        printf("Incorrect number of array elements");
        return ERROR;
    }

    for (int i = 0; i < arr_len; i++)
    {
        if (arr[i] != '\n' && arr[i] != '\0' && arr[i] != '\t')
            symbols_amount[arr[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (symbols_amount[i] != 0)
        {
            printf("%c -> %d times\n", i, symbols_amount[i]);
        }
    }
    return 0;
}

