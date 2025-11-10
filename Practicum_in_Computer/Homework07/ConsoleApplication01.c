# include <stdio.h>
int counter = 0;

int main (void)
{
    void towers(int n, char from, char aux, char to);
    
    int n;
    
    printf("請輸入A柱中環個數:");
    scanf("%d", &n);
    towers(n, 'A', 'B', 'C');
    printf("共需%d個步驟", counter);
}

void towers(int n, char from, char aux, char to)
{
    if (n > 0)
    {
        towers(n-1, from, to, aux);
        printf("ring %d: %c => %c\n", n, from, to);
        counter++;
        towers(n-1, aux, from, to);
    }
}
