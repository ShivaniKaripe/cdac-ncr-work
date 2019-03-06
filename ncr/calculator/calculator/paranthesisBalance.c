#include<stdio.h>
#include<stdlib.h>
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
		return -999;
	}

	return stack[top--];
}
char peek()
{

	if (-1 == top)
	{
		return -999;
	}

	return stack[top];
}
int isBalancedParathesis(char *str)
{
	int length = strlen(str);
	register int i = 0;
	for (i = 0; i < length; i++)
	{
		switch (str[i])
		{
		case '(':
		case '[':
		case '{':
			push(str[i]);
			break;
		case ')':
		case ']':
		case '}':
			if (((str[i] == ')') && (peek() == '(')) || ((str[i] == ']') && (peek() == '[')) || ((str[i] == '}') && (peek() == '{')))
				pop();
			break;
		default:
			break;
		}
	}
	if (-1 == top)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 