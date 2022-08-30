#include <stdio.h>

int main()
{
    int rows, k = 0;
    scanf("%d" ,&rows);
    for (int i = 1; i <= rows; i++ ,k = 0)
    {
        for (int j = 1; j <= rows - i; j++)
        {
            printf("  ");
        }
        while (k != (2 * i - 1))
        {
            printf("* ");
            k++;
        }
        printf("\n");
    }
    return 0;
}