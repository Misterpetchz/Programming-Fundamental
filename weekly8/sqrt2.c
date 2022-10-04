#include <stdio.h>

float sqrts (int number)
{
    float temp;
    if (number >= 0)
    {
            for (temp = 0.001; temp * temp < number; temp += 0.001);
            return temp;
    }
    else
        return 0;
}

int main()
{
    int number;
    scanf("%d" ,&number);
    printf("%.2f" ,sqrts(number));
    return 0;
}