#include <stdio.h>

int main()
{
    int score[3] ,max = 0;
    scanf("%d" ,score);
        for (int i=0; i<3; i++)
        {
            if (score[i] > max)
            {
                max = score[i];
            }
        }
    printf("%d" ,max);
    return 0;
}