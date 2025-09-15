#include <stdio.h>

int main(void)
{
	int a;

	printf("Please enter a positiveinteger:");
	scanf("%d", &a);

	if (a < 0) printf("%d is not a positive integer!!\n", a);
	else if (a > 0 && a < 10) printf("%d is a small integer.", a);
	else if (a > 9 && a < 100) printf("%d的十位數為%d\n%d的個位數為%d", a, a / 10, a, a % 10);
	else if (a > 99 && a % 5 == 0) printf("%d is a large integer.\n%d is divisible by 5.", a, a);
	else if (a > 99 && a % 5 == 1) printf("%d is a large integer.\n%d+5=%d", a, a, a + 5);
	else if (a > 99 && a % 5 == 2) printf("%d is a large integer.\n%d-5=%d", a, a, a - 5);
	else if (a > 99 && a % 5 == 3) printf("%d is a large integer.\n%d*5=%d", a, a, a * 5);
	else if (a > 99 && a % 5 == 4) printf("%d is a large integer.\n%d/5=%.2f", a, a, (float)a / 5);
}