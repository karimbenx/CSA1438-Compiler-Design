#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidString(char* input) {
    int length = strlen(input);
    if (length < 2) {
        return false; // String should have at least two characters (start and end)
    }

    // Check if the string starts with 'a' and ends with 'b'
    return (input[0] == 'a' && input[length - 1] == 'b');
}

int main() {
    char input[] = "abracadabrb"; // Replace with your input string

    if (isValidString(input)) {
        printf("The input string satisfies the grammar.\n");
    } else {
        printf("The input string does not satisfy the grammar.\n");
    }

    return 0;
}
