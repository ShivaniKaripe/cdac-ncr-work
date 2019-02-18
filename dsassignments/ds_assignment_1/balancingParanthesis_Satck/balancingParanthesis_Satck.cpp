#include<iostream>
#include<string.h>
using namespace std;
class Stack
{
	char arr[50];
	int top;
	int size;
public:
	Stack()
	{
		top = -1;
	}
	void push(char x);
	char pop();
	char peek();
	bool isFull();
	bool isEmpty();
	 
};
bool Stack::isFull()
{
	return(top == (size - 1));
}
bool Stack::isEmpty()
{
	return(top == -1);
}
void Stack::push(char x)
{
	if (!isFull())
	{
		arr[++top] = x;
	}
	else
	{
		cout << "stack is full"<<endl;
	}
}
char Stack::pop()
{
	char x = ' ';
	if (!isEmpty())
	{
		x = arr[top--];
	}
	else
	{
		cout << "stack is empty"<<endl;
	}
	return x;
}
char Stack::peek()
{
	char x = ' ';
	if (!isEmpty())
	{
		x = arr[top];
	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;
}

int main()
{
	Stack st;
	char temp[100];
	cout << "enter the expression for which you want to chack whether balace paranthesisis are there or not";
	cin >> temp;
	int len = strlen(temp);
	for (int i = 0; i < len; i++)
	{
		switch (temp[i])
		{
		case '(':
		case '[':
		case '{':
			st.push(temp[i]);
			break;
		case ')':
		case ']':
		case '}':
			if (((temp[i] == ')') && (st.peek() == '(')) || ((temp[i] == ']') && (st.peek() == '[')) || ((temp[i] == '}') && (st.peek() == '{')))
				st.pop();
			break;
		default:
			break;
		}
	}
	if (st.isEmpty())
	{
		cout << "balanced paranthesis are there in the expression" << endl;
	}
	else
	{
		cout << "balanced paranthesis are not there in the expression" << endl;
	}
}