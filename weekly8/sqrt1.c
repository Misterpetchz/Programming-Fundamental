#include <stdio.h>
float sqrts (int number);

int main()
{
    int number;
    scanf("%d" ,&number);
    printf("%.2f" ,sqrts(number));    
    return 0;
}

float sqrts (int number)
{
    float temp = 0, sqt;
    sqt = number / 2;
    while (sqt != temp)
    {
        temp = sqt;
        sqt = (number / temp + temp) / 2;
    }
    return sqt;
}