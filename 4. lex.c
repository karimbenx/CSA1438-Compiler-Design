#include <stdio.h>

int main() {
    int spaceCount = 0, newlineCount = 0, tabCount = 0;
    int c;

    printf("Enter text (Ctrl+D/Ctrl+Z to exit):\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaceCount++;
        } else if (c == '\n') {
            newlineCount++;
        } else if (c == '\t') {
            tabCount++;
        }
    }

    printf("Number of spaces: %d\n", spaceCount);
    printf("Number of tabs: %d\n", tabCount);
    printf("Number of newlines: %d\n", newlineCount);

    return 0;
}
