#include<stdio.h>
#include<string.h>
int isBalancedParathesis(char *);
int noSpeacialcharacters(char *);
int isValidExpression(char *str)
{
	if (isBalancedParathesis(str) == 1)
	{
		if (noSpeacialcharacters(str)==1)
		{
			if (str[0] <= '9'&&str[0] >= '0'&&str[strlen(str) - 1] <= '9'&&str[strlen(str) - 1] >= '0')
				return 1;
			else
			{
				printf_s("\n first or last character of the expression is invalid");
				return 0;
			}
		}
		else
		{
			printf_s("\n special characters are there");
			return 0;
		}
	}
	else
	{
		printf_s("\n no balanced paranthesis");
		return 0;
	}
}