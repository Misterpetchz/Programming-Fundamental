#include <stdio.h>

int main()
{
    float cm[10];
    float sum = 0, avg;
    printf("Input your 10 student height : ");
    scanf("%f %f %f %f %f %f %f %f %f %f" ,&cm[0] ,&cm[1] ,&cm[2] ,&cm[3] ,&cm[4] ,&cm[5] ,&cm[6] ,&cm[7] ,&cm[8] ,&cm[9]);
    for (int i = 0; i < 10; i++)
    {
        sum = sum + cm[i];
        printf("%.2f " ,cm[i]);
    }
    avg = sum / 10;
    printf("\n%.2f" ,avg);
    return 0;
}