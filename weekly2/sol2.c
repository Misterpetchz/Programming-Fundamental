#include <stdio.h>

int main()
{
    int score[3];
    scanf("%d" ,&score[0]);
    scanf("%d" ,&score[1]);
    scanf("%d" ,&score[2]);
    int max = score[0];
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