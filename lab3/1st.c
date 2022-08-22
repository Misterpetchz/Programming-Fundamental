#include <stdio.h>
int main()
{
    int num,sum=0,last=0;
    scanf("%d" ,&num);
    while (num > 0)
    {
        sum = sum+num%10;
        num /= 10;
    }
    printf("%d -> " ,sum);
    while (sum > 0)
    {
        last = last+sum%10;
        sum /= 10;
    }
    printf("%d" ,last);
    return 0;

}