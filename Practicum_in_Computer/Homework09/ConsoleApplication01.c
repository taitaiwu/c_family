# include <stdio.h>

int main (void)
{
    void sort_fraction(int (*ptr)[2], int n);
    int gcd(int n1, int n2);
    
    int n, i, j, counter = 0;
    int frac[200][2];
    
    printf("Please input a number:");
    scanf("%d", &n);
    
    for (i = 1; i < n+1; i++)
    {
        for (j = 1; j < i; j++)
        {
            if (gcd(i, j) != 1) continue;
            
            frac[counter][1] = i;
            frac[counter][0] = j;
            
            counter++;
        }
    }
    
    sort_fraction(frac, counter);
}

void sort_fraction(int (*ptr)[2], int n)
{
    int i, j, temp1, temp2;
    
    for (i = 0; i < (n-1); i++)
    {
        for (j = 0; j < (n-1-i); j++)
        {
            if ((float)ptr[j][0]/(float)ptr[j][1] > (float)ptr[j+1][0]/(float)ptr[j+1][1])
            {
                temp1 = ptr[j][0];
                temp2 = ptr[j][1];
                
                ptr[j][0] = ptr[j+1][0];
                ptr[j][1] = ptr[j+1][1];
                
                ptr[j+1][0] = temp1;
                ptr[j+1][1] = temp2;
            }
        }
    }
    
    printf("%d, ", 0);
    
    for (i = 0; i < n; i++)
    {
        printf("%d/%d, ", ptr[i][0], ptr[i][1]);
    }
    
    printf("%d (total number: %d)", 1, n+2);
}

int gcd(int n1, int n2)
{
    int i, small;
    
    if (n1 > n2) small = n2;
    else if (n1 < n2) small = n1;
    else return n1;
    
    for (i = small; i > 0; i--)
    {
        if (n1 % i == 0 && n2 % i == 0) return i;
    }
}