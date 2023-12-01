#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool factor(char** expr) {
    if (isdigit(**expr)) {
        (*expr)++;
        return true;
    } else if (**expr == '(') {
        (*expr)++;
        if (factor(expr) && **expr == ')') {
            (*expr)++;
            return true;
        }
    }
    return false;
}

bool term(char** expr) {
    if (factor(expr)) {
        while (**expr == '*' || **expr == '/') {
            (*expr)++;
            if (!factor(expr)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool expression(char** expr) {
    if (term(expr)) {
        while (**expr == '+' || **expr == '-') {
            (*expr)++;
            if (!term(expr)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool parseExpression(char* input) {
    return expression(&input) && *input == '\0';
}

int main() {
    char input[] = "A+B*C/D"; // Replace with your input expression

    if (parseExpression(input)) {
        printf("The expression is valid.\n");
    } else {
        printf("Invalid expression.\n");
    }

    return 0;
}
