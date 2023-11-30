%{
#include <stdio.h>
#include <string.h>
%}

%%
[a-zA-Z]+("<"|">"|"<="|">="|"=="|"!=") { 
    printf("Word and Relational Operator Found: %s\n", yytext);
}

. ;

%%
int yywrap()
{
  return 1;
}

int main() {
    yylex();
    return 0;
}
