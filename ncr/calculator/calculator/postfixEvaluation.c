#include<stdio.h>
int stack2[20];
int top2 = -1;

void push2(int x)
{
	stack2[++top2] = x;
}

int pop2()
{
	return stack2[top2--];
}

int postfixEval(char *exp)
{
	
	char *e;
	int n1, n2, n3, num;
	 
	e = exp;
	while (*e != '\0')
	{
		if (isdigit(*e))
		{
			num = *e - 48;
			push2(num);
		}
		else
		{
			n1 = pop2();
			n2 = pop2();
			switch (*e)
			{
			case '+':
			{
				n3 = n1 + n2;
				break;
			}
			case '-':
			{
				n3 = n2 - n1;
				break;
			}
			case '*':
			{
				n3 = n1 * n2;
				break;
			}
			case '/':
			{
				n3 = n2 / n1;
				break;
			}
			}
			push2(n3);
		}
		e++;
	}
	
	return  pop2();

}