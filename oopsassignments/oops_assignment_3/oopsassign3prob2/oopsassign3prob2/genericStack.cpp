///*Define a template stack class. Using this template class, create stack objects of int,
//float, char* and complex type. Include exception-handling functionality.*/
//#include <iostream>
//#include<string>
//using namespace std;
//#define MAX_SIZE 9
////complex class declaration
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
//	T stackHolder[MAX_SIZE]; 
//	int top;
//	bool overflow;
//	bool underflow;
//	
//public:
//
//	class full{};  // for handling "stack is full " case
//	class empty{};  // for handling "stack is empty " case
//	Stack() {
//		top = -1;
//		 
//	}
//	~Stack() //destructor
//	{
//		 
//	}
//	// isEmpty checks whether stck is empty or not
//	bool isEmpty() {
//		 
//			if (top < 0) {
//				 
//				return true;
//			}
//			return false;
//		
//		 
//	}
//	// isEmpty checks whether stck is full or not
//	bool isFull() {
//		
//			if (top >= (MAX_SIZE - 1)) {
//				 
//				return true;
//			}
//			 
//		return false;
//	}
//	//for printing the elements in the stack
//	void printStack() 
//	{
//		if (top >= 0)
//		{
//			for (int index = top; index >= 0; index--)
//			{
//				if (index > 0) 
//				{
//					cout << stackHolder[index] << ", ";
//				}
//				else 
//				{
//					cout << stackHolder[index];
//				}
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
//	{
//		
//		if (!isFull())
//		{
//			
//			top++;
//			stackHolder[top] = data;
//		}
//		
//	}
//	// push function deletes the element at top of the stack
//	
//	T pop()
//	{
//		cout << "in pop" << endl;
//		T value;
//		if (!isEmpty())
//		{
//			value = stackHolder[top];
//			top--;
//			return value;
//		}
//		else
//		{
//			throw empty();
//		}
//		
//	}
//	// peek returns the value resent at the top of the stack
//	T peek()
//	{
//		T value;
//		if (!isEmpty())
//		{
//			value = stackHolder[top];
//			return value;
//		}
//		else
//		{
//			throw empty();
//		}
//		return value;
//	}
//
//
//}; //end of stack class
//
//int main()
//{
//	
//	char choice[10]="";
//	while (*choice != '5')
//	{
//		std::cout << "choose any of the following" << endl;
//		std::cout << "1.integers stack" << endl;
//		std::cout << "2.float stack" << endl;
//		std::cout << "3. strings stack" << endl;
//		std::cout << "4. complex number stack" << endl;
//		std::cout << "5.exit" << endl;
//		std::cout << "enter your choice" << endl;
//		cin >> choice;
//		if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0|| strcmp("4", choice) == 0|| strcmp("5", choice) == 0)
//		{
//			if (*choice != '5')
//			{
//				switch (*choice)
//				{
//				case '1':
//				{
//
//					cout << "***** Stack using template *****" << endl;
//
//					cout << "*** Integer Type Stack***" << endl;
//					int element;
//					Stack<int> st; // declaring int type stack
//					strcpy_s(choice, 10, "");
//					while (*choice != '7')
//					{
//						cout << endl;
//						cout << "choose the options from below" << endl;
//						cout << "1.push the element" << endl;
//						cout << "2.pop the element" << endl;
//						cout << "3.know the top element" << endl;
//						cout << "4.know whether stack is full" << endl;
//						cout << "5.know wheather stack is empty" << endl;
//						cout << "6.display the elemnets of the stack" << endl;
//						cout << "7.exit from loop";
//						cout << endl;
//						cout << "ENTER YOUR CHOICE";
//						cin >> choice;
//
//						if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0 || strcmp("4", choice) == 0 || strcmp("5", choice) == 0 || strcmp("6", choice) == 0 || strcmp("7", choice) == 0)
//						{
//							if (*choice != '7')
//							{
//								
//								switch (*choice)
//								{
//									
//								case '1':
//									// case 1 handles the integer type stack
//									try
//									{
//										cout << "enter the element you want to insert" << endl;
//										cin >> element;
//										while (std::cin.fail())
//										{
//											cout << "error" << endl;
//											cout << "please enter a valid input" << endl;
//											cin.clear();
//											cin.ignore(256, '\n');
//											cin >> element;
//										}
//										if (!st.isFull()) {
//											cout << "push:" << element << "\t\t";
//											st.push(element);
//										}
//
//									}
//
//									catch (Stack<int>::full)
//									{
//										cout << "stack is full" << endl;
//									}
//									break;
//								case '2':
//									try
//									{
//										cout << st.pop();
//
//									}
//									catch (Stack<int>::empty)
//									{
//										cout << "stack is empty" << endl;
//									}
//									break;
//								case '3':
//									try
//									{
//										if (!st.isEmpty())
//										{
//											cout << "the elemnet at the top of the stack is" << st.peek() << endl;
//										}
//
//									}
//									catch (Stack<int>::empty)
//									{
//										cout << "stack is empty" << endl;
//									}
//									break;
//								case '4':
//									if (!st.isFull())
//										cout << "the stcak is not full" << endl;
//									else
//									{
//										cout << "stack is full" << endl;
//									}
//									break;
//								case '5':
//									if (!st.isEmpty())
//										cout << "the stack is not Empty" << endl;
//									else
//									{
//										cout << "stack is empty" << endl;
//									}
//									break;
//								case '6':
//									st.printStack();
//									break;
//								default:
//									break;
//								}
//							}
//							else
//							{
//								break;
//							}
//						}
//						else
//						{
//							cout << "enter a valid choice" << endl;
//						}
//					}
//					
//					break;
//				}
//				case '2':
//				{
//
//					cout << "***** Stack using template *****" << endl;
//
//					cout << "*** float Type Stack***" << endl;
//					float element;
//					Stack<float> st; // float type stack
//					strcpy_s(choice, 10, "");
//					while (*choice != '7')
//					{
//						cout << "choose the options from below" << endl;
//						cout << "1.push the element" << endl;
//						cout << "2.pop the element" << endl;
//						cout << "3.know the top element" << endl;
//						cout << "4.know whether stack is full" << endl;
//						cout << "5.know wheather stack is empty" << endl;
//						cout << "6.display the elemnets of the stack" << endl;
//						cout << "7.exit from loop";
//						cout << endl;
//						cout << "ENTER YOUR CHOICE";
//						cin >> choice;
//
//						if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0 || strcmp("4", choice) == 0 || strcmp("5", choice) == 0 || strcmp("6", choice) == 0 || strcmp("7", choice) == 0)
//						{
//							if (*choice != '7')
//							{
//
//								switch (*choice)
//								{
//								case '1':
//									try
//									{
//										cout << "enter the element you want to insert" << endl;
//										cin >> element;
//										while (std::cin.fail())
//										{
//											cout << "error" << endl;
//											cout << "please enter a valid input" << endl;
//											cin.clear();
//											cin.ignore(256, '\n');
//											cin >> element;
//										}
//										if (!st.isFull()) {
//											cout << "push:" << element << "\t\t";
//											st.push(element);
//										}
//
//									}
//
//									catch (Stack<int>::full)
//									{
//										cout << "stack is full" << endl;
//									}
//									break;
//								case '2':
//									try
//									{
//										cout << st.pop();
//
//									}
//									catch (Stack<int>::empty)
//									{
//										cout << "stack is empty" << endl;
//									}
//									break;
//								case '3':
//									try
//									{
//										if (!st.isEmpty())
//										{
//											cout << "the elemnet at the top of the stack is" << st.peek() << endl;
//										}
//
//									}
//									catch (Stack<int>::empty)
//									{
//										cout << "stack is empty" << endl;
//									}
//									break;
//								case '4':
//									if (!st.isFull())
//										cout << "the stcak is not full" << endl;
//									else
//									{
//										cout << "stack is full" << endl;
//									}
//									break;
//								case '5':
//									if (!st.isEmpty())
//										cout << "the stack is not Empty" << endl;
//									else
//									{
//										cout << "stack is empty" << endl;
//									}
//									break;
//								case '6':
//									st.printStack();
//									break;
//								default:
//									break;
//								}
//							}
//							else
//							{
//								break;
//							}
//						}
//						else
//						{
//							cout << "enter a valid choice" << endl;
//						}
//					}
//
//					break;
//				}
//
//				case '3':
//				{
//					// handles string type stack
//					cout << "\n*** String Type Stack***" << endl;
//					Stack<string> st; // string type stack declaration
//					cout << "***** Stack using template *****" << endl;
//
//					
//					char element[50];
//					 
//					strcpy_s(choice, 10, "");
//					while (*choice != '7')
//					{
//						cout << "choose the options from below" << endl;
//						cout << "1.push the element" << endl;
//						cout << "2.pop the element" << endl;
//						cout << "3.know the top element" << endl;
//						cout << "4.know whether stack is full" << endl;
//						cout << "5.know wheather stack is empty" << endl;
//						cout << "6.display the elemnets of the stack" << endl;
//						cout << "7.exit from loop";
//						cout << endl;
//						cout << "ENTER YOUR CHOICE";
//						cin >> choice;
//
//						if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0 || strcmp("4", choice) == 0 || strcmp("5", choice) == 0 || strcmp("6", choice) == 0 || strcmp("7", choice) == 0)
//						{
//							if (*choice != '7')
//							{
//
//								switch (*choice)
//								{
//								case '1':
//									try
//									{
//										cout << "enter the element you want to insert" << endl;
//										cin >> element;
//										while (std::cin.fail())
//										{
//											cout << "error" << endl;
//											cout << "please enter a valid input" << endl;
//											cin.clear();
//											cin.ignore(256, '\n');
//											cin >> element;
//										}
//										if (!st.isFull()) {
//											cout << "push:" << element << "\t\t";
//											st.push(element);
//										}
//
//									}
//
//									catch (Stack<int>::full)
//									{
//										cout << "stack is full" << endl;
//									}
//									break;
//								case '2':
//									try
//									{
//										cout << st.pop();
//
//									}
//									catch (Stack<int>::empty)
//									{
//										cout << "stack is empty" << endl;
//									}
//									 
//									break;
//								case '3':
//									try
//									{
//										if (!st.isEmpty())
//										{
//											cout << "the elemnet at the top of the stack is" << st.peek() << endl;
//										}
//
//									}
//									catch (Stack<int>::empty)
//									{
//										cout << "stack is empty" << endl;
//									}
//									break;
//								case '4':
//									if (!st.isFull())
//										cout << "the stcak is not full" << endl;
//									else
//									{
//										cout << "stack is full" << endl;
//									}
//									break;
//								case '5':
//									if (!st.isEmpty())
//										cout << "the stack is not Empty" << endl;
//									else
//									{
//										cout << "stack is empty" << endl;
//									}
//									break;
//								case '6':
//									st.printStack();
//									break;
//								default:
//									break;
//								}
//							}
//							else
//							{
//								break;
//							}
//						}
//						else
//						{
//							cout << "enter a valid choice" << endl;
//						}
//					}
//
//
//					 
//
//					break;
//				}
//				case '4':
//				{
//					// handles complex type stack 
//					cout << "\n*** complex Type Stack***" << endl;
//					Stack<Complex> st;
//					cout << "***** Stack using template *****" << endl;
//
//					
//					Complex element;
//
//					strcpy_s(choice, 10, "");
//					while (*choice != '7')
//					{
//						cout << "choose the options from below" << endl;
//						cout << "1.push the element" << endl;
//						cout << "2.pop the element" << endl;
//						cout << "3.know the top element" << endl;
//						cout << "4.know whether stack is full" << endl;
//						cout << "5.know wheather stack is empty" << endl;
//						cout << "6.display the elemnets of the stack" << endl;
//						cout << "7.exit from loop";
//						cout << endl;
//						cout << "ENTER YOUR CHOICE";
//						cin >> choice;
//
//						if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0 || strcmp("4", choice) == 0 || strcmp("5", choice) == 0 || strcmp("6", choice) == 0 || strcmp("7", choice) == 0)
//						{
//							if (*choice != '7')
//							{
//
//								switch (*choice)
//								{
//								case '1':
//									try
//									{
//										cout << "enter the element you want to insert" << endl;
//										cin >> element;
//										while (std::cin.fail())
//										{
//											cout << "error" << endl;
//											cout << "please enter a valid input" << endl;
//											cin.clear();
//											cin.ignore(256, '\n');
//											cin >> element;
//										}
//										if (!st.isFull()) {
//											cout << "push:" << element << "\t\t";
//											st.push(element);
//										}
//
//									}
//
//									catch (Stack<Complex>::full) // catches the exception if the stack is full
//									{
//										cout << "stack is full" << endl;
//									}
//									break;
//								case '2':
//									try
//									{
//										cout << st.pop();
//
//									}
//									catch (Stack<Complex>::empty)  // catches the exception if the stack is empty
//									{
//										cout << "stack is empty" << endl;
//									}
//									break;
//								case '3':
//									try
//									{
//										if (!st.isEmpty())
//										{
//											cout << "the elemnet at the top of the stack is" << st.peek() << endl;
//										}
//
//									}
//									catch (Stack<Complex>::empty) // catches the exception if the stack is empty
//									{
//										cout << "stack is empty" << endl;
//									}
//									break;
//								case '4':
//									if (!st.isFull())
//										cout << "the stcak is not full" << endl;
//									else
//									{
//										cout << "stack is full" << endl;
//									}
//									break;
//								case '5':
//									if (!st.isEmpty())
//										cout << "the stack is not Empty" << endl;
//									else
//									{
//										cout << "stack is empty" << endl;
//									}
//									break;
//								case '6':
//									st.printStack();
//									break;
//								default:
//									break;
//								}
//							}
//							else
//							{
//								break;
//							}
//						}
//						else
//						{
//							cout << "enter a valid choice" << endl;
//						}
//					}
//					break;
//				}
//
//				default:
//				{
//					break;
//				}
//				}
//			}
//			else
//			{
//				return -1;
//			}
//
//		}
//		else
//		{
//			cout << "please enter a valid choice" << endl;
//		}
//	}
//
//
//
//	
//
//	system("pause");
//	return 0;
//}