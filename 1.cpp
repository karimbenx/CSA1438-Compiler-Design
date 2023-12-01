#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000];
    printf("Enter code (Ctrl+D to exit):\n");

    while (fgets(input, sizeof(input), stdin) != NULL) {
        for (int i = 0; input[i]; ++i) {
            if (isspace(input[i])) continue;
            if (input[i] == '/' && input[i + 1] == '/') break;
            
            if (isalpha(input[i]) || input[i] == '_') {
                int j = i + 1;
                while (isalnum(input[j]) || input[j] == '_') ++j;
                printf("Identifier: %.10s\n", &input[i]); // Print only first 10 chars for identifiers
                i = j - 1;
            } else if (isdigit(input[i])) {
                int j = i + 1;
                while (isdigit(input[j])) ++j;
                printf("Constant: %.10s\n", &input[i]); // Print only first 10 chars for constants
                i = j - 1;
            } else printf("Operator: %c\n", input[i]);
        }
    }

    return 0;
}
