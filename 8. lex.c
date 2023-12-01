#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100

char names[MAX_SYMBOLS][50];
int values[MAX_SYMBOLS];
int count = 0;

void insertSymbol(char* name, int value) {
    if (count < MAX_SYMBOLS) {
        strcpy(names[count], name);
        values[count] = value;
        count++;
        printf("Symbol '%s' inserted with value %d.\n", name, value);
    } else {
        printf("Symbol table is full. Cannot insert more symbols.\n");
    }
}

int searchSymbol(char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("Found: Name: %s, Value: %d\n", names[i], values[i]);
            return values[i];
        }
    }
    printf("Symbol '%s' not found.\n", name);
    return -1;
}

void displaySymbolTable() {
    printf("Symbol Table:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Value: %d\n", names[i], values[i]);
    }
}

int main() {
    insertSymbol("x", 10);
    insertSymbol("y", 20);
    insertSymbol("z", 30);

    displaySymbolTable();

    int foundValue = searchSymbol("y");
    if (foundValue != -1) {
        // Symbol found, use the foundValue
    }

    int notFoundValue = searchSymbol("a");
    if (notFoundValue != -1) {
        // This won't execute as 'a' is not in the symbol table
    }

    return 0;
}
