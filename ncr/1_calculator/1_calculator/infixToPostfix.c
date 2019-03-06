#include<stdio.h>
#include<string.h>
#define MAX_SIZE 25
int top = -1;
char stack[MAX_SIZE];
void push(char item)
{
	if (MAX_SIZE == top)
		printf_s("stack is full");
	else
		stack[++top] = item;
}
char pop()
{

	if (-1 == top)
	{
		printf_s("stack is empty");
		exit(1);
	}

	return stack[top--];
}
char peek()
{

	if (-1 == top)
	{
		printf_s("stack is empty");
		exit(1);
	}

	return stack[top];
}
int isOperator(char ch)
{
	if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/')

		return 1;

	return 0;
}
int precedence(char ch)
{
	if (ch == '(')

		return 0;

	if (ch == '+' || ch == '-')

		return 1;

	if (ch == '*' || ch == '/')

		return 2;
}
char * infixToPostfix(char str[])
{
	printf_s("entred if");
	register int i = 0;
	int len = strlen(str);
	char *result = (char *)malloc(sizeof(char)*len);
	int j = 0;
	for (i = 0; i < len; i++)
	{
		if (isOperator(str[i]) == 1)
		{
			result[j++] = '@';
			if (top == -1)
				push(str[i]);
			else
			{
				if (str[i] == '(')
					push(str[i]);
				else if (str[i] == ')')
				{
					while (str[i] != '(')
						result[j++] = pop();
					pop();
				}
				else
				{

					while (peek() != -1 && precedence(str[i]) <= precedence(peek()))
					{

						result[j++] = pop();

						 

					}
					push(str[i]);
				}
			}
		}
		else
		{
			result[j++] = str[i];
			 
			 
			
		}
	}
	return result;
}
int main()
{
	 
	char s[100];
	printf_s("enter the exp");
	gets_s(s, 100);
	char *result = infixToPostfix(s);
	printf("the result is %s", result);
	system("pause");
}