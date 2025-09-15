#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (void)
{
    int answer;
    int guess;
    int high=100;
    int low=0;
    int count=0;
    int error=0;
    char ch;

    srand(time(NULL));

    printf("~\ This is a guess number game\ ~\n");

    do
    {
        answer=rand()%101;
        high=100;
        low=0;

        printf("Please enter a number from 0 to 100\ :");
        scanf("%d",&guess);
        count++;

        while (guess!=answer)
        {
            while (guess<low || guess>high)
            {
                printf("Input error,please try again\a\ :");
                scanf("%d",&guess);
                error++;
            }

            if (guess<answer)
            {
                low=guess;
                printf("The number is too small,please enter a number from %d to %d\ :",low,high);
                scanf("%d",&guess);
                count++;
            }

            if (guess>answer)
            {
                high=guess;
                printf("The number is too big,please enter a number from %d to %d\ :",low,high);
                scanf("%d",&guess);
                count++;
            }
        }

        if (guess==answer)
        {
            printf("\n~~~~~~\ Congratulations!\ ~~~~~~\n");
            printf("You guessed %d times in this round and input error %d times.\n",count,error);

            if (count==1) printf("¡°\ Excellent!\n\n");
            else if (count==2) printf("¡°\ Unbelievable!\n\n");
            else if (count==3) printf("¡°\ Fantastic!\n\n");
            else if (count==4 ) printf("¡°\ Amazing!\n\n");
            else if (count==5 || count==6) printf("¡°\ Good!\n\n");
            else if (count==7 || count==8) printf("¡°\ Normal.\n\n");
            else printf("¡°\ Don\'t be sad,try again!\n\n");

            if (error>4) printf("Please come on! You had input error to many times.\n\n");
        }

        do
        {
            printf("\nDo you want to continue to the next round?\n");
            printf("¡¹Enter Y to continue,enter N to end:");
            scanf(" %c",&ch);

            if (ch=='N' || ch=='n') printf("\n~~~~~~\  Game over\  ~~~~~~\n");

            if (ch=='Y' || ch=='y')
            {
                printf("\n~~~~\ Welcome a new round\ ~~~~\n");
                count=0;
                error=0;
            }

            if (ch!='N' && ch!='n' && ch!='Y' && ch!='y')
                printf("I don't know what you mean,please try again.\a\n");

        }while (ch!='N' && ch!='n' && ch!='Y' && ch!='y');

    }while (ch=='Y' || ch=='y');


}
