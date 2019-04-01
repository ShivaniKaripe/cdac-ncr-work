#include<iostream>
#include<exception>
#include<string>
using namespace std;
class Complex
	{
		int real;
		int img;
	public:
		Complex()//default constructor
		{
			real = img = 0;
	
		}
		Complex(int tempReal, int tempImg) //parameterized constructor
		{
			real = tempReal;
			img = tempImg;
		}
		Complex(const Complex &c) //copy constructor
		{
			real = c.real;
			img = c.img;
		}
		~Complex()//destructor
		{
	
		}
		friend istream& operator>> (istream &cin, Complex &c); // declaration of cin overloading function
		friend ostream& operator<<(ostream& cout, Complex c);  //declaration of cout overloading function
	
	
	};
	// operator >> overloading function
	istream& operator >> (istream &cin, Complex &c)
	{
		std::cout << "enter the real part of the complex number" << endl;
		cin >> c.real;
		std::cout << "enter the imaginary part of the complex number" << endl;
		cin >> c.img;
		return cin;
	}
	// operator << overloading function
	ostream& operator<<(ostream& cout, Complex c)
	{
		cout << c.real << "+  " << c.img << "i";
		return cout;
	}
	
class Empty:public exception
{
public:
		const char* what() const noexcept override
		{
			return "stack is empty";
		}
};
class  Full:public exception
{
public:
	const char* what() const noexcept override
	{
		return "stack is full";
	}
 };
template<class T>
 class Stack
{
	 int top;
	 T stackHolder[5];
public:
	Stack()
	{
		top = -1;
	}
	void push(T element)
	{
		 
		if (top == 4)
		{
			throw Full();
		}
 		stackHolder[++top] = element;
	}
	T pop()
	{
		T element;
		if (top == -1)
		{
			throw Empty();
		}
		element = stackHolder[top];
		top--;
		return element;
	}
	T peek()
	{
		T element;
		if (top == -1)
		{
			throw Empty();
		}
		element = stackHolder[top];
		return element;
	}
	void printStack()
			{
				if (top >= 0)
				{
					for (int index = top; index >= 0; index--)
					{
						 cout << stackHolder[index];
					}
					cout << endl;
				}
				else 
				{
					cout << "stack empty" << endl;
				}
		
			}
			
  };
 void stackOperations(int choice)
 {
	 int intElement = 0;
	 float floatElement = 0;
	 string stringElement = "";
	 Complex complexElement;
	 int option = 0;
	 while (true)
	 {
		cout << "choose the options from below" << endl;
		cout << "1.push the element" << endl;
		cout << "2.pop the element" << endl;
		cout << "3.know the top element" << endl;
		cout << "4.display the elemnets of the stack" << endl;
		cout << "5.exit from loop";
		cout << endl;
		cout << "ENTER YOUR CHOICE";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "enter the element to be pushed";
			if (choice == 1)
			{
				cin >> intElement;
			}
			else if (choice == 2)
			{
				cin >> floatElement;
			}
			else if (choice == 3)
			{
				std::cin >> stringElement;
			}
			else if (choice == 4)
			{
				cin >> complexElement;
			}


		default:
			break;
		}
	 }
 }
 int main()
 {
	 int choice = 0;
	 while (true)
	 {
				std::cout << "choose any of the following" << endl;
		 		std::cout << "1.integers stack" << endl;
		 		std::cout << "2.float stack" << endl;
		 		std::cout << "3. strings stack" << endl;
		 		std::cout << "4. complex number stack" << endl;
		 		std::cout << "5.exit" << endl;
		 		std::cout << "enter your choice" << endl;
		 		cin >> choice;
				stackOperations(choice);
	 }
	 system("pause");
 }