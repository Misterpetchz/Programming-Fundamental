#include <stdio.h>

int main()
{
    int n, fac = 1;
    printf("Input your number to find factorial : ");
    scanf("%d" ,&n);
    for (int i = 1; i <= n; i++)
    {
        fac *= i;
    }
    printf("%d" ,fac);
    return 0;
}