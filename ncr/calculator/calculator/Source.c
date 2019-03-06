#include<stdio.h>
#include<math.h>
#define MAX_SIZE 25
char str[MAX_SIZE];
int isValidExpression(char *);
int evaluateExpression(char *);
char *infixToPostfix(char* exp);
int main()
{
	printf("enter the expression to be evaluated");
	gets_s(str, MAX_SIZE);
	//if (1 == isValidExpression(str))
	//{
		evaluateExpression(str);
	//}
	system("pause");
}