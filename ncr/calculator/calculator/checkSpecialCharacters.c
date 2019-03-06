#include<stdio.h>
int noSpeacialcharacters(char*str)
{
	register int i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= '0'&&str[i] >= '9') || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')');
		else
		{
			printf_s("\n invalid characters are there in the expression");
			return 0;
		}
			
	}
	return 1;
}