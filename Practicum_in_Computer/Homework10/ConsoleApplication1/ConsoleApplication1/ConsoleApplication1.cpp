# include <stdio.h>

int main(void)
{
    char ch;
    int vowel[5] = { 0 };
    int i;

    FILE* DataIn;
    FILE* DataOut;

    DataIn = fopen("t1.txt", "r+");
    DataOut = fopen("t2.txt", "w+");

    if (DataIn != NULL && DataOut != NULL)
    {
        while ((ch = fgetc(DataIn)) != EOF)
        {
            if (ch == 'a' || ch == 'A') vowel[0]++;
            else if (ch == 'e' || ch == 'E') vowel[1]++;
            else if (ch == 'i' || ch == 'I') vowel[2]++;
            else if (ch == 'o' || ch == 'O') vowel[3]++;
            else if (ch == 'u' || ch == 'U') vowel[4]++;
        }
    }

    fprintf(DataOut, "A\tE\tI\tO\tU\n");
    for (i = 0; i < 5; i++)
    {
        fprintf(DataOut, "%d\t", vowel[i]);
    }

    fclose(DataIn);
    fclose(DataOut);
}