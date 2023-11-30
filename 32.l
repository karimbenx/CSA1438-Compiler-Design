%{
#include<stdio.h>
%}
%%
"http""://"[a-zA-Z]+".com"|".in" {printf("\n%s is valid URL",yytext);}
.+ {printf("\n%s is not valid URL",yytext);}
%%

int yywrap(){}
int main()
{
while(yylex());
} 