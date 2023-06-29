#include <stdio.h>
#include <stdlib.h>

#define ERROR 1

void write(int rows, int columns, int matrix[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void show(int rows, int columns, int indent, int matrix[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%*d", indent, matrix[i][j]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    int rows_1 = atoi(argv[1]);
    int columns_1 = atoi(argv[2]);

    int rows_2 = atoi(argv[3]);
    int columns_2 = atoi(argv[4]);

    if (argc != 5) {
        printf("Incorrect number of arguments");
        return ERROR;
    }
    if (columns_1 != rows_2) {
        printf("Can't multiply matrices\n");
        return ERROR;
    }

    printf("Enter first matrix\n");
    int matrix_1[rows_1][columns_1];
    write(rows_1, columns_1, matrix_1);

    printf("Enter second matrix\n");
    int matrix_2[rows_2][columns_2];
    write(rows_2, columns_2, matrix_2);

    int max = 0;
    int matrix_3[rows_1][columns_2];
    for (int k = 0; k < rows_1; k++) {
        for (int l = 0; l < columns_2; l++) {
            matrix_3[k][l] = 0;
            for (int i = 0; i < columns_1; i++) {
                matrix_3[k][l] += matrix_1[k][i] * matrix_2[i][l];
            }
            if (matrix_3[k][l] > max)
                max = matrix_3[k][l];
        }
    }

    int indent = 1;
    while (max > 0) {
        max /= 10;
        indent++;
    }

    printf("First matrix\n");
    show( rows_1, columns_1, indent, matrix_1);
    printf("Second matrix\n");
    show( rows_2, columns_2, indent, matrix_2);
    printf("Result of multiplication\n");
    show( rows_1, columns_2, indent, matrix_3);

    return 0;
}
