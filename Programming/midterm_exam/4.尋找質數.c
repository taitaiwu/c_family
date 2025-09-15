#include <stdio.h>

int main (void)
{
    int a,b,i,j,k;

    scanf("%d%d",&a,&b);

    for (i=a ; i<=b ; i++)
    {
        k=0;

        for (j=2 ; j<i ; j++)
        {
            if (i%j!=0) k=1;
            else
            {
                k=0;
                break;
            }
        }

        if (k==1) printf("%d ",i);
    }
}
