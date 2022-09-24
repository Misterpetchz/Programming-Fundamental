#include <stdio.h>

int main()
{
    int num1 ,num2;
    int max;
    scanf("%d %d" ,&num1 ,&num2);
    if (num1 >= num2)
    {
        max += num1;
    }
    else
        max += num2;
    printf("%d" ,max);
    return 0;
}