# include <stdio.h>

int main (void)
{
    int n, i, j, k, m = 0, x = 0;
    int prime[1000] = {0};

    printf("Please input a number:");
    scanf("%d", &n);

    for (i = 2; i <= n; i++)
    {
        k = 1;

        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                k = 0;
            }
        }

        if (k == 1)
        {
            prime[m] = i;
            m++;
        }
    }

    for (i = 0; i < m-1; i++)
    {
        if (prime[i]+2  == prime[i+1]) 
        {
            printf("(%d,%d)", prime[i], prime[i+1]);
            x++;
        }
    }

    printf("\nTotal is %d", x);
}