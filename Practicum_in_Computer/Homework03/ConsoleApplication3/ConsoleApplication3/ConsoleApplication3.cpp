# include <stdio.h>

int main(void)
{
	int n, counter = 0;
	int w, x, y, z;

	printf("N = ");
	scanf_s(" %d", &n);

	for (w = 1; w < n; w++)
	{
		for (x = w + 1; x < n; x++)
		{
			for (y = x + 1; y < n; y++)
			{
				for (z = y + 1; z < n; z++)
				{
					if ((w + x + y + z) == n)
					{
						counter++;
					}
				}
			}
		}
	}

	printf("Total is %d.", counter);
}