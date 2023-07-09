#include <stdio.h>

int main()
{
    long long num, changed_num = 0;
    int digit_capacity = 1;
    int first, last;

    printf("Enter your number:\n");
    scanf("%lli", &num);

    last = num % 10;
    while (num >= 10)
    {
        changed_num += digit_capacity * (num % 10);
        num /= 10;
        digit_capacity *= 10;
    }
    first = num;
    changed_num -= last;
    changed_num =  digit_capacity * last + changed_num + first;

    printf("The first and last are swapped:\n%lli", changed_num);
    return 0;
}
