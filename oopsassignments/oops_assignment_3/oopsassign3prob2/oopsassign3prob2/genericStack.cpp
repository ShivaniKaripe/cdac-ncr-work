/*Define a template stack class. Using this template class, create stack objects of int,
float, char* and complex type. Include exception-handling functionality.*/
#include <iostream>
#include<string>
using namespace std;
#define MAX_SIZE 9
template <class T>
class Stack {
private:
	T stackHolder[MAX_SIZE];
	int top;
	bool overflow;
	bool underflow;
	
public:
	class full{};
	class empty{};
	Stack() {
		top = -1;
		overflow = false;
		underflow = true;
	}
	~Stack() {
		cout << "\nIn Destructor" << endl;
	}
	bool isEmpty() {
		 
			if (top < 0) {
				 
				throw empty();
			}
			return false;
		
		return underflow;
	}
	bool isFull() {
		
			if (top >= (MAX_SIZE - 1)) {
				 
				throw full();
			}
			 
		return false;
	}
	void printStack() {
		if (top!=MAX_SIZE) {
			for (int index = top; index >= 0; index--) {
				if (index > 0) {
					cout << stackHolder[index] << ", ";
				}
				else {
					cout << stackHolder[index];
				}
			}
			cout << endl;
		}
		else {
			cout << "stack empty" << endl;
		}

	}
	void push(T data) {
		
		if (!isFull())
		{
			
			top++;
			stackHolder[top] = data;
		}
		
	}
	T pop() {
		cout << "in pop" << endl;
		T value;
		if (!isEmpty()) {
			value = stackHolder[top];
			top--;
		}
		return value;
	}
	T peek() {
		T value;
		if (!isEmpty()) {
			value = stackHolder[top];
		}
		return value;
	}


};

