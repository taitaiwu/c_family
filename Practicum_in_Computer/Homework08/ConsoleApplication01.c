# include <stdio.h>

int main (void)
{
    void sort(int *arr, int n);
    
    int nums[100] = {0};
    int i, n;
    
    printf("請輸入整數的個數:");
    scanf("%d", &n);
    
    for (i = 1; i < n+1; i++)
    {
        printf("請輸入第%d個數:", i);
        scanf("%d", &nums[i-1]);
    }
    
    sort(nums, n);
}

void sort(int *arr, int n)
{
    int i, j;
    int temp;
    
    for (i = 0; i < (n-1); i++)
    {
        for (j = 0; j < (n-1-i); j++)
        {
            if (*(arr+j) > *(arr+j+1))
            {
                temp = *(arr+j+1);
                *(arr+j+1) = *(arr+j);
                *(arr+j) = temp;
            }
        }
    }
    
    printf("排序結果:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr+i));
    }
}