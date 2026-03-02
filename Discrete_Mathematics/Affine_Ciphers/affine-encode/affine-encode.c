# include <stdio.h>
# include <string.h>

int main (void)
{
    FILE *DataIn;
    FILE *DataOut;

    int a, b, letter;
    int i;

    char input[100];

    DataIn = fopen("affine-encode-in.txt", "r");
    DataOut = fopen("affine-encode-out.txt", "w");

    if (DataIn != NULL)
    {
        while (fscanf(DataIn, "%d %d", &a, &b) == 2 && fscanf(DataIn, "%s", input) == 1)
        {
            for (i = 0; i < strlen(input); i++)
            {
                letter = (int)input[i];

                if (letter < 123 && letter > 96) letter -= 97;
                else if ((letter < 91 && letter > 64)) letter -= 65;

                if ((a * letter + b) % 26 < 10) fprintf(DataOut, "0%d", (a * letter + b) % 26);
                else fprintf(DataOut, "%d", (a * letter + b) % 26);
            }

            fprintf(DataOut, "\n");
        }
    }

    fclose(DataIn);
    fclose(DataOut);
    printf("Done!");
}