#include <stdio.h>

int main (void)
{
    int a=1;
    int count=1;

    while (count<56)
    {
        printf("%d\ ",count);
        count=count+1;
        a=a+1;

        if (a==2 || a==4 || a==7 || a==11 || a==16 || a==22 || a==29 || a==37 || a==46) printf("\n");
    }
}


