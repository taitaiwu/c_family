#include <stdio.h>

int isPrime (int number , int i)
{
    if (i==1) return 1;

    else
    {
        if (number%i==0) return 0;
        else return isPrime(number,i-1);
    }
}

int main (void)
{
    int a;
    printf("Please enter an integer:");
    scanf("%d",&a);

    int result=isPrime(a,a/2);

    if (result==1) printf("%d is a prime number.",a);
    else if (result==0) printf("%d is not a prime number.",a);
}
