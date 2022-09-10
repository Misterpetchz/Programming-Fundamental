#include <stdio.h>

long int power(int , int);

int main()
{
    int base ,expo ,ans;
    scanf("%d %d" ,&base ,&expo);
    ans = power(base ,expo);
    printf("Power is : %d" ,ans);
    return 0;
}
long int power(int x ,int n)
{
    if (n == 0)
        return 1;
    else
        return x * power(x , n - 1);
}