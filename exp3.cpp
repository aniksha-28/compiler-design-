#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '%');
}

int main() {
    char input[1000];
    int i = 0;

    printf("Enter source code:\n");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {

        // Ignore spaces, tabs, newlines
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
            i++;
            continue;
        }

        // Ignore single-line comments
        if (input[i] == '/' && input[i+1] == '/') {
            while (input[i] != '\n' && input[i] != '\0')
                i++;
            continue;
        }

        // Ignore multi-line comments
        if (input[i] == '/' && input[i+1] == '*') {
            i += 2;
            while (!(input[i] == '*' && input[i+1] == '/') && input[i] != '\0')
                i++;
            i += 2;
            continue;
        }

        // Identify identifiers
        if (isalpha(input[i]) || input[i] == '_') {
            printf("Identifier: ");
            while (isalnum(input[i]) || input[i] == '_')
                printf("%c", input[i++]);
            printf("\n");
            continue;
        }

        // Identify constants
        if (isdigit(input[i])) {
            printf("Constant: ");
            while (isdigit(input[i]))
                printf("%c", input[i++]);
            printf("\n");
            continue;
        }

        // Identify operators
        if (isOperator(input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
            continue;
        }

        i++;
    }

    return 0;
}
