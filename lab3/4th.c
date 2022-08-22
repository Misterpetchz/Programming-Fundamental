#include <stdio.h>

int main()
{
   int x,prime=1;
    scanf("%d" ,&x);
    for (int i=2; i<x; i++)
    {
        if (x%i==0)
        {
            prime = 0;
            break;
        }
    }
    if (prime == 1)
    {
        printf("prime number");
    }
    else
        printf("not prime number");
    
    return 0;
}