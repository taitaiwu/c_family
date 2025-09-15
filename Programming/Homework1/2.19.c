#include <stdio.h>

int main(void)
{
    int a,b,c,sum,average,product,smallest,largest;

    printf("Enter three different integers:");
    scanf("%d%d%d",&a,&b,&c);

    sum=a+b+c;
    printf("Sum is %d\ \n",sum);

    average=sum/3;
    printf("Average is %d\ \n",average);

    product=a*b*c;
    printf("Product is %d\ \n",product);

    if (a<b && a<c)
    {
        smallest=a;
        printf("Smallest is %d\ \n",smallest);
    }

    else if (b<a && b<c)
    {
        smallest=b;
        printf("Smallest is %d\ \n",smallest);
    }

    else
    {
        smallest=c;
        printf("Smallest is %d\ \n",smallest);
    }

    if (a>b && a>c)
    {
        largest=a;
        printf("Largest is %d\ \n",largest);
    }

    else if (b>a && b>c)
    {
        largest=b;
        printf("Largest is %d\ \n",largest);
    }

    else
    {
        largest=c;
        printf("Largest is %d\ \n",largest);
    }
}
