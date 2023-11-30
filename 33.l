%{
#include<stdio.h>
%}
%%
((0[1-9])|([1-2][0-9])|(3[0-1]))\/((0[1-9])|(1[0-2]))\/(19[0-9]{2}|2[0-9]{3}) {printf("\n%s is a Valid DoB",yytext);}
.* {printf("\n%s is Invalid DoB",yytext);}
%%
int yywrap()
{
return 1;
}
int main(int argc,char*argv[])
{
yyin=fopen(argv[1],"r");
yyout=fopen("output.c","w");
yylex();
return 0;
}