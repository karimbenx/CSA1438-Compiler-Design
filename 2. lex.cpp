#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter code:\n");

    while (fgets(input, sizeof(input), stdin) != NULL) {
        if (strstr(input, "//") != NULL || strstr(input, "/*") != NULL) {
            printf("Comment found: %s", input);
        } else {
            printf("Not a comment: %s", input);
        }
    }

    return 0;
}
