#include <stdio.h>

int main() {
    float celsius;
    printf("Input Celsius temperature:");
    scanf("%f", &celsius);;
    printf("Fahrenheit temperature is %.2f\n", 1.8 * celsius + 32);
    printf("Kelvin temperature is %.2f\n", celsius + 273.15);
    return 0;
}
