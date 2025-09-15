#include <stdio.h>

int lcm (int numberA , int numberB)
{
    int i,j=1,m,n,lcm;

    for (i=2 ; i<=numberA ; i++)
    {
        if (numberA%i==0)
        {
            if (numberB%i==0) j=i;
        }
    }

    m=numberA/j;
    n=numberB/j;
    lcm=j*m*n;

    return lcm;
}

int main (void)
{
    int a,b;
    printf("Please enter two integers:");
    scanf("%d%d",&a,&b);

    int result=lcm(a,b);
    printf("\n[%d,%d]=%d\n",a,b,result);
}
