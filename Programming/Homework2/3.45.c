#include <stdio.h>

int main (void)
{
    int a,b,x;
    int y=1;
    float n=1;
    float e=1;
    float i=1;

    //(a)撰寫一個程式讀入非負的整數，計算並印出其階乘值

    printf("Please enter a non-negative integer:");
    scanf("%d",&a);

    b=a;

    while (a<0)
    {
        printf("Input error.Please try again:");
        scanf("%d",&a);
    }

    while (a>0)
    {
        n=n*a;
        a=a-1;
    }

    printf(" %d! = %.0f\n",b,n);

    //(b)撰寫一個程式計算數學常數e的趨近值

    n=1;

    while (i<=b)
    {
        n=n*i;
        e=e+1/n;
        i=i+1;
    }
    printf("  e = %f\n",e);

    //(c)寫一個程式計算eˣ的值

    printf("Please enter an integer for exponent\"x\" of e:");
    scanf("%d",&x);

    e=1;
    i=1;
    n=1;

    while (i<=b)
    {
        n=n*i;
        y=y*x;
        e=e+y/n;
        i=i+1;
    }

    printf("  e^%d  = %f",x,e);
}
