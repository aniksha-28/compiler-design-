#include <stdio.h>
#include <string.h>

int main() {
    char expr[50];
    int i, temp = 1;

    printf("Enter the expression: ");
    scanf("%s", expr);

    printf("\nThree Address Code:\n");

    // Process multiplication and division first
    for(i = 0; expr[i] != '\0'; i++) {
        if(expr[i] == '*' || expr[i] == '/') {
            printf("t%d = %c %c %c\n",
                   temp,
                   expr[i - 1],
                   expr[i],
                   expr[i + 1]);

            expr[i + 1] = '0' + temp;
            temp++;
        }
    }

    // Process addition and subtraction
    for(i = 0; expr[i] != '\0'; i++) {
        if(expr[i] == '+' || expr[i] == '-') {
            printf("t%d = %c %c %c\n",
                   temp,
                   expr[i - 1],
                   expr[i],
                   expr[i + 1]);

            expr[i + 1] = '0' + temp;
            temp++;
        }
    }

    return 0;
}
