#include <stdio.h>

int main (void)
{
    int a,b,c,d,e,f;
    printf("Please enter a integer:");
    scanf("%d",&a);

    b=a/10000;
    c=(a%10000)/1000;
    d=((a%10000)%1000)/100;
    e=(((a%10000)%1000)%100)/10;
    f=a%10;

    int count=0;

    if (b==9) count=count+1;
    if (c==9) count=count+1;
    if (d==9) count=count+1;
    if (e==9) count=count+1;
    if (f==9) count=count+1;

    printf("This integer has %d number\"9\"s.",count);
}
