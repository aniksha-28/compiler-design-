#include <stdio.h>
#include <string.h>

int main() {
    char expr[20];
    char op1, op2, operatorSymbol;

    printf("Enter expression (Example: a=b+c): ");
    scanf("%s", expr);

    // Extract operands and operator
    op1 = expr[2];
    operatorSymbol = expr[3];
    op2 = expr[4];

    printf("\nGenerated Target Code:\n");

    printf("MOV R0, %c\n", op1);

    switch(operatorSymbol) {
        case '+':
            printf("ADD R0, %c\n", op2);
            break;

        case '-':
            printf("SUB R0, %c\n", op2);
            break;

        case '*':
            printf("MUL R0, %c\n", op2);
            break;

        case '/':
            printf("DIV R0, %c\n", op2);
            break;

        default:
            printf("Invalid Operator\n");
            return 0;
    }

    printf("MOV %c, R0\n", expr[0]);

    return 0;
}
