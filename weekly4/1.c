#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int base ,expo ,ans;
    scanf("%d %d" ,&base ,&expo);
    ans = pow(base ,expo);
    printf("Power is : %d" ,ans);
    return 0;
}