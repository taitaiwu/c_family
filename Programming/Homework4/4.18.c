#include <stdio.h>

int main (void)
{
    int a,b,c,d,e,i;

    printf("This is a program for drawing bar charts.\n");
    printf("Please enter five numbers between 1 to 30:");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

    while(a>30 || a<1 || b>30 || b<1 || c>30 || c<1 || d>30 || d<1 || e>30 || e<1)
    {
        printf("Enter error,please try again:");
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    }

    printf("\nBar chart below\n\n");


    for (i=1 ; i<=a ; i++)
    {
        printf("*");
    }
    printf("\n");

    for (i=1 ; i<=b ; i++)
    {
        printf("*");
    }
    printf("\n");

    for (i=1 ; i<=c ; i++)
    {
        printf("*");
    }
    printf("\n")
;
    for (i=1 ; i<=d ; i++)
    {
        printf("*");
    }
    printf("\n");

    for (i=1 ; i<=e ; i++)
    {
        printf("*");
    }
    printf("\n");
}
