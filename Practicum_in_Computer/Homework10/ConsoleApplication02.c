# include <stdio.h>
# include <string.h>

int main (void)
{
    char word[100][20];
    char voc[100][20];
    int count[100] = {0};
    char input[50];
    int i = 0, j, k, l = 0, m = 0;

    FILE *DataIn;
    FILE *DataOut;
    
    DataIn = fopen("t3.txt", "r");
    DataOut = fopen("t4.txt", "w");
 
    if (DataIn != NULL && DataOut != NULL)
    {
        while(fscanf(DataIn, "%s", input) == 1)
        {
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

    for (i = 0; i < l; i++)
    {
        fprintf(DataOut, "%s:%d\n", voc[i], count[i]);
    }

    fclose(DataIn);
    fclose(DataOut);
}