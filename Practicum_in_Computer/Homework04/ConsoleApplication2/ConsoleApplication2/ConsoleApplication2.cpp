# include <stdio.h>

int main(void)
{
	int n1, n2, i;

	printf("Please input two integers:");
	scanf_s(" %d %d", &n1, &n2);

	if (n1 <= n2)
	{
		for (i = n1; i > 0; i--)
		{
			if (n1 % i == 0 && n2 % i == 0)
			{
				printf("GCD is %d", i);
				break;
			}
		}
	}

	else
	{
		for (i = n2; i > 0; i--)
		{
			if (n1 % i == 0 && n2 % i == 0)
			{
				printf("GCD is %d", i);
				break;
			}
		}
	}
}