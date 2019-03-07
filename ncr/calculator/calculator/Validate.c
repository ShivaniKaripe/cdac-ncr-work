#include<stdio.h>
#include<string.h>
//"isBalanedParanthesis" function declaration
int isBalancedParathesis(char *);
//int noSpeacialcharacters(char *);
//"isValidExpression" checks whether the expression is valid or not
int isValidExpression(char *str)
{
	//checks if the paranthesis in the expression are balance or not
	if (isBalancedParathesis(str) == 1)
	{
		 //if balance parantheisi are there then function returns '1'
		return 1;
	}
	else
	{
		//if balance parantheisi are not there then function returns '0'
		printf_s("\n in the expression balanced paranthesis are not there");
		printf_s("\n the expression is invalid");
		return 0;
	}
}