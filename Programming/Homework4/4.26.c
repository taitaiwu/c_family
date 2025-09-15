#include <stdio.h>
#include <math.h>

int main (void)
{
    double n,k,Pi;
    int counter=0;
    int c314=0,c3141=0,c31415=0,c314159=0;

    Pi=0;
    for (n=1 ;  ; n+=2)
    {
        k=4/n;
        counter++;

        if (counter%2==0)
        {
            k=k*(-1);
        }

        Pi=Pi+k;

        if (c314==0 && (int)(Pi*100)==314)
        {
            c314++;
            printf("3.14\t using %6d items.\n",counter);
        }

        if (c3141==0 && (int)(Pi*1000)==3141)
        {
            c3141++;
            printf("3.141\t using %6d items.\n",counter);
        }

        if (c31415==0 && (int)(Pi*10000)==31415)
        {
            c31415++;
            printf("3.1415\t using %6d items.\n",counter);
        }

        if (c314159==0 && (int)(Pi*100000)==314159)
        {
            c314159++;
            printf("3.14159\t using %6d items.\n",counter);
            break;
        }

    }


}






