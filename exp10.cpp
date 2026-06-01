#include <stdio.h>

int main() {

    printf("Given Grammar:\n");
    printf("S -> iEtS | iEtSeS | a\n");
    printf("E -> b\n");

    printf("\nGrammar after Left Factoring:\n");

    // Left factored grammar
    printf("S -> iEtSS' | a\n");
    printf("S' -> eS | epsilon\n");
    printf("E -> b\n");

    return 0;
}
