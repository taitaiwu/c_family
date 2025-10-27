# include <stdio.h>

int main(void)
{
	int n1, n2;
	int x, y;

	while (1)
	{
		printf("總數量+總腳數:");
		scanf_s(" %d+%d", &n1, &n2);

		if (n1 == 0 && n2 == 0) break;

		y = (n2 - (n1 * 2)) / 2;
		x = n1 - y;

		if (x < 0 || y < 0 || (n2 - (n1 * 2)) % 2 != 0)
		{
			printf("無解\n");
		}
		else
		{
			printf("雞%d隻 兔子%d隻\n", x, y);
		}
	}
}