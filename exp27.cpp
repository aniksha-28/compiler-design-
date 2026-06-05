#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'a' &&
           str[i+1] == 'b' &&
           str[i+2] == 'c')
        {
            str[i] = 'A';
            str[i+1] = 'B';
            str[i+2] = 'C';
        }
    }

    printf("Modified String: %s", str);

    return 0;
}
