# include <stdio.h>

int main(void)
{
	int low, high, i, j, k;
	int sum = 0, max = 0;
	int arr[100000] = { 0 };

	printf("Please input the LowerBound and the UpperBound:");
	scanf_s(" %d %d", &low, &high);

	for (i = low; i <= high; i++)
	{
		j = i;
		sum = j;

		while (j != 1)
		{
			if (j % 2 == 0) j /= 2;
			else j = 3 * j + 1;

			sum += j;
		}

		arr[i] = sum;
	}

	for (i = low; i <= high; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			k = i;
		}
	}

	printf("N=%d Sum=%d", k, max);
}