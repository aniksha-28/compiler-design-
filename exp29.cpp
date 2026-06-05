#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[100], token[20];
    int i = 0, j;

    printf("Enter C Program:\n");

    while((str[i] = getchar()) != EOF)
        i++;

    str[i] = '\0';

    i = 0;

    while(str[i] != '\0')
    {
        if(isalpha(str[i]))
        {
            j = 0;
            while(isalnum(str[i]))
                token[j++] = str[i++];

            token[j] = '\0';

            if(strcmp(token,"int")==0 ||
               strcmp(token,"void")==0 ||
               strcmp(token,"main")==0)
                printf("%s : Keyword\n", token);
            else
                printf("%s : Identifier\n", token);
        }

        else if(isdigit(str[i]))
        {
            j = 0;
            while(isdigit(str[i]))
                token[j++] = str[i++];

            token[j] = '\0';
            printf("%s : Constant\n", token);
        }

        else if(strchr("+-=*/", str[i]))
        {
            printf("%c : Operator\n", str[i]);
            i++;
        }

        else if(strchr("(){};,<>", str[i]))
        {
            printf("%c : Special Symbol\n", str[i]);
            i++;
        }

        else
            i++;
    }

    return 0;
}
