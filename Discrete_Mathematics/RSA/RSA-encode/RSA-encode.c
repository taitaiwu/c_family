# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef long long LL;
typedef unsigned long long ULL;

ULL power(ULL a, ULL b, ULL mod) ;
ULL c_i(ULL m, ULL e, ULL n) ;

int main (void)
{
    FILE *DataIn;
    FILE *DataOut;

    int e;
    int len, letter, all = 0;
    int i, j = 0, k;
    int counter1 = 1;

    LL n, p, q;
    ULL c;
    ULL temp4;

    char input[1000];
    char m[1000];
    char temp1[1000];
    char temp2[1000];
    char temp3[1000];

    DataIn = fopen("RSA-encode-in.txt", "r");
    DataOut = fopen("RSA-encode-out.txt", "w");

    if (DataIn != NULL)
    {
        printf("RSA-encode-in.txt has been successfully loaded.\n\n");
        
        while (fscanf(DataIn, "%lld %lld %d", &p, &q, &e) == 3 && fscanf(DataIn, "%d", &len) == 1 && fscanf(DataIn, "%s", input) == 1)
        {
            n = 1LL * p * q;
            j = 0;

            for (i = 0; i < strlen(input); i++)
            {
                letter = input[i];

                if (letter < 123 && letter > 96) letter -= 97;
                else if ((letter < 91 && letter > 64)) letter -= 65;

                snprintf(temp1, sizeof(temp1), "%d", letter);

                if (letter < 10)
                {
                    m[j] = '0';
                    m[j+1] = temp1[0];
                }

                else 
                {
                    m[j] = temp1[0];
                    m[j+1] = temp1[1];
                }

                j += 2;
            }

            m[j] = '\0';

            for (i = 0; i < j; i += len)
            {
                for (k = i; k < i+len; k++)
                {
                    temp2[k-i] = m[k];
                }

                temp2[len] = '\0';
                temp4 = strtoull(temp2, NULL, 10);
                c = c_i(temp4, (ULL)e, (ULL)n);

                snprintf(temp3, sizeof(temp3), "%llu", c);
                fprintf(DataOut, "%0*llu", len, c);
            }

            fprintf(DataOut, "\n");
            printf("No.%d test data has been done!\n", counter1); 
            counter1++; 
        }
    }

    else
    {
        printf("RSA-encode-in.txt loadding failed, please try again.\n");
    }

    fclose(DataIn);
    fclose(DataOut);
    printf("\n============================\n");
    printf("All test data has been done!\n");
    printf("You can view it in RSA-encode-out.txt.\n");
}


ULL power(ULL a, ULL b, ULL mod) 
{
    ULL result = 0;
    a %= mod;

    while (b) 
    {
        if (b & 1)  result = (result + a) % mod;

        a = (a + a) % mod;
        b >>= 1;
    }
    return result;
}

ULL c_i(ULL m, ULL e, ULL n) 
{
    ULL result = 1 % n;
    m %= n;

    while (e > 0) 
    {
        if (e & 1) result = power(result, m, n);

        m = power(m, m, n);
        e >>= 1;
    }
    return result;
}