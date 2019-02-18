#include<iostream>
using namespace std;
struct _stack_
{
	int top;
	int *ptr;
	int size;
};
class Stack
{
	struct  _stack_ sta;
public:
	Stack();
	void push(int);
	int pop();
	int peek();
	bool isEmpty();
	bool isFull();
	void get_size(int );
	void display();
	~Stack()
	{
		
	}
};
Stack::Stack()
{
	sta.ptr = NULL;
	sta.top = -1;
	sta.size = 0;
}
void Stack::get_size(int x)
{
	sta.size = x;
	sta.ptr = new int[x];

}
bool Stack::isEmpty()
{
	return((sta.top == (-1)));
}
bool Stack::isFull()
{
	return(sta.top == (sta.size - 1));
}
void Stack::push(int x)
{
	if (!(sta.top == (sta.size - 1)))
	{
		sta.ptr[++sta.top] = x;
	}
	else
	{
		cout << "stack is full"<<endl;
	}
}
int Stack::pop()
{
	int x = -999;
	if (!(sta.top == -1))
	{
		x = sta.ptr[sta.top--];

	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;
}
int Stack::peek()
{
	int x = -999;
	if (!isEmpty())
	{
		x = sta.ptr[sta.top];

	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;
}
void Stack::display()
{
	if (!(sta.top == -1))
	{
		cout << "the elements of the stack are" << endl;
		for (int i = 0; i <= sta.top; i++)
		{
			cout << sta.ptr[i];
		}
	}
	else
	{
		cout << "the stack is empty";
	}
}
int main()
{
	int choice = 0;
	int size=0;
	int x;
	Stack st;
	cout << "enter the size of the stack" << endl;
	cin >> size;
	st.get_size(size);
	cout << "choose the options from below"<<endl;
	cout << "1.push the element" << endl;
	cout << "2.pop the element" << endl;
	cout << "3.know the top element" << endl;
	cout << "4.know whether stack is full" << endl;
	cout << "5.know wheather stack is empty" << endl;
	cout << "6.display the elemnets of the stack" << endl;
	
	do
	{
		cout << endl;
		cout << "ENTER YOUR CHOICE";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "enter the element you want to insert" << endl;
			cin >> x;
			st.push(x);
			break;
		case 2:
			cout << "the elemnet deleted is" << endl;
			x = st.pop();
			if (x != -999)
				cout << x<<endl;
			break;
		case 3:
			cout << "the elemnet at the top of the stack  is" << endl;
			x = st.peek();
			if (x != -999)
				cout << x << endl;;
			break;
		case 4:
			if (!st.isFull())
				cout << "the stcak is not full" << endl;
			else
			{
				cout << "stack is full" << endl;
			}
			break;
		case 5:
			if (!st.isEmpty())
				cout << "the stack is not Empty" << endl;
			else
			{
				cout << "stack is empty" << endl;
			}
			break;
		case 6:
			st.display();
			break;
		default:
			break;
		}
	} while (choice < 7);
	}

