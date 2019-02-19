/*program which evalustes the postfix expression is evaluated*/
#include<iostream>
#include<string.h>
using namespace std;
class Stack
{
	int top;
	int sta[50];
public:
	Stack()
	{
		top = -1;
	}
	void push(char x)
	{
		sta[++top] = x;
	}
	int pop()
	{
		int x;
		if (top != -1)
			x = sta[top--];
		else
			x = -999;
		return x;
	}
	bool isEmpty()
	{
		return(top == -1);
	}
};
int main()
{
	Stack st;
	int pop1, pop2;
	int result = 0;
	char str[50];
	cout << "enter the postfix expression you wnt to evaluate" << endl;
	cin >> str;
	cout << endl;
	int l = strlen(str);
	for (int i = 0; i < l; i++)
	{
		if (str[i] <= '9'&&str[i] >= '0')
		{
			st.push((int)str[i]-48);
		}
		else
		{
			if (!st.isEmpty())
			{
				pop1 = st.pop();
			}
			else
			{
				cout <<" invalid expression";
				break;
			}
			if (!st.isEmpty())
			{
				pop2 = st.pop();
			}
			else
			{
				cout << "invalid expression";
				break;
			}
			
			
			switch (str[i])
			{
			case '*':
				result = pop2 *pop1;
				break;
			case '+':
				result = pop2 +pop1;
				 
				break;
			case '/':
				result = pop2 /pop1;
				 
				break;
			case '%':

				result = pop2 %pop1;
				break;
			case '-':
				result = pop2 -pop1;
				break;

			default:
				break;
			}
			st.push(result);
		}
	}
	cout << "the result of postfix expression is   " << st.pop();
}