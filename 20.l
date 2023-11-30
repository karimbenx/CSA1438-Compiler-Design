%{
int line_number = 1;
%}

%%
\n  { printf("%d: %s", line_number++, yytext); }
.|\n { printf("%d: %s", line_number, yytext); }
%%

int yywrap() {
    return 1; // Indicate end of input
}

int main() {
    FILE *input_file = fopen("sample.c", "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    yyin = input_file;
    yylex();

    fclose(input_file);
    return 0;
}

