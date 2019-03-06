
/*infix to postfix evaluation using stack*/
 
#include<iostream>
#include<string.h>
using namespace std;
class Stack
{
	char sta[30];
	int top;
public:
	Stack()
	{
		top = -1;
	 }
	void push(char);
	char pop();
	char peek();
	bool isEmpty();
	bool isFull();

};
bool Stack::isEmpty()
{
	return(top = -1);
}
bool Stack::isFull()
{
	return(top == 29);
}
void Stack :: push(char x)
{
	if (!isFull())
	{
		sta[++top] = x;
	}
	else
	{
		cout << "stack is full";
	}
}
char Stack::pop()
{
	char x=' ';
	if (!isEmpty())
		x = sta[top--];
	else
		cout << "stack is empty";
	return x;
}
char Stack::peek()
{
	char x = ' ';
	if (!isEmpty())
		x =  sta[top];
	else
		cout << "stack is empty";
	return x;
}
int precedence(char ch)
{
	if (ch == '{')
		return 1;
	else if (ch == '[')
		return 2;
	else if (ch == '(')
		return 3;
	else if (ch == '-')
		return 4;
	else if (ch == '+')
		return 5;
	else if (ch == '%')
		return 6;
	else if (ch == '/')
		return 7;
	else if (ch == '*')
		return 8;
	else if (ch == '^')
		return 9;
	else
		return -1;
}
int main()
{
	Stack st; 
	 
	
	char ipstr[50];
	char opstr[50];
	cout << "enter the infix notation for which you want findout the postfix notation";
	cin >> ipstr;
	int l = strlen(ipstr);
	int j = -1;
	for (int i = 0; i < l; i++)
	{
		if (((ipstr[i] >= 'a') && (ipstr[i] <= 'z')) || ((ipstr[i] >= 'A') && (ipstr[i] <= 'Z')) )
			opstr[++j]= ipstr[i];

		else if (st.isEmpty())
		{
			st.push(ipstr[i]);
		}
		else if (ipstr[i] == ')')
		{
			while (st.peek() != '(')
			{
				opstr[++j] = st.pop();

			}
			st.pop();
		}
		else if (ipstr[i] == ']')
		{
			while (st.peek() != '[')
			{
				opstr[++j] = st.pop();
			}
			st.pop();
		}
		else if (ipstr[i] == '}')
		{
			while (ipstr[i] != '{')
			{
				opstr[++j] = st.pop();
			}
			st.pop();
		}
		 
		else if(precedence(ipstr[i])<=precedence(st.peek())
			{
		while ( (precedence(ipstr[i]) <= precedence(st.peek())))
				opstr[++j] = st.pop();
			push(ipstr[i]);
			}
			}
		else
			push(ipstr[i]);
	 while(!st.isEmpty())
	{
		 opstr[++j] = st.pop();
	}

	 cout << "output  is" << opstr;


		


}
