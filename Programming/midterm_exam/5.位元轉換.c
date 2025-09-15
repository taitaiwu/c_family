#include <stdio.h>

int main (void)
{
    int a,b,n;

    scanf("%d",&a);


    for (b=128 ; b>=1 ; b/=2)
    {
        n=a/b%2;
        printf("%d",n);
    }
}
