# include <stdio.h>
# include <string.h>

int main (void)
{
    int n, i, j;
    int sum1 = 0, sum2 = 0;
    int null = 0;

    FILE *DataIn;

    DataIn = fopen("t16.txt", "r");

    if (DataIn != NULL)
    {
        while(fscanf(DataIn, "%d", &n) == 1)
        {
            for (i = 0; i <= n; i++)
            {
                sum1 = 0;
                sum2 = 0;
                null = 1;

                for (j = 0; j < i; j++)
                {
                    sum1 += j;
                }

                for (j = i+1; j <= n; j++)
                {
                    sum2 += j;
                }

                if (sum1 == sum2)
                {
                    printf("%d\n", i);
                    null = 0;
                    break;
                }
            }

            if (null == 1) printf("null\n");
        }
    }

    fclose(DataIn);
}