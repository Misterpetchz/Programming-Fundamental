#include <stdio.h>

int main()
{
    int a=1;
    while (a<=10000)
    {   
        int x=1,sum=0;
        while(x<=a/2)
        {
            if(a%x==0)
                sum += x;
            x++;
        }
        if (a==sum || a== 1)
            printf("%d " ,a);
        a++;
    }
    return 0;
}