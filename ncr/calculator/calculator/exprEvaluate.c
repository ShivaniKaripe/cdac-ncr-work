#include<stdio.h>
#include<string.h>

//int  InfixToPostfix(char *);
//this function evaluate the expression
int evaluateExpression(char * str)
{

	printf_s("in eval");
	//conversion of infixToPostfix 
	//it returns the result of the expression
	int temp_result = InfixToPostfix(str);
	 
	 
	return temp_result;
}