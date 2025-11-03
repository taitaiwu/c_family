#include <stdio.h>

int main (void)
{
    int a, b, i, x, y;
    int arr[10] = {0};
    int j = 0;
    
    printf("請輸入A:B......");
    scanf("%d:%d", &a, &b);
    
    for (i = a; i<= b; i++)
    {
        if (i < 10) arr[i] += 1;
        else
        {
            j = i;
            
            while (j > 9)
            {
                arr[j%10] += 1;
                j /= 10;
            }
            
            arr[j] += 1;
        }
    }
    
    printf("0~9出現的次數為......");
    for (j = 0; j < 9; j++)
    {
        printf("%d, ", arr[j]);
    }
    
    printf("%d", arr[9]);
}