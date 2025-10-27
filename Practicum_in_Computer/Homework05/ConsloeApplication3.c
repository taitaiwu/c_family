#include <stdio.h>

int main (void)
{
    long long int n;
    int  prime = 1, j = 0;
    int num[100] = {0};
    
    printf("Please input a number n (1<n<1000000000):");
    scanf(" %lld", &n);

    printf("%lld = ", n);
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            num[j] = i;
            j++;
        }
    }

    for (int i = 0; i < j-1; i++)
    {
        printf("%d*", num[i]);
    }
    
    printf("%d", num[j-1]);
}