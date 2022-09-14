#include <stdio.h>

int main()
{
    float a ,b ,c ,d ,e ,f ,g ,h ,i ,j;
    float sum ,avg;
    printf("Input your 10 student hright : ");
    scanf("%f %f %f %f %f %f %f %f %f %f" ,&a ,&b ,&c ,&d ,&e ,&f ,&g ,&h ,&i ,&j);
    sum = a + b + c + d + e + f + g + h + i + j;
    avg = sum / 10;
    printf("%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f" ,a ,b ,c ,d ,e ,f ,g ,h ,i ,j);
    printf("\n%.2f" ,avg);
    return 0;
}