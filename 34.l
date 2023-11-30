%{
#include <stdio.h>
%}

%%

[0-9]      { printf("The input is a digit: %s\n", yytext); }
.          { printf("The input is not a digit: %s\n", yytext); }

%%

int yywrap() {
    return 1; // Returning 1 indicates the end of input.
}

int main() {
    yylex();
    return 0;
}
