#include <stdio.h>
#include <stdbool.h>

int main() {
    float operand_1, operand_2, result;
    char operator;
    printf("Type '0 0 0' to stop\n");
    while(1) {
        printf("Enter expression (<operand_1> <operator> <operand_2>):\n");
        scanf("%f %c %f", &operand_1, &operator, &operand_2);
        if (operand_1 == 0 && operator == '0' && operand_2 == 0){
            printf("Terminated");
            break;
        }
        bool is_correct = true;
        switch (operator) {
            case '+':
                result = operand_1 + operand_2;
                break;
            case '-':
                result = operand_1 - operand_2;
                break;
            case '*':
                result = operand_1 * operand_2;
                break;
            case '/':
                result = operand_1 / operand_2;
                if (operand_2 == 0)
                    is_correct = false;
                break;
            default:
                is_correct = false;
        }
        if (is_correct)
            printf("Result of operation is %f\n", result);
        else
            printf("Wrong expression! Please try again.\n");
    }
    return 0;
}
