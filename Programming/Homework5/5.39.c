#include <stdio.h>

int gcd (int x ,int y)
{
    if (y==0) return x;
    else return gcd(y,x%y);
}

int lcm (int x, int y)
{
    return (x*y)/gcd(x,y);
}

int main (void)
{
    int a,b;
    printf("Please enter two numbers:");
    scanf("%d%d",&a,&b);

    int gcd_answer=gcd(a,b);
    printf("%d and %d\'s greatest common divisor is %d.\n",a,b,gcd_answer);

    int lcm_answer=lcm(a,b);
    printf("%d and %d\'s lowest common Multiple is %d.\n",a,b,lcm_answer);
}


