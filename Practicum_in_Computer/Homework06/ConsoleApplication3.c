#include <stdio.h>

int main(void)
{
    int century;
    printf("Please input the century: ");
    scanf("%d", &century);

    int m = (century - 1) * 100 + 1;
    int n = century * 100;

    int count = 0;

    for (int y = m; y <= n; y++) 
    {
        int i = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);

        int w = (y + (y - 1)/4 - (y - 1)/100 + (y - 1)/400) % 7;

        int m[12] = {31, 28+i, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for (int j = 0; j < 12; j++) 
        {
            int d = (w + 12) % 7; 
            if (d == 5) count++;
            w = (w + m[j]) % 7; 
        }
    }

    printf("%d times!!\n", count);
    return 0;
}
