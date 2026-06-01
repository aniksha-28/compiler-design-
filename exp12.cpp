#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

// Function declarations
void E();
void Edash();
void T();
void Tdash();
void F();

// Function for E ? TE'
void E() {
    T();
    Edash();
}

// Function for E' ? +TE' | e
void Edash() {
    if (input[i] == '+') {
        i++;
        T();
        Edash();
    }
}

// Function for T ? FT'
void T() {
    F();
    Tdash();
}

// Function for T' ? *FT' | e
void Tdash() {
    if (input[i] == '*') {
        i++;
        F();
        Tdash();
    }
}

// Function for F ? id
void F() {
    if (input[i] == 'i' && input[i + 1] == 'd') {
        i += 2;
    } else {
        printf("String is Invalid\n");
    }
}

int main() {
    printf("Enter the input string: ");
    scanf("%s", input);

    E();

    if (input[i] == '\0')
        printf("String is Accepted\n");
    else
        printf("String is Rejected\n");

    return 0;
}
