# include <stdio.h>
# include <string.h>

int main (void)
{
    int n1, n2, i, j, k;
    int max = 0;
    int nums[50] = {0};
    int product[50][50] = {0};
    int relation[30][30] = {0};

    FILE *DataIn;

    DataIn = fopen("t9.txt", "r");

    if (DataIn != NULL)
    {
        fscanf(DataIn, "%d", &n1);

        for (i = 0; i < n1; i++)
        {
            fscanf(DataIn, "%d", &n2);
            nums[i] = n2;

            for (j = 0; j < n2; j++)
            {
                fscanf(DataIn, "%d", &product[i][j]);
            }
        }
        
    }

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < nums[i]; j++)
        {
            for (k = j+1; k < nums[i]; k++)
            {
                relation[product[i][j]][product[i][k]]++;
            }
        }
    }

    for (i = 1; i < 30; i++)
    {
        for (j = i+1; j < 30; j++)
        {
            if (relation[i][j] > max) max = relation[i][j];
        }
    }

    for (i = 1; i < 30; i++)
    {
        for (j = i+1; j < 30; j++)
        {
            if (relation[i][j] == max) printf("(%d,%d) %d times\n", i, j, max);
        }
    }

    fclose(DataIn);
}