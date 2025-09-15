#include <stdio.h>

void hanoi(int number, char begin, char regist , char end)
{
    if (number > 0)
    {
        hanoi(number-1, begin, end , regist);

        printf("Move plate %d from %c to %c.\n", number, begin, end);

        hanoi(number-1, regist , begin ,end);
    }
}

int main(void)
{
    int n;
    printf("Please enter the number of floors of Hanoi Tower:");
    scanf("%d", &n);

    char x, y, z;
    printf("Please name the three pillars:");
    scanf(" %c %c %c", &x, &y, &z);

    printf("\n#Attention:The smaller the number, the small the plate!\n\n");

    hanoi(n,x,y,z);
    return 0;
}
