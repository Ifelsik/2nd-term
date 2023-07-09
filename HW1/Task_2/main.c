#include <stdio.h>

int main() {
    int days;
    printf("Enter the number of days:");
    scanf("%d", &days);
    printf("Years: %d\n", days / 365);
    printf("Months: %d\n", days % 365 / 30);
    printf("Weeks: %d\n", days % 365 % 30 / 7);
    printf("Days: %d\n", days % 365 % 30 % 7);
    return 0;
}
