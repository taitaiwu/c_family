# include <stdio.h>
# include <string.h>

int main (void)
{
    char word[100][20];
    char voc[100][20];
    int count[100] = {0};
    char input[50];
    char temp[20];
    int i = 0, j, k, l = 0, m = 0, x, y, z;
    int temp2;
    int counter = 0;

    FILE *DataIn;
    FILE *DataOut;
    
    DataIn = fopen("t5.txt", "r");
    DataOut = fopen("t6.txt", "w");
 
    if (DataIn != NULL && DataOut != NULL)
    {
        while(fscanf(DataIn, "%s", input) == 1)
        {
            if (input[strlen(input)-1] == ',' || input[strlen(input)-1] == '.') input[strlen(input)-1] = '\0';

            for (x = 0; x < strlen(input); x++)
            {
                if (((int)input[x]) < 91 && ((int)input[x]) > 64) input[x] = (char)((int)input[x] + 32);
            }

            strcpy(word[i], input);
            i++;
        }
    }

    for (j = 0; j < i; j++)
    {
        m = 0;

        for (k = 0; k < l; k++)
        {
            if (word[j][strlen(word[j])-1] == '.' || word[j][strlen(word[j])-1] == ',') word[j][strlen(word[j])-1] = '\0';

            if (strcmp(word[j], voc[k]) == 0)
            {
                count[k]++;
                m = 1;
            }

        }

        if (m == 0)
        {
            strcpy(voc[l], word[j]);
            count[l]++;
            l++;
        } 
    }

    for (x = 0; x < l; x++)
    {
        for (y = 0; y < l; y++)
        {
            if (strcmp(voc[x], voc[y]) == -1) 
            {
                strcpy(temp, voc[y]);
                strcpy(voc[y], voc[x]);
                strcpy(voc[x], temp);

                temp2 = count[y];
                count[y] = count[x];
                count[x] = temp2;
            }
        }
    }

    

    for (i = 0; i < l; i++)
    {
        fprintf(DataOut, "%s:%d\n", voc[i], count[i]);
    }

    fclose(DataIn);
    fclose(DataOut);
}