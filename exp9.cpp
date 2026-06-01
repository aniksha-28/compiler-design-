#include <stdio.h>
#include <string.h>

int main() {
    char nonTerminal = 'L';

    printf("Given Grammar:\n");
    printf("S -> (L) | a\n");
    printf("L -> L,S | S\n");

    printf("\nGrammar after eliminating Left Recursion:\n");

    // S remains unchanged
    printf("S -> (L) | a\n");

    // Eliminated left recursion for L
    printf("L -> SL'\n");
    printf("L' -> ,SL' | e\n");

    return 0;
}

