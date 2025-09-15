#include <stdio.h>

int main (void)
{
    int n,k,bouns,total,extra;

    scanf("%d%d",&n,&k);

    bouns=n/k;

    total=n+bouns;

    while (bouns>=k)
    {
        extra=bouns/k;
        total=total+extra;
        bouns/=k;
    }

    printf("%d",total);
}
