#include <stdio.h>
#include <string.h>

int main() {
    char str[200];

    printf("Enter a line: ");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);

    // Check single-line comment
    if (str[0] == '/' && str[1] == '/') {
        printf("It is a single-line comment.\n");
    }

    // Check multi-line comment
    else if (str[0] == '/' && str[1] == '*' &&
             str[len-3] == '*' && str[len-2] == '/') {
        printf("It is a multi-line comment.\n");
    }

    else {
        printf("It is NOT a comment.\n");
    }

    return 0;
}
