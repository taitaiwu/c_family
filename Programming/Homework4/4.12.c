#include <stdio.h>

int main (void)
{
    int i,j,k,l;

    printf("Prime numbers from 1 to 100:2");

    for (i=3 ; i<100 ; i++)
    {
        j=1;

        for(k=2 ; k<i ; k++)
        {
            l=i;

            if (l%k==0)
            {
                j=0;
                break;
            }
        }

        if (j==1) printf(",%d",l);
    }
}
