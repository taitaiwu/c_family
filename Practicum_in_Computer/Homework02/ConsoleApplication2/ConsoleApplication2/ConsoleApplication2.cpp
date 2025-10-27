# include <stdio.h>

int main(void)
{
	int i, n, temp;
	int total = 0;
	int max = -2147483648; // Minimum value for a 32-bit signed integer
	int min = 2147483647;  // Maximum value for a 32-bit signed integer

	printf("Please input the number of integers:");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		printf("Integer #%d....", i);
		scanf_s("%d", &temp);

		total += temp;
		
		if (temp > max) max = temp;
		if (temp < min) min = temp;
	}

	printf("The average is %.2f\n", (float)total / n);
	printf("The maximum is %d\n", max);
	printf("The minimum is %d\n", min);

}