# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef long long LL;
typedef unsigned long long ULL;

LL inverse(LL p, LL q, LL e);
ULL power(ULL a, ULL b, ULL mod);
ULL m_i(ULL m, ULL e, ULL n);


int main (void)
{
    FILE *DataIn;
    FILE *DataOut;

    int e;
    int len;
    int i, j, k = 0, l;
    int counter1 = 1;

    LL p, q, d, n;
    ULL m;
    ULL temp2;

    char input[1000];
    char temp1[1000];
    char temp3[1000];
    char temp4[3];

    DataIn = fopen("RSA-decode-in.txt", "r");
    DataOut = fopen("RSA-decode-out.txt", "w");

    if (DataIn != NULL)
    {
        printf("RSA-decode-in.txt has been successfully loaded.\n\n");

        while (fscanf(DataIn, "%lld %lld %d", &p, &q, &e) == 3 && fscanf(DataIn, "%d", &len) == 1 && fscanf(DataIn, "%s", input) == 1)
        {
            d = inverse(p, q, e);
            n = 1LL * p * q;

            for (i = 0; i < strlen(input); i += len)
            {
                k = 0;

                for (j = i; j < i+len; j++)
                {
                    temp1[k] = input[j];
                    k++;
                }

                temp1[k] = '\0';
                temp2 = strtoull(temp1, NULL, 10);
                m = m_i(temp2, d, n);
                snprintf(temp3, sizeof(temp3), "%0*llu", len, m);

                for (l = 0; l < strlen(temp3); l += 2)
                {
                    temp4[0] = temp3[l];
                    temp4[1] = temp3[l+1];
                    temp4[2] = '\0';

                    fprintf(DataOut, "%c", (int)(strtoull(temp4, NULL, 10) + 65));
                }
            }

            fprintf(DataOut, "\n");
            printf("No.%d test data has been done!\n", counter1); 
            counter1++; 
        }
    }

    else
    {
        printf("RSA-decode-in.txt loadding failed, please try again.\n");
    }

    fclose(DataIn);
    fclose(DataOut);
    printf("\n============================\n");
    printf("All test data has been done!\n");
    printf("You can view it in RSA-decode-out.txt.\n");
}

LL inverse(LL p, LL q, LL e)
{
    LL r1 = (p-1) * (q-1), r2 = e, r3;
    LL s1 = 1, s2 = 0, s3;
    LL t1 = 0, t2 = 1, t3;
    LL temp, result;

    while (r2 != 0)
    {
        temp = r1 / r2;
        r3 = r1 % r2;
        s3 = s1 - temp * s2;
        t3 = t1 - temp * t2;

        r1 = r2;
        r2 = r3;
        s1 = s2;
        s2 = s3;
        t1 = t2;
        t2 = t3;
    }

    result = t1 % ((p-1) * (q-1));

    if (result < 0) result += ((p-1) * (q-1));

    return result;
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

ULL m_i(ULL c, ULL d, ULL n) 
{
    ULL result = 1 % n;
    c %= n;

    while (d > 0) 
    {
        if (d & 1) result = power(result, c, n);

        c = power(c, c, n);
        d >>= 1;
    }
    return result;
}

