# include <stdio.h>
# include <string.h>

int main (void)
{
    char input[50];
    int nums[26] = {0};
    int i, j;
    int counter = 0;
    int repeat = 0;

    FILE *DataIn;

    DataIn = fopen("t15.txt", "r");

    if (DataIn != NULL)
    {
        while(fscanf(DataIn, "%s", input) == 1)
        {
            int nums[26] = {0};
            counter = 0;
            repeat = 0;

            if (strlen(input) == 1) 
            {
                printf("No\n");
                continue;;
            }

            for (i = 0; i < strlen(input); i++)
            {
                if ((int)input[i] > 64 && (int)input[i] < 91)
                {
                    nums[(int)input[i]-65]++;
                }

                else if ((int)input[i] > 96 && (int)input[i] < 123)
                {
                    nums[(int)input[i]-97]++;
                }
            }

            for (i = 0; i < 26; i++)
            {
                if (nums[i] == 0) counter++;
            }

            for (i = 0; i < 26; i++)
            {
                for (j = 0; j < i; j++)
                {
                    if (nums[j] == nums[i] && nums[j] != 0) 
                    {
                        repeat = 1;
                        break;
                    }
                }
            }
            
            if (counter >= 25 || repeat == 1)  printf("No\n");
            else printf("Yes\n");
        }
    }

    fclose(DataIn);
}