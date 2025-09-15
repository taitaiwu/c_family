#include <stdio.h>

int main(void)
{
    int a,b,c,d,e,f;

    printf("Please enter a five-digit number:");
    scanf("%d",&a);

    b=a/10000;
    c=(a%10000)/1000;
    d=((a%10000)%1000)/100;
    e=(((a%10000)%1000)%100)/10;
    f=(((a%10000)%1000)%100)%10;

    printf("%d  %d  %d  %d  %d",b,c,d,e,f);
}
