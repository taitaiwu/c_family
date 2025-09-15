#include <stdio.h>

int main (void)
{
    int i, j;

    for (i=1 ; i<10 ; i+=2)
    {
        printf("%*s", (10-i/2) ,"");

        for (j=1 ; j<=i ;j++)
        {
            printf("*");
        }
        printf("\n");
    }

     for (i=7 ; i>0 ; i-=2)
    {
        printf("%*s", (10-i/2) ,"");

        for (j=1 ; j<=i ;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
