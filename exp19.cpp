#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i, vowels = 0, consonants = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(isalpha(str[i]))
        {
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' ||
               str[i]=='o' || str[i]=='u' ||
               str[i]=='A' || str[i]=='E' || str[i]=='I' ||
               str[i]=='O' || str[i]=='U')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }

    printf("Number of Vowels = %d\n", vowels);
    printf("Number of Consonants = %d\n", consonants);

    return 0;
}
