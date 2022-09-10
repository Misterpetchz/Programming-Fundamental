#include <stdio.h>

int main()
{
    int a, b = 2;
    scanf("%d" ,&a);
    while (a != 1)
    {
        while (a % b == 0)
        {
            if (a / b == 1)
            {
                printf("%d",b);
                break;
            }
            printf("%d " ,b);
            a = a / b;
        }
        b++;
    }
    return 0;
}