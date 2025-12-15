# include <stdio.h>
# include <string.h>

int main (void)
{
    int n;
    int counter1, counter2;
    int i;

    char input[50];
    char word[100][100];

    FILE *DataIn;
    FILE *DataOut;

    printf("The width of word wrap : ");
    scanf("%d", &n);

    DataIn = fopen("t12.txt", "r");
    DataOut = fopen("t13.txt", "w");

    if (DataIn != NULL && DataOut != NULL)
    {
        counter1 = n;

        while(fscanf(DataIn, "%s", input) == 1)
        {
            if (strlen(input) <= counter1)
            {
                fprintf(DataOut, "%s", input);
                counter1 -= strlen(input);

                if (counter1 > 0) 
                {
                    fprintf(DataOut, " ");
                    counter1--;
                }

                else
                {
                    counter1 = n - 1;
                    fprintf(DataOut, "\n ");
                }
            }

            else
            {
                if (strlen(input) > n || strlen(input) > counter1)
                {
                    counter2 = strlen(input);

                    if (counter1 < n-1)
                    {
                        fprintf(DataOut, "\n");
                        counter1 = n;
                    }
                    
                    while (counter2 > 0)
                    {
                        fprintf(DataOut, "%c", input[strlen(input)-counter2]);
                        counter1--;
                        counter2--;

                        if (counter1 == 0) 
                        {
                            counter1 = n;
                            fprintf(DataOut, "\n");
                        }
                    }

                    if (counter1 > 0) 
                    {
                        fprintf(DataOut, " ");
                        counter1--;
                    }

                    else
                    {
                        counter1 = n - 1;
                        fprintf(DataOut, "\n ");
                    }
                }

                else
                {
                    counter1 = n;
                    fprintf(DataOut, "\n%s", input);
                    counter1 -= strlen(input);

                    if (counter1 > 0) 
                    {
                        fprintf(DataOut, " ");
                        counter1--;
                    }

                    else
                    {
                        counter1 = n - 1;
                        fprintf(DataOut, "\n ");
                    }
                }
            }
        }
    }

    fclose(DataIn);
    fclose(DataOut);
}