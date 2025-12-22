# include <stdio.h>
# include <string.h>

int main (void)
{
    int abcba(char input[100], int begin, int end);

    char input[100];
    int list[100000][2] = {0};

    int i, j, k;
    int counter1 = 0;
    int max = 0;

    printf("Please input a string:");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++)
    {
        for (j = i; j < strlen(input); j++)
        {
            if (input[i] == input[j] && abcba(input, i, j))
            {
                list[counter1][0] = i;
                list[counter1][1] = j;
                counter1++;
            }
        }
    }

    for (i = 0; i < 100; i++)
    {
        if (list[i][1] - list[i][0] > max) max = list[i][1] - list[i][0];
    }

    printf("The longest is : ");
    for (i = 0; i < 100; i++)
    {
        if (list[i][1] - list[i][0] == max)
        {
            for (j = list[i][0]; j <= list[i][1]; j++)
            {
                printf("%c", input[j]);
            }

            printf(", ");
        }
    }
}

int abcba(char input[100], int i, int j)
{
    if (i == j) return 1;

    while (i != j)
    {
        if (input[i] != input[j]) return 0;
        i++;
        j--;
    }

    return 1;
}