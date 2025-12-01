# include <stdio.h>
# include <string.h>

int main (void)
{
    void check_ISBN10(char *arr);
    void check_ISBN13(char *arr);
    
    char input[14];
    
    while (1)
    {
        printf("Please input an ISBN code:");
        scanf("%s", input);
    
        if (strlen(input) == 10) check_ISBN10(input);
        else if (strlen(input) == 13) check_ISBN13(input);
        else 
        {
            printf("Error!");
            break;
        }
    }
}

void check_ISBN10(char *arr)
{
    int i;
    int total = 0;
    
    for (i = 0; i < 10; i++)
    {
        if ((i == 9) && (*(arr+9) == 'X')) total += 58 * (10 - i);
        else total += *(arr+i) * (10 - i);
    }
    
    if (total % 11 == 0) printf("The ISBN code is correct!!\n");
    else printf("The ISBN code is wrong!!\n");
}

void check_ISBN13(char *arr)
{
    int i;
    int total = 0;
    
    for (i = 0; i < 12; i++)
    {
        if (i % 2 == 0) total += *(arr+i) - '0';
        else total += (*(arr+i) - '0') * 3;
    }
    
    if (10 - (total % 10) == (*(arr+12) - '0')) printf("The ISBN code is correct!!\n");
    else if (10 - (total % 10) == 10) printf("The ISBN code is correct!!\n");
    else printf("The ISBN code is wrong!!\n");
}