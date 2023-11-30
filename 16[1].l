%{
#include<stdio.h>
int nchar, nword, nline;
%}
%%
\n { nline++; nchar+=yyleng; }
[^ \t\n]+ { nword++, nchar += yyleng; }
. { nchar++; }
%%
int yywrap() 
{
return 1;
}
int main(int argc, char *argv[]) 
{
yyin = fopen(argv[1], "r");
yyout=fopen("output.c","w");
yylex();
printf("Number of characters = %d\n", nchar);
printf("Number of words = %d\n", nword);
printf("Number of lines = %d\n", nline);
}s