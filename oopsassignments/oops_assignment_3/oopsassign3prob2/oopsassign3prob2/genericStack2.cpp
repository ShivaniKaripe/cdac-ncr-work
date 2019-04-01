///*Define a template stack class. Using this template class, create stack objects of int,
//float, char* and complex type. Include exception-handling functionality.*/
//#include <iostream>
//#include<string>
//#include<exception>
//
//using namespace std;
//constexpr auto MAX_SIZE = 5 ;
//class Empty : public exception
//{
//public:
//	const char* what() const noexcept override
//	{
//		return "stack is empty";
//	}
//};
//
//class Full : public exception
//{
//public:
//	const char* what() const noexcept override
//	{
//		return "stack is full";
//	}
//};
////complex class declaration
//
//class Complex
//{
//	int real;
//	int img;
//public:
//	Complex()//default constructor
//	{
//		real = img = 0;
//
//	}
//	Complex(int tempReal, int tempImg) //parameterized constructor
//	{
//		real = tempReal;
//		img = tempImg;
//	}
//	Complex(const Complex &c) //copy constructor
//	{
//		real = c.real;
//		img = c.img;
//	}
//	~Complex()//destructor
//	{
//
//	}
//	friend istream& operator>> (istream &cin, Complex &c); // declaration of cin overloading function
//	friend ostream& operator<<(ostream& cout, Complex c);  //declaration of cout overloading function
//
//
//};
//// operator >> overloading function
//istream& operator >> (istream &cin, Complex &c)
//{
//	std::cout << "enter the real part of the complex number" << endl;
//	cin >> c.real;
//	std::cout << "enter the imaginary part of the complex number" << endl;
//	cin >> c.img;
//	return cin;
//}
//// operator << overloading function
//ostream& operator<<(ostream& cout, Complex c)
//{
//	cout << c.real << "+  " << c.img << "i";
//	return cout;
//}
//// class template declaration
//template <class T>
//// stack class declaration
//class Stack {
//private:
//	T stackHolder[5]; 
//	int top;
//	bool overflow;
//	bool underflow;
//	
//public:
//
//	 Stack() {
//		top = -1;
//		 
//	}
//	~Stack() //destructor
//	{
//		 
//	}
//	 
//	//for printing the elements in the stack
//	void printStack() 
//	{
//		if (top >= 0)
//		{
//			for (int index = top; index >= 0; index--)
//			{
//				 
//				cout << stackHolder[index] << endl;;
//				
//			}
//			cout << endl;
//		}
//		else 
//		{
//			cout << "stack empty" << endl;
//		}
//
//	}
//	// push function inserts the element at top of the stack
//	// takes the element that has to inserted as an argument
//	void push(T data)
//			{
//				
//		if (top < 5)
//		{
//
//			top++;
//			stackHolder[top] = data;
//		}
//		else
//			throw Full();
//		
//				
//			}
//			// push function deletes the element at top of the stack
//			
//			T pop()
//			{
//				cout << "in pop" << endl;
//				T value;
//				if (top>-1)
//				{
//					value = stackHolder[top];
//					top--;
//					return value;
//				}
//				else
//				{
//					throw Empty();
//				}
//				return value;
//			}
//			
//	/*void push(T data) 
//	{
//		//cout << "in push"<<endl;
//		cout << "push "<<data<<endl;
//		cout << "top   :   " << top << endl;
//		if (top == 5)
//		{
//			throw Full();
//		}
//			
//			stackHolder[++top] = data;
//			cout << "stack holder" << stackHolder[top] << endl;
//	}
//	// push function deletes the element at top of the stack
//	
//	T pop()
//	{
//		cout << "in pop" << endl;
//		if (top == -1)
//		{
//			throw Empty();
//		}
//		cout <<"top   :   "<< top<<endl;
//		cout << "stackHolder[top--]" << stackHolder[top--] << endl;
//		return stackHolder[top--];
//		
//	}*/
//	// peek returns the value resent at the top of the stack
//	T peek()
//	{
//		if (top == -1)
//		{
//			throw Empty();
//		}
//		cout << top;
//		return stackHolder[top--];
//	}
//
//
//}; //end of stack class
//
//int main()
//{
//
//	
//	Stack<int> st;
//	try
//	{
//		st.push(10);
//		st.push(20);
//		st.push(30);
//		st.push(40);
//		st.push(50);
//		st.push(60);
//		st.push(70);
//	}
//	catch (std::exception& ex)
//	{
//		std::cerr << ex.what();
//	}
//	try
//	{
//		cout << "1"  << st.pop()<<endl;
//		cout << "2" << st.pop() << endl;
//		cout << "3" << st.pop() << endl;
//		cout << "4" << st.pop() << endl;
//		cout << "5" << st.pop() << endl;
//		cout << "6" << st.pop() << endl;
//	}
//	catch (std::exception& ex)
//	{
//		std::cerr << ex.what();
//	}
//	system("pause");
//	return 0;
//}