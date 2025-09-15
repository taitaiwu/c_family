#include <stdio.h>

int isPerfect (int number)
{
    int i,sum=0;

    for (i=1 ; i<number ; i++)
    {
        if (number%i==0) sum=sum+i;
    }

    if (number==sum) return 1;
    else return 0;
}

int main (void)
{
    int a,i,j
    ;
    printf("Please enter an integer:");
    scanf("%d",&a);

    int result=isPerfect(a);
    if (result==1) printf("%d is a perfect number.\n",a);
    else if (result==0) printf("%d is not a perfect number.\n",a);

    printf("--------------------------\n");
    printf("Perfect number between 1 and 1000:\n");

    for (i=1 ; i<=1000 ; i++)
    {
        int perfect=isPerfect(i);
        if (perfect==1)
        {
            printf("¡´ %3d=",i);
            for (j=1 ; j<i ; j++)
            {
                if (i%j==0)
                {
                    if (j==1) printf("%d",j);
                    else printf("+%d",j);
                }
            }
            printf("\n");
        }
    }
}

