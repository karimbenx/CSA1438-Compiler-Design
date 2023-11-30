%{
#include <stdio.h>
%}

%%

[A-Z][a-z]+    { printf("Capitalized word: %s\n", yytext); }
.|\n           ; // Ignore other characters
%%

int yywrap() {
    return 1; // Indicate end of input
}

int main() {
    yylex();
    return 0;
}
