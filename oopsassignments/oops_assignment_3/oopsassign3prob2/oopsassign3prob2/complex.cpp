//#include<iostream>
//#define MAX_SIZE 9
//using namespace std;
////class Complex
////{
////	int real;
////	int img;
////public:
////	Complex()
////	{
////		real = img = 0;
////
////	}
////	Complex(int r, int i)
////	{
////		real = r;
////		img = i;
////	}
////	Complex(const Complex &c)
////	{
////		real = c.real;
////		img = c.img;
////	}
////	~Complex()
////	{
////
////	} 
////	friend istream& operator>> (istream &cin, Complex &c);
////	friend ostream& operator<<(ostream& cout, Complex c);
////
////
////};
////istream& operator >> (istream &cin, Complex &c)
////{
////	std::cout << "enter the real part of the complex number" << endl;
////	cin >> c.real;
////	std::cout << "enter the imaginary part of the complex number" << endl;
////	cin >> c.img;
////	return cin;
////}
////ostream& operator<<(ostream& cout, Complex c)
////{
////	cout << c.real << "+  " << c.img << "i";
////	return cout;
////}
//
////template <class Complex>
//class Stack {
//private:
//	Complex stackHolder[MAX_SIZE];
//	int top;
//	bool overflow;
//	bool underflow;
//
//public:
//	class full {};
//	class empty {};
//	Stack() {
//		top = -1;
//		overflow = false;
//		underflow = true;
//	}
//	~Stack() {
//		cout << "\nIn Destructor" << endl;
//	}
//	bool isEmpty() {
//
//		if (top < 0) {
//
//			throw empty();
//		}
//		return false;
//
//		return underflow;
//	}
//	bool isFull() {
//
//		if (top >= (MAX_SIZE - 1)) {
//
//			throw full();
//		}
//
//		return false;
//	}
//	void printStack() {
//		if (top != MAX_SIZE) {
//			for (int index = top; index >= 0; index--) {
//				if (index > 0) {
//					cout << stackHolder[index] << ", ";
//				}
//				else {
//					cout << stackHolder[index];
//				}
//			}
//			cout << endl;
//		}
//		else {
//			cout << "stack empty" << endl;
//		}
//
//	}
//	void push(Complex data) {
//
//		if (!isFull())
//		{
//
//			top++;
//			stackHolder[top] = data;
//		}
//
//	}
//	Complex pop() {
//		cout << "in pop" << endl;
//		Complex value;
//		if (!isEmpty()) {
//			value = stackHolder[top];
//			top--;
//		}
//		return value;
//	}
//	Complex peek() {
//		Complex value;
//		if (!isEmpty()) {
//			value = stackHolder[top];
//		}
//		return value;
//	}
//
//
//};
//int main()
//{
//	cout << "***** Stack using template *****" << endl;
//
//	cout << "*** Integer Type Stack***" << endl;
//	char choice[10];
//	Complex element;
//	Stack st;
//	strcpy_s(choice, 10, "");
//	while (*choice != '7')
//	{
//		cout << "choose the options from below" << endl;
//		cout << "1.push the element" << endl;
//		cout << "2.pop the element" << endl;
//		cout << "3.know the top element" << endl;
//		cout << "4.know whether stack is full" << endl;
//		cout << "5.know wheather stack is empty" << endl;
//		cout << "6.display the elemnets of the stack" << endl;
//		cout << "7.exit from loop";
//		cout << endl;
//		cout << "ENTER YOUR CHOICE";
//		cin >> choice;
//
//		if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0 || strcmp("4", choice) == 0 || strcmp("5", choice) == 0 || strcmp("6", choice) == 0 || strcmp("7", choice) == 0)
//		{
//			if (*choice != '7')
//			{
//
//				switch (*choice)
//				{
//				case '1':
//					try
//					{
//						cout << "enter the element you want to insert" << endl;
//						cin >> element;
//						if (!st.isFull()) {
//							cout << "push:" << element << "\t\t";
//							st.push(element);
//						}
//
//					}
//
//					catch (Stack::full)
//					{
//						cout << "stack is full" << endl;
//					}
//					break;
//				case '2':
//					try
//					{
//						cout << st.pop();
//
//					}
//					catch (Stack::empty)
//					{
//						cout << "stack is empty" << endl;
//					}
//					break;
//				case '3':
//					try
//					{
//						if (!st.isEmpty())
//						{
//							cout << "the elemnet at the top of the stack is" << st.peek() << endl;
//						}
//
//					}
//					catch (Stack::empty)
//					{
//						cout << "stack is empty" << endl;
//					}
//					break;
//				case '4':
//					if (!st.isFull())
//						cout << "the stcak is not full" << endl;
//					else
//					{
//						cout << "stack is full" << endl;
//					}
//					break;
//				case '5':
//					if (!st.isEmpty())
//						cout << "the stack is not Empty" << endl;
//					else
//					{
//						cout << "stack is empty" << endl;
//					}
//					break;
//				case '6':
//					st.printStack();
//					break;
//				default:
//					break;
//				}
//			}
//			else
//			{
//				break;
//			}
//		}
//		else
//		{
//			cout << "enter a valid choice" << endl;
//		}
//	}
//	system("pause");
//}
//			 