int main()
{
	
	char choice[10]="";
	while (*choice != '3')
	{
		std::cout << "choose any of the following" << endl;
		std::cout << "1.integers stack" << endl;
		std::cout << "2.float stack" << endl;
		std::cout << "3. strings stack" << endl;
		std::cout << "4.exit" << endl;
		std::cout << "enter your choice" << endl;
		cin >> choice;
		if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0|| strcmp("4", choice) == 0)
		{
			if (*choice != '4')
			{
				switch (*choice)
				{
				case '1':
				{

					cout << "***** Stack using template *****" << endl;

					cout << "*** Integer Type Stack***" << endl;
					int element;
					Stack<int> st;
					strcpy_s(choice, 10, "");
					while (*choice != '7')
					{
						cout << "choose the options from below" << endl;
						cout << "1.push the element" << endl;
						cout << "2.pop the element" << endl;
						cout << "3.know the top element" << endl;
						cout << "4.know whether stack is full" << endl;
						cout << "5.know wheather stack is empty" << endl;
						cout << "6.display the elemnets of the stack" << endl;
						cout << "7.exit from loop";
						cout << endl;
						cout << "ENTER YOUR CHOICE";
						cin >> choice;

						if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0 || strcmp("4", choice) == 0 || strcmp("5", choice) == 0 || strcmp("6", choice) == 0 || strcmp("7", choice) == 0)
						{
							if (*choice != '7')
							{
								
								switch (*choice)
								{
								case '1':
									try
									{
										cout << "enter the element you want to insert" << endl;
										cin >> element;
										if (!st.isFull()) {
											cout << "push:" << element << "\t\t";
											st.push(element);
										}

									}

									catch (Stack<int>::full)
									{
										cout << "stack is full" << endl;
									}
									break;
								case '2':
									try
									{
										cout << st.pop();

									}
									catch (Stack<int>::empty)
									{
										cout << "stack is empty" << endl;
									}
									break;
								case '3':
									try
									{
										if (!st.isEmpty())
										{
											cout << "the elemnet at the top of the stack is" << st.peek() << endl;
										}

									}
									catch (Stack<int>::empty)
									{
										cout << "stack is empty" << endl;
									}
									break;
								case '4':
									if (!st.isFull())
										cout << "the stcak is not full" << endl;
									else
									{
										cout << "stack is full" << endl;
									}
									break;
								case '5':
									if (!st.isEmpty())
										cout << "the stack is not Empty" << endl;
									else
									{
										cout << "stack is empty" << endl;
									}
									break;
								case '6':
									st.printStack();
									break;
								default:
									break;
								}
							}
							else
							{
								break;
							}
						}
						else
						{
							cout << "enter a valid choice" << endl;
						}
					}
					
					break;
				}
				case '2':
				{

					cout << "***** Stack using template *****" << endl;

					cout << "*** float Type Stack***" << endl;
					float element;
					Stack<float> st;
					strcpy_s(choice, 10, "");
					while (*choice != '7')
					{
						cout << "choose the options from below" << endl;
						cout << "1.push the element" << endl;
						cout << "2.pop the element" << endl;
						cout << "3.know the top element" << endl;
						cout << "4.know whether stack is full" << endl;
						cout << "5.know wheather stack is empty" << endl;
						cout << "6.display the elemnets of the stack" << endl;
						cout << "7.exit from loop";
						cout << endl;
						cout << "ENTER YOUR CHOICE";
						cin >> choice;

						if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0 || strcmp("4", choice) == 0 || strcmp("5", choice) == 0 || strcmp("6", choice) == 0 || strcmp("7", choice) == 0)
						{
							if (*choice != '7')
							{

								switch (*choice)
								{
								case '1':
									try
									{
										cout << "enter the element you want to insert" << endl;
										cin >> element;
										if (!st.isFull()) {
											cout << "push:" << element << "\t\t";
											st.push(element);
										}

									}

									catch (Stack<int>::full)
									{
										cout << "stack is full" << endl;
									}
									break;
								case '2':
									try
									{
										cout << st.pop();

									}
									catch (Stack<int>::empty)
									{
										cout << "stack is empty" << endl;
									}
									break;
								case '3':
									try
									{
										if (!st.isEmpty())
										{
											cout << "the elemnet at the top of the stack is" << st.peek() << endl;
										}

									}
									catch (Stack<int>::empty)
									{
										cout << "stack is empty" << endl;
									}
									break;
								case '4':
									if (!st.isFull())
										cout << "the stcak is not full" << endl;
									else
									{
										cout << "stack is full" << endl;
									}
									break;
								case '5':
									if (!st.isEmpty())
										cout << "the stack is not Empty" << endl;
									else
									{
										cout << "stack is empty" << endl;
									}
									break;
								case '6':
									st.printStack();
									break;
								default:
									break;
								}
							}
							else
							{
								break;
							}
						}
						else
						{
							cout << "enter a valid choice" << endl;
						}
					}

					break;
				}

				case '3':
				{
					cout << "\n*** String Type Stack***" << endl;
					Stack<string> st;
					cout << "***** Stack using template *****" << endl;

					cout << "*** Integer Type Stack***" << endl;
					char element[50];
					 
					strcpy_s(choice, 10, "");
					while (*choice != '7')
					{
						cout << "choose the options from below" << endl;
						cout << "1.push the element" << endl;
						cout << "2.pop the element" << endl;
						cout << "3.know the top element" << endl;
						cout << "4.know whether stack is full" << endl;
						cout << "5.know wheather stack is empty" << endl;
						cout << "6.display the elemnets of the stack" << endl;
						cout << "7.exit from loop";
						cout << endl;
						cout << "ENTER YOUR CHOICE";
						cin >> choice;

						if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0 || strcmp("4", choice) == 0 || strcmp("5", choice) == 0 || strcmp("6", choice) == 0 || strcmp("7", choice) == 0)
						{
							if (*choice != '7')
							{

								switch (*choice)
								{
								case '1':
									try
									{
										cout << "enter the element you want to insert" << endl;
										cin >> element;
										if (!st.isFull()) {
											cout << "push:" << element << "\t\t";
											st.push(element);
										}

									}

									catch (Stack<int>::full)
									{
										cout << "stack is full" << endl;
									}
									break;
								case '2':
									try
									{
										cout << st.pop();

									}
									catch (Stack<int>::empty)
									{
										cout << "stack is empty" << endl;
									}
									break;
								case '3':
									try
									{
										if (!st.isEmpty())
										{
											cout << "the elemnet at the top of the stack is" << st.peek() << endl;
										}

									}
									catch (Stack<int>::empty)
									{
										cout << "stack is empty" << endl;
									}
									break;
								case '4':
									if (!st.isFull())
										cout << "the stcak is not full" << endl;
									else
									{
										cout << "stack is full" << endl;
									}
									break;
								case '5':
									if (!st.isEmpty())
										cout << "the stack is not Empty" << endl;
									else
									{
										cout << "stack is empty" << endl;
									}
									break;
								case '6':
									st.printStack();
									break;
								default:
									break;
								}
							}
							else
							{
								break;
							}
						}
						else
						{
							cout << "enter a valid choice" << endl;
						}
					}


					 

					break;
				}
				default:
				{
					break;
				}
				}
			}
			else
			{
				return -1;
			}

		}
		else
		{
			cout << "please enter a valid choice" << endl;
		}
	}



	

	system("pause");
	return 0;
}