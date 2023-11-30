%{
#include<stdio.h>
%}
%%
if|else|main|void|return|swtich|case|int|char|printf|scanf {printf("\n%s is keyword",yytext);}
.+[a-zA-Z][a-zA-Z0-9]+ {printf("\n%s is identifier",yytext);}
.+ {printf("\n%s is not keyword or identifier",yytext);}
%%

int yywrap(){}
int main()
{
while(yylex());
} 