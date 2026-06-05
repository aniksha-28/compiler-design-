#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[200], *word;
    int i, flag;

    printf("Enter a sentence:\n");
    fgets(str, sizeof(str), stdin);

    word = strtok(str, " \n\t");

    printf("Capital Words are:\n");

    while(word != NULL)
    {
        flag = 1;

        for(i = 0; word[i] != '\0'; i++)
        {
            if(!isupper(word[i]))
            {
                flag = 0;
                break;
            }
        }

        if(flag)
            printf("%s\n", word);

        word = strtok(NULL, " \n\t");
    }

    return 0;
}
