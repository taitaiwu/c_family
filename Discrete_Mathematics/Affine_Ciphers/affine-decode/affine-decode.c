# include <stdio.h>
# include <string.h>

int main (void)
{
    FILE *DataIn;
    FILE *DataOut;

    int a1, a2;
    int b, c, p, q;
    int s1, s2, s3;
    int t1, t2, t3;
    int r1, r2, r3;
    int i, temp;

    char input[50];

    DataIn = fopen("affine-decode-in.txt", "r");
    DataOut = fopen("affine-decode-out.txt", "w");

    if (DataIn != NULL)
    {
        while (fscanf(DataIn, "%d %d", &a1, &b) == 2 && fscanf(DataIn, "%s", input) == 1)
        {
            r1 = 26;
            r2 = a1;
            s1 = 1;
            s2 = 0;
            t1 = 0;
            t2 = 1;


            while (r2 != 0)
            {
                q = r1 / r2;
                r3 = r1 % r2;
                s3 = s1 - q * s2;
                t3 = t1 - q * t2;

                r1 = r2;
                r2 = r3;
                s1 = s2;
                s2 = s3;
                t1 = t2;
                t2 = t3;
            }

            a2 =  (t1 % 26 + 26) % 26;
           
            for (i = 0; i < strlen(input); i += 2)
            {
                c = (input[i] - '0') * 10 + (input[i+1] - '0');
                temp = (c - b) % 26;

                if (temp < 0) temp += 26;

                p = (a2 * temp) % 26 + 65;

                fprintf(DataOut, "%c", p);
            }
        }
    }

    fclose(DataIn);
    fclose(DataOut);
    printf("Done!");
}