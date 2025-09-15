#include <stdio.h>

int main (void)
{
    int a=100;
    int b,c,d,e,f,g;

    while (a<1000)
    {
        b=a/100;
        c=(a%100)/10;
        d=a%10;
        e=b*b*b;
        f=c*c*c;
        g=d*d*d;

        if (a==e+f+g) printf("%d=%d^3+%d^3+%d^3\n",a,b,c,d);
        a=a+1;
    }
}
