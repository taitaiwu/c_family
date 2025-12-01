# include <stdio.h>

int main (void)
{
    int ugly(int n);
    int n, i=1, counter = 0;
    
    printf("Please input a number:");
    scanf("%d", &n);
    
    while(counter < n)
    {
        if (ugly(i)) 
        {
            counter++;
            printf("%d, ", i);
        }
        
        i++;
    } 
}

int ugly(int n)
{
    while (n % 2 == 0 && n > 0)
    {
        n /= 2;
    }
    
    while (n % 3 == 0 && n > 0)
    {
        n /= 3;
    }
    
    while (n % 5 == 0 && n > 0)
    {
        n /= 5;
    }
    
    return n == 1;
}