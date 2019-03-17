//evaluation of infix to postfix
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define SIZE 50
char s[SIZE];
int top1 = -1;
//declaration of function "postfixEval"
int postfixEval(char *);
//"push" adds the element to the list
push1(char elem)
{
	s[++top1] = elem;
}
//"pop" removes the element then returns the value 
char pop1()
{
	return(s[top1--]);
}
//"pr" retuns the precedence value
int pr(char elem)
{
	switch (elem)
	{
		//"#" has the hieghest precedence as it indicates the end of the stack
	case '#': return 0;
		//'(' has the next hiehhest precedence
	case '(': return 1;
		//for '+' and '-' same precedence value
	case '+':
	case '-': return 2;
		//for '*' and '/' same precedence value
	case '*':
	case '/': return 3;
	}
}
//this function converts infix expression to postfix
int InfixToPostfix(char infx[])
{

	char  pofx[50], ch, elem;
	int i = 0, k = 0;
	//clrscr();
	//loop is repeated until null terminating character encountered 
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
		//loop stops when the end of the stack is reached
		pofx[k++] = pop1();
	pofx[k] = '\0';
	 
	//postfixEval evaluates the postfix expression
	int result = postfixEval(pofx);
	//retuns the result of the expression
	return result;
}