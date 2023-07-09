#include <stdio.h>

void calculations(float x, float y){
    printf("Sum: %f\n", x + y);
    printf("Difference: %f\n", x - y);
    printf("Multiplication: %f\n", x * y);
    printf("Division: %f\n", x / y);
}

int main() {
    float num_1, num_2;
    printf("Enter 2 numbers:\n");
    scanf("%f %f", &num_1, &num_2);
    calculations(num_1, num_2);
    printf("\n");  // Для разделения разных вычислений
    calculations(num_1 + num_2, num_1 * num_2);
    return 0;
}
