#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char str[])
{
    char keywords[][10] = {
        "int", "float", "char", "double", "if", "else",
        "for", "while", "do", "return", "void", "break",
        "continue"
    };

    int i;
    for(i = 0; i < 13; i++)
    {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char str[100];

    printf("Enter words (Press Ctrl+Z to stop):\n");

    while(scanf("%s", str) != EOF)
    {
        if(isKeyword(str))
            printf("%s --> Keyword\n", str);
        else
            printf("%s --> Identifier\n", str);
    }

    return 0;
}
