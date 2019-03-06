/* This program converts infix expression to postfix expression.
 * This program assume that there are Five operators: (*, /, +, -,^)
	in infix expression and operands can be of single-digit only.
 * This program will not work for fractional numbers.
 * Further this program does not check whether infix expression is
 valid or not in terms of number of operators and operands.*/

#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>

#define SIZE 100


 /* declared here as global variable because stack[]
 * is used by more than one fucntions */
char stack1[SIZE];
int top1 = -1;

/* define push operation */

void push1(char item)
{
	if (top1 >= SIZE - 1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top1 = top1 + 1;
		stack1[top1] = item;
	}
}

/* define pop operation */
char pop1()
{
	char item;

	if (top1 < 0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		/* underflow may occur for invalid expression */
		/* where ( and ) are not matched */
		exit(1);
	}
	else
	{
		item = stack1[top1];
		top1 = top1 - 1;
		return(item);
	}
}

/* define function that is used to determine whether any symbol is operator or not
(that is symbol is operand)
* this fucntion returns 1 if symbol is opreator else return 0 */

int is_operator(char symbol)
{
	if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* define fucntion that is used to assign precendence to operator.
* Here ^ denotes exponent operator.
* In this fucntion we assume that higher integer value
* means higher precendence */

int precedence(char symbol)
{
	if (symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if (symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if (symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

char* InfixToPostfix(char infix_exp[])
{
	char postfix_exp[100];
	int i, j;
	char item;
	char x;

	push('(');                               /* push '(' onto stack */
	strcat_s(infix_exp,sizeof(infix_exp), ")");                  /* add ')' to infix expression */

	i = 0;
	j = 0;
	item = infix_exp[i];         /* initialize before loop*/

	while (item != '\0')        /* run loop till end of infix expression */
	{
		if (item == '(')
		{
			push1(item);
		}
		else if (isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              /* add operand symbol to postfix expr */
			j++;
		}
		else if (is_operator(item) == 1)        /* means symbol is operator */
		{
			x = pop1();
			while (is_operator(x) == 1 && precedence(x) >= precedence(item))
			{
				postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = pop1();                       /* add them to postfix expresion */
			}
			push1(x);
			/* because just above while loop will terminate we have
			oppped one extra item
			for which condition fails and loop terminates, so that one*/

			push1(item);                 /* push current oprerator symbol onto stack */
		}
		else if (item == ')')         /* if current symbol is ')' then */
		{
			x = pop1();                   /* pop and keep popping until */
			while (x != '(')                /* '(' encounterd */
			{
				postfix_exp[j] = x;
				j++;
				x = pop1();
			}
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; /* go to next symbol of infix expression */
	} /* while loop ends here */
	if (top1 > 0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}
	if (top1 > 0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */
	return postfix_exp;
}

/* main function begins */
 