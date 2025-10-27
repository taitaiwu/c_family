#include <stdio.h>

int main(void)
{
	int num1, num2, i, sum;
	char a;

	while (1)
	{
		printf("Number 1:");
		scanf_s(" %d", &num1);
		printf("Number 2:");
		scanf_s(" %d", &num2);

		if (num1 > num2)
		{
			printf("Error!! Number1 > Number2!!\n");
			continue;
		}

		else
		{
			sum = 0;

			for (i = num1; i <= num2; i++)
			{
				sum += i;
			}

			printf("Sum = %d\n", sum);
		}

		printf("Again(Y/N)??");
		scanf_s(" %c", &a);

		if (a == 'N' || a == 'n') break;
	}
}