/*Define string class with dynamic memory allocation for string. Define default
constructor, parameterized constructors, copy constructor, destructor, Overload +,
[], =, <<, >> operators. Observe the behavior of shallow copying and deep copying.*/
#include<iostream>
#include<string.h>
using namespace std;
class String
{
	char *ptr;
	int l;
public:
	String()
	{
		ptr = NULL;
		l = 0;
	}
	String(char *p, int len)
	{
		ptr = new char[len+1];
		l = len;
		strcpy(ptr, p);
	}
	String(const String &s)
	{
		l = s.l;
		ptr = new char[l + 1];
		strcpy(ptr, s.ptr);
	}
	~String()
	{
		//destructor
	}
	String operator+(String s)
	{
		String temp;
		temp.l = l + s.l;
		temp.ptr = new char[(temp.l+1)];
		temp.ptr = strcat(ptr, s.ptr);
		return temp;
	}
	char& operator[](int i)
	{
		 
		return ptr[i];
	}
	String operator=(String s)
	{
		l = s.l;
		if (ptr != NULL)
			delete ptr;
		ptr = new char[(l + 1)];
		strcpy(ptr, s.ptr);
		return(*this);
	}
	friend istream& operator>> (istream &cin, String &s);
	friend ostream& operator<<(ostream &cout, String s);
	 
};
istream& operator>> (istream &cin, String &s)
{
	cout << "enter the lnghth of the string and enter the string";
	std::cin >>s.l;
	s.ptr = new char[(s.l + 1)];
	std::cin >>s.ptr;
	return cin;
}
ostream& operator<<(ostream &cout, String s)
{
	cout << "the length of the string is" << s.l << endl;
	cout << "the string is " << s.ptr << endl;
	return cout;
}
int main()
{
	String s1, s2, s3;
	
	cin >> s1;
	cin >> s2;
	s3 = s1 + s2;
	cout << "the result of s3=s1+s2 is" << endl;
	cout << s3;
	cout << endl;
	s3 = s2;
	cout << "the result of s3=s2 is" << endl;
	cout << s3;
	cout << endl;
	s2[3] = 'p';
	cout << "the result after performing s2[3]='p' is" << endl;
	cout << s2[3];

}
