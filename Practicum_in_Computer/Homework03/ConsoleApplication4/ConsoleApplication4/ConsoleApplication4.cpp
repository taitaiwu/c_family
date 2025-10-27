# include <stdio.h>

int main(void)
{
	int i, j, k, n, index = 1;

	printf("Please input a number:");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = n - i; j > 0; j--)
			printf(" ");

		for (k = 1; k <= i; k++)
			printf("%d", k%10);

		for (k = i - 1; k > 0; k--)
			printf("%d", k % 10);

		printf("\n");
	}
}
