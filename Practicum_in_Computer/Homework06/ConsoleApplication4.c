#include <stdio.h>
#include <string.h>

int main (void)
{
    char str1[50], str2[50];
    int  i, j;
    int count1[26] = {0}, count2[26] = {0};
    int da = 1;
    
    printf("Please input string #1:");
    scanf(" %[^\n]", str1);
    
    printf("Please input string #2:");
    scanf(" %[^\n]", str2);
    
    for (i = 0; i < strlen(str1); i++)
    {
        if ((int)str1[i] > 64 && (int)str1[i] < 91) count1[(int)str1[i]-64] += 1;
        else if ((int)str1[i] > 96 && (int)str1[i] < 123) count1[(int)str1[i]-96] += 1;
    }
    
    for (i = 0; i < strlen(str2); i++)
    {
        if ((int)str2[i] > 64 && (int)str2[i] < 91) count2[(int)str2[i]-64] += 1;
        else if ((int)str2[i] > 96 && (int)str2[i] < 123) count2[(int)str2[i]-96] += 1;
    }
    
    
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            printf("No");
            da = 0;
            break;
        }
    }
    
    if (da == 1) printf("Yes");
}