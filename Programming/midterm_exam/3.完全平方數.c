#include <stdio.h>
#include <math.h>

int main (void)
{
    int a,b,i,j,y,z=0;
    float x;

    scanf("%d%d",&a,&b);

    for (i=a ; i<=b ; i++)
    {
        x=pow(i,0.5);
        y=(int)x;

        if(x==y)
        {
            z=z+i;
        }
    }

    printf("%d",z);
}
