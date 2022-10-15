#include <stdio.h>

int max (int a ,int b);

int main()
{
    int x ,y;
    scanf("%d %d" ,&x ,&y);
    printf("%d" ,max(x ,y));
    return 0;
}

int max (int a ,int b)
{
    if (a >= b)
        return a;
    else 
        return b;
}
//