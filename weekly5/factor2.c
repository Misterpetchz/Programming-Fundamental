#include <stdio.h>

long factor(int x)
{
    int y = 2;
    while (x != 1)
    {
        if (x % y == 0)
        {
            printf("%d " ,y);
            x = x / y;
        }
        else 
            y++;
    }
}

int main()
{
    int n;
    scanf("%d" ,&n);
    factor(n);
    return 0;
}