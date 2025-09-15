#include <stdio.h>

int main (void)
{
    int a,b,c;
    char s='%';

    scanf("%d%d%d",&a,&b,&c);

    if (c==a+b) printf("+");
    if (c==a-b) printf("-");
    if (c==a*b) printf("*");
    if (c==a%b) printf("%c",s);
    if (c!=a+b && c!=a-b && c!=a*b && c!=a%b) printf("?");
}
