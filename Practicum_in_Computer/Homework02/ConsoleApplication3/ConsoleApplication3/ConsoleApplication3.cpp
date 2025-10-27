# include <stdio.h>

int main(void)
{
	int i, j, k, n, index=1;

	printf("Please input a number:");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = n - i; j > 0; j--)
			printf(" ");

		for (k = 0; k < i*2-1; k++)
			printf("%d", index);

		index++;
		if (index == 10) index = 0;
		printf("\n");
	}
}
