#include <stdio.h>

int main (void)
{
    int a,hour,minute,second;

    printf("Please enter seconds:");
    scanf("%d",&a);

    hour=a/3600;
    minute=(a%3600)/60;
    second=(a%3600)%60;

    printf("It is %d : %d :%d.",hour,minute,second);

}
