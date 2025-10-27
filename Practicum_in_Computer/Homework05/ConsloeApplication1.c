#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[100], str2[100];
	int i, j, count = 0;
	int sub = 0;

	printf("Please input the string 1:");
	scanf("%s", str1);
	printf("Please input the string 2:");
	scanf("%s", str2);


	for (i = 0; i < strlen(str1)-strlen(str2); i++)
	{
		sub = 0;

		if (str1[i] == str2[0])
		{
			sub = 1;

			for (j = 0; j < strlen(str2); j++)
			{
				if (str2[j] != str1[i + j])
				{
					sub = 0;
					break;
				}
			}
		}

		if (sub == 1) count++;
	}

	if (count > 0)
	{
		printf("String 2 is a substring of String 1.\n");
		printf("Repeat %d times.\n", count);
	}

	else printf("String 2 is not a substring of String 1.\n");
}