#include <stdio.h>
int main()
{
    int x,y=2;
    scanf("%d" ,&x);
    while (x!=1)
    {
        if (x%y == 0)
        {
            printf("%d" ,y);
            x = x/y;
            if (x!=1)
            {
                printf("x");
            }
        }
        else 
        {
        y++;
        }

    }
    return 0;
}