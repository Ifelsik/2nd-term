#include <stdio.h>

int main() {
    float a, b, c;
    float max;
    printf("Enter 3 numbers:\n");
    scanf(" %f %f %f", &a, &b, &c);
    max = a > b ? a : b;
    max = max > c ? max : c;
    printf("%f\n", max);
    return 0;
}
