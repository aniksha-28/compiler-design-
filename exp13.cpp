#include <stdio.h>
#include <string.h>

char input[100];
int i = 0, error = 0;

// Function declarations
void E();
void Eprime();
void T();
void Tprime();
void F();

// E ? TE'
void E() {
    T();
    Eprime();
}

// E' ? +TE' | e
void Eprime() {
    if (input[i] == '+') {
        i++;
        T();
        Eprime();
    }
}

// T ? FT'
void T() {
    F();
    Tprime();
}

// T' ? *FT' | e
void Tprime() {
    if (input[i] == '*') {
        i++;
        F();
        Tprime();
    }
}

// F ? (E) | id
void F() {
    if (input[i] == '(') {
        i++;
        E();

        if (input[i] == ')')
            i++;
        else
            error = 1;
    }
    else if (input[i] == 'i' && input[i + 1] == 'd') {
        i += 2;
    }
    else {
        error = 1;
    }
}

int main() {
    printf("Enter input string: ");
    scanf("%s", input);

    E();

    if (input[i] == '\0' && error == 0)
        printf("String is accepted by the grammar.\n");
    else
        printf("String is not accepted by the grammar.\n");

    return 0;
}
