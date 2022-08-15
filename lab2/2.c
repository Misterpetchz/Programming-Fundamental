#include <stdio.h>
int main()
{
    int x,y;
    int div;
    printf("Enter first number : ");
    scanf("%d" ,&x);
    printf("Enter second number : ");
    scanf("%d" ,&y);
   while (x != y)
    {
        if (x > y){
            x = x-y;
        }
        else{
            y =y-x;
        }
    }
    div = x;
    printf("%d", div);
    return 0;
}