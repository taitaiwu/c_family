#include <stdio.h>

int main (void)
{
    char s;
    int i,j,k;

    printf("(A)\n");
    for (i=1 ; i<10 ; i++)
    {
        for (j=1 ; j<=i ; j++)
        {
            printf("%s","*");
        }
        printf("\n");
    }

    printf("\n(B)\n");
    for (i=1 ; i<11 ; i++)
    {
        for (j=10 ; j>=i ; j--)
        {
            printf("%s","*");
        }
        printf("\n");
    }

    printf("\n(C)\n");
    for (i=1 ; i<10 ; i++)
    {
        for (k=1 ; k<i ; k++)
        {
            printf(" ");
        }

        for (j=10 ; j>i ; j--)
        {
            printf("%s","*");
        }
        printf("\n");
    }

    printf("\n(D)\n");
    for (i=1 ; i<10 ; i++)
    {
        for (k=10 ; k>i ; k--)
        {
            printf(" ");
        }

        for (j=1 ; j<i ; j++)
        {
            printf("%s","*");
        }
        printf("\n");
    }
}
