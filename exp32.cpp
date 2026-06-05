#include <stdio.h>

int main()
{
    int n, num;
    int positive = 0, negative = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the numbers:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);

        if(num > 0)
            positive++;
        else if(num < 0)
            negative++;
    }

    printf("Number of Positive Numbers = %d\n", positive);
    printf("Number of Negative Numbers = %d\n", negative);

    return 0;
}
