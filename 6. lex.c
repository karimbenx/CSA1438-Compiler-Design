#include <stdio.h>
#include <string.h>

int main() {
    char production[100];
    printf("Enter a production (e.g., A -> Aα | β): ");
    fgets(production, sizeof(production), stdin);

    // Assuming production is in the form A -> Aα | β
    char *nonTerminal = strtok(production, " ");
    printf("%s -> %s' ", nonTerminal, nonTerminal);

    char *rule = strtok(NULL, " ");
    int hasLeftRecursion = 0;

    while (rule != NULL) {
        if (strcmp(nonTerminal, rule) == 0) {
            hasLeftRecursion = 1;
            printf("| %s' ", nonTerminal);
        } else {
            printf("| %s ", rule);
        }
        rule = strtok(NULL, " ");
    }

    if (hasLeftRecursion) {
        printf("\n%s' -> ε | %s %s'\n", nonTerminal, nonTerminal, nonTerminal);
    } else {
        printf("\n");
    }

    return 0;
}
