%{
int tags = 0;
%}

%%
"<"[^>]*> {tags++; printf("%s\n", yytext);}
.|\n { /* Ignoring other characters */ }

%%

int yywrap(void) {
    return 1;
}

int main(void) {
    FILE *f;
    char file[100]; // Allowing a larger buffer for file name input

    printf("Enter the file name: ");
    scanf("%s", file);

    f = fopen(file, "r");
    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }

    yyin = f;
    yylex();

    printf("Number of HTML tags: %d\n", tags);

    fclose(yyin);
    return 0;
}
