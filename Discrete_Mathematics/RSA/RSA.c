# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define BOLD(string) "\x1b[1m" string "\x1b[0m" 
# define RED(string) "\x1b[31m" string "\x1b[0m" 
# define YELLOW(string) "\x1b[33m" string "\x1b[0m" 
# define BLUE(string) "\x1b[34m"string "\x1b[0m" 
# define GREEN(string) "\x1b[36m"string "\x1b[0m" 

typedef long long LL;
typedef unsigned long long ULL;

void encode(void);
void decode(void);
ULL power(ULL a, ULL b, ULL mod);
ULL mod(ULL front, ULL e, ULL back);
LL inverse(LL p, LL q, LL e);

int main(void)
{
    int n = 0;

    printf("Discrete Final Project - Cryptography (RSA Cryptosystem)\n");
    printf("NCUE-CSIE Junior / S1254059 / Jiatai Wu\n");


    while (1)
    {
        printf("\nThere are some function in this program...\n");
        printf("1) RSA-encode\n");
        printf("2) RSA-decode\n");
        printf("3) Both RSA-encode and RSA-decode\n");
        printf("9) " RED("END PROGRAM!")"\n");
        printf("" BLUE("[NOTE]")" Please check " YELLOW("\"RSA-encode-in.txt\"")" and " YELLOW("\"RSA-decode-in.txt\"")" in your files.\n\n");
        printf("Now you can enter a number to select the function that you want.\n");
        printf("Please enter a number : ");
        scanf("%d", &n);

        if (n == 1)
        {
            printf("\n" BOLD("" GREEN("> Function 1 - RSA-encode : ")"")"\n");
            encode();
        }

        else if (n == 2)
        {
            printf("\n" BOLD("" GREEN("> Function 2 - RSA-decode : ")"")"\n");
            decode();
        }

        else if (n == 3)
        {
            printf("\n" BOLD("" GREEN("> Function 3 - Both RSA-encode and RSA-decode : ")"")"\n");
            printf("\n>" BOLD(">RSA-encode : ")"\n");
            encode();
            printf("\n>" BOLD(">RSA-decode : ")"\n");
            decode();
        }

        else if (n == 9)
        {
            printf("\n" BOLD("GOODBYE!!")"\n\n");
            break;
        }

        else printf("\n" BOLD("" RED("Input Error")"")", Please try again!!\n");
    }
}

void encode(void)
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
        printf("  RSA-encode-in.txt has been successfully loaded.\n\n");
        
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
                c = mod(temp4, (ULL)e, (ULL)n);

                snprintf(temp3, sizeof(temp3), "%llu", c);
                fprintf(DataOut, "%0*llu", len, c);
            }

            fprintf(DataOut, "\n");
            printf("  No.%d test data has been done!\n", counter1); 
            counter1++; 
        }
    }

    else
    {
        printf("  RSA-encode-in.txt loadding failed, please try again.\n");
    }

    fclose(DataIn);
    fclose(DataOut);
    printf("\n  ======================================\n");
    printf("  All test data has been done!\n");
    printf("  You can view it in " YELLOW("RSA-encode-out.txt")".\n");
    printf("  ======================================\n");
}

void decode(void)
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
        printf("  RSA-decode-in.txt has been successfully loaded.\n\n");

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
                m = mod(temp2, (ULL)d, (ULL)n);
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
            printf("  No.%d test data has been done!\n", counter1); 
            counter1++; 
        }
    }

    else
    {
        printf("  RSA-decode-in.txt loadding failed, please try again.\n");
    }

    fclose(DataIn);
    fclose(DataOut);
    printf("\n  ======================================\n");
    printf("  All test data has been done!\n");
    printf("  You can view it in " YELLOW("RSA-decode-out.txt")".\n");
    printf("  ======================================\n");
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

ULL mod(ULL front, ULL e, ULL back) 
{
    ULL result = 1 % back;
    front %= back;

    while (e > 0) 
    {
        if (e & 1) result = power(result, front, back);

        front = power(front, front, back);
        e >>= 1;
    }
    return result;
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