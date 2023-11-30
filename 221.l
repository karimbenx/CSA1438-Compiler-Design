%{
#include<stdio.h>
int nc=0;
%}
%%
"/*"[a-zA-Z0-9\n\t]*"*/" {nc++;}
"//"[a-zA-Z0-9\t]*"\n" {nc++;}
%%
int yywrap(){}
int main(void)
{
FILE *f;
char file[10];
printf("enter file name:");
scanf("%s",file);
f=fopen(file,"r");
yyin=f;
yylex();
printf("the number of comment lines=%d\n",nc);
fclose(yyin);
}