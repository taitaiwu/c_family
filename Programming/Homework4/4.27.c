#include <stdio.h>

int main (void)
{
    int a,b,c;
    int d=0;

    printf("Right triangle with side length less than 500:\n");

    for (a=1 ; a<501 ;a++)
    {
        for (b=1 ; b<a ; b++)
        {
            for (c=1 ; c<500 ; c++)
            {
                if (c*c==a*a+b*b)
                {
                    d++;
                    if (a<b) printf("(%3d) side1=%3d  slde2=%3d  side3=%3d\n",d,a,b,c);
                    else printf("(%3d) side1=%3d  slde2=%3d  side3=%3d\n",d,b,a,c);
                }
            }
        }
    }
}
