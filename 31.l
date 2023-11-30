%{
int positive_no = 0, negative_no = 0;
%}

%%

-?[0-9]+   { if(yytext[0] == '-') { negative_no++; printf("negative number = %s\n", yytext); } else { positive_no++; printf("positive number = %s\n", yytext); } }

%%

int yywrap() {}

int main() {
    yylex();
    printf("number of positive numbers = %d,\nnumber of negative numbers = %d\n", positive_no, negative_no);
    return 0;
}
