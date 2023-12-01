#include <stdio.h>
#include <ctype.h>

int main() {
    char identifier[100];

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isalpha(identifier[0]) || identifier[0] == '_') {
        for (int i = 1; identifier[i] != '\0'; ++i) {
            if (!isalnum(identifier[i]) && identifier[i] != '_') {
                printf("Invalid identifier: %s\n", identifier);
                return 0;
            }
        }
        printf("Valid identifier: %s\n", identifier);
    } else {
        printf("Invalid identifier: %s\n", identifier);
    }

    return 0;
}
