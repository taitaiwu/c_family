# include <stdio.h>

int main(void)
{
	int n, counter = 0;
	int i, j;
	int prime[100] = { 0 };
	bool is_prime = true;

	printf("Please input a number:");
	scanf_s(" %d", &n);

	for (i = 2; i < n; i++)
	{
		for (j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				is_prime = false;
				continue;
			}
		}

		if (is_prime)
		{
			prime[counter] = i;
			counter++;
		}

		is_prime = true;
	}

	for (i = 0; i < counter; i++)
	{
		if (i == counter - 1)
			printf("%d", prime[i]);
		else
			printf("%d, ", prime[i]);
	}

	printf("\nTotal is %d", counter);
}