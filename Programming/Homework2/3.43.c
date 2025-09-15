#include <stdio.h>

int main (void)
{
    int a,b,c;

    printf("Please enter the length of the first side:");
    scanf("%d",&a);
    printf("Please enter the length of the second side:");
    scanf("%d",&b);
    printf("Please enter the length of the third side:");
    scanf("%d",&c);

    if ( a+b>c && a+c>b && b+c>a )
    {
        printf("This is a triangle.");
    }

    else
    {
        printf("This is NOT a triangle.");
    }
}
