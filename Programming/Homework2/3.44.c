#include <stdio.h>

int main (void)
{
    int a,b,c;

    printf("Please enter the length of the first side:");
    scanf("%d",&a);
    printf("Please enter the length of the second side:");
    scanf("%d",&b);
    printf("Please enter the length of the third side:");
    scanf("%d",&c);

    if (a+b>c && a+c>b && b+c>a)
    {
        if (a==b && a==c) printf("This is an regular  triangle.");

        else if (a==b || a==c || b==c)
        {
            if (a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a) printf("This is a isosceles righttriangle.");
            else printf("This is a isosceles triangle.");
        }

        else if (a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
        {
            if (a==b || a==c || b==c) printf("This is a isosceles righttriangle.");
            else printf("This is a rectangular triangle.");
        }

        else if (a*a+b*b>c*c && a*a+c*c>b*b && b*b+c*c>a*a) printf("This is a acute triangle.");

        else printf("This is a obtuse  triangle.");
    }

    else
    {
        printf("This is NOT a triangle.");
    }
}

  /*isosceles triangle(���y�T����)
    not a triangle(�����T����)
    regular triangle(���T����)
    rectangular triangle(�����T����)
    obtuse triangle(�w���T����)
    acute triangle(�U���T����)
   isosceles righttriangle(���y�����T����)*/
