#include <stdio.h>

int total (int number)
{
    int i,j,k=0;

    for (i=10 ; i<(number*10) ; i*=10)
    {
        j=(number%i)/(i/10);
        k=k+j;
        if (i==10) printf("\n%d",j);
        else printf("+%d",j);
    }
    return k;
}

int main (void)
{
    int a;
    printf("Please enter an integer:");
    scanf("%d",&a);

    int result=total(a);
    printf("=%d\n",result);
}
