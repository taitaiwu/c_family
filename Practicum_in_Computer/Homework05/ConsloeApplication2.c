#include <stdio.h>
#include <string.h>

int main(void)
{
	while(1)
	{
	    char input[17];
    	int temp, total = 0;
    	int num[16] = { 0 };
	
	    printf("請輸入卡號:");
    	scanf("%s", input);
    
    	if (strlen(input) == 15) 
    	{
    	    num[0] = 0;
    	    
    	    for (int i = 1; i < 16; i++)
    	    {
    	        num[i] = input[i-1] - '0';
    	    }
    	}
    	
    	else if (strlen(input) == 16) 
    	{
    	    for (int i = 0; i < 16; i++)
    	    {
    	        num[i] = (int)input[i] - 48;
    	    }
    	}
    	
    	else
    	{
    	    printf("Error! 非15或16個卡號數字");
    	    break;
    	}
    	
    
    	for (int i = 0; i < 15; i++)
    	{
    		if (i % 2 == 0) {
    			temp = num[i] * 2;
    
    			if (temp > 9) temp = temp / 10 + temp % 10;
    
    			total = total + temp;
    		}
    
    		else total += num[i];
    	}

    
    	if (10 - total % 10 == num[15]) printf("卡號正確\n");
    	else if (num[15] == 0 && total % 10 ==0) printf("卡號正確\n");
    	else printf("卡號錯誤\n");
    }
}