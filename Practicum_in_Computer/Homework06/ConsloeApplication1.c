#include <stdio.h>
#include <string.h>
#include <math.h>

int main (void)
{
    int dec;
    int dec_arr[100] = {0};
    int i = 0, j = 0;
    char bin[100];
    
    printf("Please input a decimal number:");
    scanf("%d", &dec);

    while (dec != 0)
    {
        dec_arr[i] = dec % 2;
        dec /= 2;
        i++;
    }
    
    for (j = i; i >= 0; i--)
    {
        if ((dec_arr[i] == 0) && (j == i))
            continue;
        printf("%d", dec_arr[i]);
    }
    
    printf("\nPlease input a binary number:");
    scanf("%s", bin);
    dec = 0;
    j = 0;
    
    for (i = strlen(bin) - 1; i >= 0; i--)
    {
        dec += ((int)bin[i] - '0') * pow(2, j);
        j++;
    }
    
    printf("%d", dec);
}