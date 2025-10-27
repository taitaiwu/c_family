#include <stdio.h>

int main(void)
{
	int n, i;
	int temp1 = 0;
	int temp2 = 1;
	int temp3;

	printf("Please input a number: ");
	scanf_s(" %d", &n);

	printf("0, 1, ");

	for (i = 2; i < n-1; i++)
	{
		temp3 = temp1 + temp2;
		printf("%d, ", temp3);
		temp1 = temp2;
		temp2 = temp3;
	}

	printf("%d", temp1 + temp2);
}