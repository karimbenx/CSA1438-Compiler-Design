%{
#include <stdio.h>
%}

%%
[0-9]{10}   { printf("Valid Mobile Number: %s\n", yytext); }
.|\n        { printf("Invalid Mobile Number\n"); }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a mobile number: ");
    yylex();
    return 0;
}
