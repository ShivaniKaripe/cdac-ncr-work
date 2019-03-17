//#include<iostream>
//#include<conio.h>
//#include<process.h>
//using namespace std;
//template<class t>
//class stack
//{
//	t a[5]; int top;
//public:
//	stack()
//	{
//		top = -1;
//	}
//	void push();
//	void pop();
//	void display();
//};
//template<class t>
//void stack<t>::push()
//{
//	try
//	{
//		if (top == 4)
//			throw top;
//		else
//		{
//			cout << "enter element to push" << endl;
//			int x;
//			cin >> x;
//			a[++top] = x;
//		}
//	}
//	catch (int a)
//	{
//		cout << "exception caught:OVERFLOW:Top=" << a << endl;
//	}
//}
//template<class t>
//void stack<t>::pop()
//{
//	try
//	{
//		if (top == -1)
//			throw top;
//		else
//		{
//			cout << "element  is popped out from stack:" << a[top] << endl;
//			top--;
//		}
//	}
//	catch (int x)
//	{
//		cout << "exception caught:UNDERFLOW" << endl;
//	}
//}
//template<class t>
//void stack<t>::display()
//{
//
//	cout << "elements in stack are:" << endl;
//	try
//	{
//		if (top == -1)
//			throw top;
//		else
//		{
//			for (int i = top; i >= 0; i--)
//			{
//				cout << "[" << a[i] << "]" << endl;
//			}
//		}
//	}
//	catch (int x)
//	{
//		cout << "exception caught:THERE ARE NO ELEMENTS IN STACK" << endl;
//	}
//}
//int main()
//{
//	stack<float> s;
//	while (1)
//	{
//		cout << "stack using class templates and exception handling" << endl;
//		cout << "1:push\n2:pop\n3:display\n4:exit\nEnter your choice" << endl;
//		int choice;
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			s.push(); break;
//		case 2:
//			s.pop(); break;
//		case 3:
//			s.display(); break;
//		case 4:
//			exit(0);
//		default:
//			cout << "enter correct choice" << endl;
//
//		}
//	}
//	return 0;
//	system("pause");
//}
