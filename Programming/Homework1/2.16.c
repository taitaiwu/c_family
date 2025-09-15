#include <stdio.h>

int main(void)
{
    float a,b;

    printf("Please enter the first number:");
    scanf("%f",&a);

    printf("Please enter the second number:");
    scanf("%f",&b);

    printf("\n%.f+%.f=%.f",a,b,a+b);
    printf("\n%.f-%.f=%.f",a,b,a-b);
    printf("\n%.f¡Ñ%.f=%.f",a,b,a*b);
    printf("\n%.f¡Ò%.f=%.f",a,b,a/b);
    printf("...%d\n",(int)a%(int)b);

}
