#include <stdio.h>

double evaluateExpression(char* expression) {
    double result = 0;
    char operator;
    int i = 0;

    while (expression[i] != '\0') {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            operator = expression[i];
        } else {
            double operand = expression[i] - 'A' + 1;

            switch (operator) {
                case '+':
                    result += operand;
                    break;
                case '-':
                    result -= operand;
                    break;
                case '*':
                    result *= operand;
                    break;
                case '/':
                    if (operand != 0) {
                        result /= operand;
                    } else {
                        printf("Error: Division by zero.\n");
                        return 0;
                    }
                    break;
            }
        }
        i++;
    }

    return result;
}

int main() {
    char input[] = "A+B*C-D"; // Replace with your input expression

    double result = evaluateExpression(input);
    printf("Result: %lf\n", result);

    return 0;
}
