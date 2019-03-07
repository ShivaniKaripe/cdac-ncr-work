//this program is to evaluate the expression
#include<stdio.h>
#include<math.h>
#define MAX_SIZE 25
char str[MAX_SIZE];
//declaration of the functions
//"isValidExpression" checks for the balanced paranthesis
//"evaluateExpression" evaluates the result of the expression
int isValidExpression(char *);
int evaluateExpression(char *);
 
int main()
{
	int final_res;
	//the input string is stored in 'str'
	printf("enter the expression to be evaluated");
	gets_s(str, MAX_SIZE);
	//checking whether it is valid expression or not
	if (1 == isValidExpression(str))
	{
		//if it is valid expression then "evaluateExpression" is called
		final_res = evaluateExpression(str);
		printf_s("the final result of the expression is %d", final_res);
	}
	//to stop the terminal from exiting
	system("pause");
}