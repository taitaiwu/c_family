#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int union_of_set (void);
int intersection_of_set(void);
int dice_rolling(void);
int turtle_graphics(void);
int duplicate_elimination(void);

int main (void)
{
    printf("This is Homework 6, the following is questions in this homework.\n\n");

    printf("(1)6.14 Union of Set\n");
    printf("(2)6.15 Intersection of Set\n");
    printf("(3)6.19 Dice Rolling\n");
    printf("(4)6.23 Turtle Graphics\n");
    printf("(5)6.28 Duplicate Elimination\n");

    int a,b;

    do
    {
        printf("\nPlease enter number 1~5 to view the question, and enter number \"0\" to exit.\n");
        printf("Which question do you want to read: ");
        scanf("%d",&a);

        if (a==1)
        {
            printf("\n6.14 Union of Set\n\n");
            union_of_set();
        }

        else if (a==2)
        {
            printf("\n6.15 Intersection of Set\n\n");
            intersection_of_set();
        }

        else if (a==3)
        {
            printf("\n6.19 Dice Rolling\n\n");
            dice_rolling();
        }

        else if (a==4)
        {
            printf("\n6.23 Turtle Graphics\n\n");
            turtle_graphics();
        }

        else if (a==5)
        {
            printf("\n6.28 Duplicate Elimination\n\n");
            duplicate_elimination();
        }

        else if (a==0) printf("\n~~~~~Goodbye~~~~~\n");

        else
        {
            while (a<0 || a>5)
            {
                printf("I don\'t know what you mean, please try again: ");
                scanf("%d",&a);
            }
        }
    }while(a!=0);
}


//6.14 Union of Set
int union_of_set (void)
{
    int i,j,k,counter=0;
    int a[10],b[10],c[10];

    srand(time(NULL));

    printf("The first  number list : ");
    for (i=0 ; i<10 ; i++)
    {
        a[i]=rand()%100;
        printf("%2d ",a[i]);
    }

    printf("\nThe second number list : ");
    for (j=0 ; j<10 ; j++)
    {
        b[j]=rand()%100;
        printf("%2d ",b[j]);
    }

    printf("\n---------------------------------------------------------");
    printf("\nUnion of two lists : ");

    for (i=0 ; i<10 ; i++)
    {
        printf("%d ", a[i]);
    }

    for (j=0 ; j<10 ; j++)
    {
        k=0;

        for (i=0 ; i<10 ; i++)
        {
            if (b[j]==a[i])
            {
                k=1;
                break;
            }

        }
        if (k==0) printf("%d ",b[j]);
    }
    printf("\n\n===================================(Separation Line)========================================\n");
}


//6.15 Intersection of Set

int intersection_of_set(void)
{
    int i,j,counter=0;
    int a[10],b[10];

    srand(time(NULL));

    printf("The first  number list : ");
    for (i=0 ; i<10 ; i++)
    {
        a[i]=rand()%100;
        printf("%2d ",a[i]);
    }

    printf("\nThe second number list : ");
    for (j=0 ; j<10 ; j++)
    {
        b[j]=rand()%100;
        printf("%2d ",b[j]);
    }

    printf("\n---------------------------------------------------------");
    printf("\nIntersection of two lists : ");
    for (i=0 ; i<10 ; i++)
    {
        for (j=0 ; j<10 ; j++)
        {
            if (a[i]==b[j])
            {
                printf("%2d ",a[i]);
                counter++;
            }
        }
    }

    if (counter==0) printf("None.");

    printf("\n\n===================================(Separation Line)========================================\n");
}


//6.19 Dice Rolling

int dice_rolling(void)
{
    int a,b,c,i,j,k;
    int table[11]={0};

    for (i=0 ; i<36000 ; i++)
    {
        a=rand()%6+1;
        b=rand()%6+1;
        c=a+b;

        for (j=2 ; j<13 ; j++)
        {
            if (c==j)
            {
                k=j-2;
                table[k]++;
            }
        }

    }

    printf("Total Points\tTimes\t\n");
    for (k=0 ; k<11 ; k++)
    {
        printf("\t%2d\t %4d\n ",k+2,table[k]);
    }

    printf("\n===================================(Separation Line)========================================\n");
}


//6.23 Turtle Graphics

int floor[50][50]={0};
int x=0,y=0;

int draw (int pen,int number,int angle);

int turtle_graphics(void)
{
    printf("This is a program about Turtle Graphics.\n");
    printf("The following table is about orders to the turtle.\n\n");

    printf("Command\t Meaning\n");
    printf("-------------------------------------------------------------\n");
    printf("1\t Pen up\n");
    printf("2\t Pen down\n");
    printf("3\t Turn right\n");
    printf("4\t Turn left\n");
    printf("5,10\t Move forward 10 spaces (or a number other than 10)\n");
    printf("6\t Print the 50-by-50 array\n");
    printf("9\t End of data (sentinel)\n\n");

    printf("Now you can start creating.\n");

    int a,b,m,n,pen,angle=0;

    while(1)
    {
        scanf("%d,%d",&m,&n);

        if (m==1) pen=0;

        else if (m==2) pen=1;

        else if (m==3)
        {
            angle-=90;
            if (angle<0) angle+=360;
            if (angle>360) angle%=360;
        }

        else if (m==4)
        {
            angle+=90;
            if (angle<0) angle+=360;
            if (angle>360) angle%=360;
        }

        else if (m==5) draw(pen,n,angle);

        else if (m==6)
        {
            for(a=0 ; a<50 ; a++)
            {
                for(b=0 ; b<50 ; b++)
                {
                    if(floor[a][b]==1) printf("# ");
                    else printf("  ");
                }
                printf("\n");
            }
        }

        else if (m==9) break;
    }

    printf("\n\n===================================(Separation Line)========================================\n");
}

int draw (int pen,int number,int angle)
{
    int m;

    if (pen==1)
    {
        if(angle==0)
        {
            for(m=0 ; m<number ; m++)
            {
                if (y<49)
                {
                    floor[x][y]=1;
                    y++;
                }
            }
        }

        if(angle==90)
        {
            for(m=0 ; m<number ; m++)
            {
                if (x>0)
                {
                    floor[x][y]=1;
                    x--;
                }
            }
        }

        if(angle==180)
        {
            for(m=0 ; m<number ; m++)
            {
                if (y>0)
                {
                    floor[x][y]=1;
                    y--;
                }
            }
        }

        if(angle==270)
        {
            for(m=0 ; m<number ; m++)
            {
                if (x<49)
                {
                    floor[x][y]=1;
                    x++;
                }
            }
        }
    }
}


//6.28 Duplicate Elimination

int duplicate_elimination(void)
{
    int a=0,i,j,k=0,counter=1;
    int number[20];
    int list[20];

    srand(time(NULL));


    printf("Original list : ");

    for(i=0 ; i<20 ; i++)
    {
        number[i]=rand()%20+1;
        printf("%2d ",number[i]);
    }

    printf("\n");

    for(i=0 ; i<20 ; i++)
    {
        for(j=0 ; j<=i ; j++)
        {
            k=0;

            if (number[i]==number[j] && i!=j)
            {
                k=1;
                break;
            }

        }

        if (k==0)
        {
            list[a]=number[i];
            a++;
        }

    }

    printf("Processed list: ");

    for(i=0 ; i<a ; i++)
    {
        printf("%2d ",list[i]);
    }


    printf("\n\n===================================(Separation Line)========================================\n");
}
