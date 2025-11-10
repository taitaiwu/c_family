# include <stdio.h>
# include <string.h>

int main (void)
{
    int frac(int n);
    
    char string[12];
    int letter[12] = {0};
    int i, j, k = 0;
    int same = 0;
    int m = 1;
    int outcome = 0;
    
    printf("Please input a string:");
    scanf("%s", string);
    
    for (i = 0; i < strlen(string); i++)
    {
        same = 0;
        
        for (j = 0; j < i; j++)
        {
            if (string[i] == string[j])
            {
                same = 1;
                letter[j]++;
                break;
            }
        }
        
        if (same == 0) letter[i]++;
    }
    
    for (int i = 0; i < 12; i++)
    {
        if (letter[i] != 0) m *= frac(letter[i]);
    }
    
    outcome = frac(strlen(string)) / m;
    
    printf("The number of permutations is %d", outcome);
}

int frac(int n)
{
    int i, sum = 1;
    
    for (i = 1; i <= n; i++)
    {
        sum *= i;
    }
    
    return sum;
}