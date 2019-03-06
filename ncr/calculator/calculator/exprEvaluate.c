#include<stdio.h>
#include<string.h>
int evaluateExpression(char * str)
{
	char *temp = InfixToPostfix(str);
	int result = postfixEval(temp);
	return result;
}