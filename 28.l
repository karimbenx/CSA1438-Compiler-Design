%{
#include <stdio.h>
int vow_count = 0;
int const_count = 0;
%}

%%

[aeiouAEIOU] { vow_count++; printf("Vowel: %s\n", yytext); }
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ] { const_count++; printf("Consonant: %s\n", yytext); }
. ;

%%

int yywrap() {
    return 1; // Signal there is no more input
}

int main() {
    printf("Enter a string: ");
    yylex();
    printf("\nNo. of vowels = %d", vow_count);
    printf("\nNo. of consonants = %d\n", const_count);
    return 0;
}
