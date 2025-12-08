# include <stdio.h>
# include <string.h>

int main (void)
{
    char word1[2000][20];
    char word2[2000][20];
    char word3[2000][20];
    char input[20];

    int i = 0, j = 0, m, x, y, a, b;
    int count1, count2 = 0, count3 = 0;
    int same;
    int same_len[20] = {0};
    int same_loc[20] = {0};
    int max = 0;
    int max_loc = 0;
    int bool[2000] = {0};


    FILE *data1;
    FILE *data2;

    data1 = fopen("t10.txt", "r");
    data2 = fopen("t11.txt", "r");

    if (data1 != NULL && data2 != NULL)
    {
        while(fscanf(data1, "%s", input) == 1)
        {
            if (input[strlen(input)-1] == ',' || input[strlen(input)-1] == '.') input[strlen(input)-1] = '\0';

            for (m = 0; m < strlen(input); m++)
            {
                if (((int)input[m]) < 91 && ((int)input[m]) > 64) input[m] = (char)((int)input[m] + 32);
            }

            strcpy(word1[i], input);
            i++;
        }

        while(fscanf(data2, "%s", input) == 1)
        {
            if (input[strlen(input)-1] == ',' || input[strlen(input)-1] == '.') input[strlen(input)-1] = '\0';

            for (m = 0; m < strlen(input); m++)
            {
                if (((int)input[m]) < 91 && ((int)input[m]) > 64) input[m] = (char)((int)input[m] + 32);
            }
            
            strcpy(word2[j], input);
            j++;
        }
    }

    for (x = 0; x < i; x++)
    {
        for (y = 0; y < j; y++)
        {
            if (strcmp(word1[x], word2[y]) == 0)
            {
                count1 = 0;

                while (strcmp(word1[x+count1], word2[y+count1]) == 0)
                {
                    count1++;
                }

                if (count1 >= 7)
                {
                    for (m = x; m < x+count1; m++)
                    {
                        bool[m] = 1;
                    }
                }
            }
        }   
    }

    for (m = 0; m < i; m++)
    {
        if (bool[m] == 1) count3++;
    }

    printf("%d / %d = %.2f %c", count3, i, (float)count3/(float)i*100, '%');
    
    fclose(data1);
    fclose(data2);
}