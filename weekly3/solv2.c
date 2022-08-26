#include <stdio.h>

int main()
{
    int n,k,sam = 1;
    scanf("%d" ,&n);
    for (int i = n; i>0; i--)
    {
        for (k = sam; k>=1; k--)
        {
            printf("*");
        }
        sam += 1; //*เพิ่มอันละบรรททัด
        printf("\n");
    }
    return 0;
}