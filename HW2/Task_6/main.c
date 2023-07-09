#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool is_Armstrong(const int number)  // checking for Armstrong number
{
    int temp_1 = number, temp_2 = number;
    int sum = 0;

    int digit_capacity = 0;
    while (temp_1 > 0)
    {
        digit_capacity++;
        temp_1 /= 10;
    }

    while (temp_2 > 0)
    {
        int digit = temp_2 % 10;
        sum += pow(digit, digit_capacity);
        temp_2 /= 10;
    }
    return sum == number;
}


int main() {
    int start, end;
    printf("Enter the start and end numbers of the range:\n");
    scanf("%i %i", &start, &end);
    if (start > end)
    {
        int temp = end;
        end = start;
        start = temp;
    }
    for (int i = start; i <= end; i++)
    {
        if (is_Armstrong(i))
            printf("%i\n", i);
    }
    return 0;
}
