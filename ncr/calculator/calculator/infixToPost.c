//evaluation of infix to postfix
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define SIZE 50
char s[SIZE];
int top1 = -1;
int postfixEval(char *);
push1(char elem)
{
	s[++top1] = elem;
}

char pop1()
{
	return(s[top1--]);
}

int pr(char elem)
{
	switch (elem)
	{
	case '#': return 0;
	case '(': return 1;
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 3;
	}
}

int InfixToPostfix(char infx[])
{
	char  pofx[50], ch, elem;
	int i = 0, k = 0;
	//clrscr();
	 
	push1('#');
	while ((ch = infx[i++]) != '\0')
	{
		if (ch == '(') push1(ch);
		else
			if (isalnum(ch)) pofx[k++] = ch;
			else
				if (ch == ')')
				{
					while (s[top1] != '(')
						pofx[k++] = pop1();
					elem = pop1();
				}
				else
				{
					while (pr(s[top1]) >= pr(ch))
						pofx[k++] = pop1();
					push1(ch);
				}
	}
	while (s[top1] != '#')
		pofx[k++] = pop1();
	pofx[k] = '\0';
	printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n", infx, pofx);
	//getch();
	int result = postfixEval(pofx);
	return result;
}