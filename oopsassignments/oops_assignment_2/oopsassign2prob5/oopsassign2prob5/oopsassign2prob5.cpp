/*Define string class with dynamic memory allocation for string. Define default
constructor, parameterized constructors, copy constructor, destructor, Overload +,
[], =, <<, >> operators. Observe the behavior of shallow copying and deep copying.*/
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
//creates a class named string
class String
{
	char *ptr;
	int length;
public:
	String()
	{
		ptr = NULL;
		length = 0;
	}
	String(char *p, int len)//parameterised constructor
	{
		ptr = new char[len+1];
		length = len;
		strcpy_s(ptr,length+1, p);
	}
	String(const String &s)//copy constructor
	{
		length = s.length;
		ptr = new char[length + 1];
		strcpy_s(ptr, length+1 ,s.ptr);
	}
	~String()//destructor
	{
		//destructor
	}
	String operator+(String s)//function for string concatenation
	{
		String temp;
		temp.length = length + s.length;
		temp.ptr = new char[(temp.length+1)];
		strcpy_s(temp.ptr, length + 1, ptr);
	    strcat_s(temp.ptr,(temp.length+1), s.ptr);
		return temp;
	}
	char& operator[](int i)
	{
		 
		return ptr[i];
	}
	String operator=(String s)//function for string comparion
	{
		length = s.length;
		if (ptr != NULL)
			delete ptr;
		ptr = new char[(length + 1)];
		strcpy_s(ptr,length+1 ,s.ptr);
		return(*this);
	}
	friend istream& operator>> (istream &cin, String &s);
	friend ostream& operator<<(ostream &cout, String s);
	 
};
istream& operator>> (istream &cin, String &s)//function for overloading >> operator
{
	cout << "enter the lnghth of the string and enter the string";
	std::cin >>s.length;
	s.ptr = new char[(s.length + 1)];
	std::cin >>s.ptr;
	return cin;
}
ostream& operator<<(ostream &cout, String s)//function for overloading <<operator
{
	cout << "the length of the string is" << s.length << endl;
	cout << "the string is " << s.ptr << endl;
	return cout;
}
int main()
{

	String inputString1, inputString2, result;//creating the objects
	char choice[10];
	int position = 0;
	char replace;
	cin >> inputString1;
		strcpy_s(choice, 10, "");
		while (*choice != '7')
		{
			cout << "choose the options from below" << endl;
			cout << "1.string concatenation" << endl;
			cout << "2.copying string to other" << endl;
			cout << "3.replacing a character of string" << endl;
			cout << "4.exit from loop";
			cout << endl;
			cout << "ENTER YOUR CHOICE";
			cin >> choice;
	
			if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0 || strcmp("4", choice) == 0  )
			{
				if (*choice != '4')
				{
	
					switch (*choice)
					{
					case '1':
						try
						{
							cin >> inputString2;
							result = inputString1 + inputString2;
							inputString1(inputString2);
							cout << "the result of s3=s1+s2 is" << endl;
							cout << result;
							cout << endl;
	
						}
	
						catch (...)
						{
							cout << "exception in concatenation" << endl;
						}
						break;
					case '2':
						try
						{
							result = inputString2;
							cout << "the result of s3=s2 is" << endl;
							cout << result;
							cout << endl;
						}
						catch (...)
						{
							cout << "exception in copying a string to other" << endl;
						}
						break;
					case '3':
						try
						{
							cout << "the string is" << inputString1;
							cout << "enter the position of character you want to replece" << endl;
							cin >> position;
							cout << "enter the  character you want to replece with " << endl;
							cin >> replace;
							inputString2[position] = replace;
							cout << "the result after performing replacing operation is is" << endl;
							cout << "the element at position 3 of stringObj2 is" << endl;
							cout << inputString2[3];
	
						}
						catch (...)
						{
							cout << "exception in  replacing" << endl;
						}
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
	
	
	
	
	
	system("pause");
	return 0;
 


}
