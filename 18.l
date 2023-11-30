%{
int nmacro, nheader; 
%}
%%
^#define { nmacro++; } 
^#include { nheader++; } 
.|\n { } 
%%
int yywrap() 
{ 
return 1; 
} 
int main(int argc, char *argv[]) 
{ 
yyin = fopen(argv[1], "r"); 
yyout = fopen("output.c","w");
yylex(); 
printf("Number of macros defined = %d\n", nmacro); 
printf("Number of header files included = %d\n", nheader); 
}