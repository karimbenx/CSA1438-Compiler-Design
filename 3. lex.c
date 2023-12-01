#include <stdio.h>

int main() {
  char operator;

  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &operator);

  switch (operator) {
    case '+':
    case '-':
    case '*':
    case '/':
      printf("Valid operator: %c\n", operator);
      break;
    default:
      printf("Invalid operator: %c\n", operator);
      break;
  }

  return 0;
}

