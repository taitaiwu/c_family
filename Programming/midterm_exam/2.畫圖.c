#include <stdio.h>

int main (void)
{
    int a,b,m,n;
    char c;

    scanf("%d%d %c",&a,&b,&c);

    for (m=1 ; m<=a ; m++)
    {
        for (n=1 ; n<=b ; n++)
        {
            printf("%c",c);
        }
        printf("\n");
    }
}
