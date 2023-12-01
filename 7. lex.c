#include <stdio.h>
#include <string.h>

void eliminateLeftFactoring(char *production) {
    int len = strlen(production);
    int prefixLen = 0;

    // Finding the length of the common prefix
    while (prefixLen < len && production[prefixLen] == production[len - prefixLen - 1]) {
        prefixLen++;
    }

    if (prefixLen <= 1) {
        printf("No left factoring found.\n");
        return;
    }

    printf("Common prefix: %.*s\n%c -> ", prefixLen, production, production[0]);

    // Printing non-left factored productions
    for (int j = prefixLen; j < len; j++) {
        if (j == len - 1 || production[j] == '|') {
            printf("%.*s%c | ", len - j - 1, production + j + 1, production[0]);
        }
    }
    printf("\b\b  \n");
}

int main() {
    char production[] = "S -> abCd | abCef | abCghi"; // Replace with your production
    eliminateLeftFactoring(production);

    return 0;
}
