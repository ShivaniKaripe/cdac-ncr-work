/*Write a program to demonstrate the situation where it is necessary to write the
code for copy constructor.*/
/*one of the situation where the copy constructor is necessary is when we are dynamically alloacting 
memory for pointer using deep copy*/
#include<iostream>

using namespace std;

class Array
{
	int len;
	int *ptr;
public:
	Array()
	{
		len = 0;
		ptr = NULL;
	}
	Array(int l, int*p)
	{
		len = l;
		ptr = new int[len];
		for (int i = 0; i < len; i++)
		{
			ptr[i] = p[i];
		}
	}
	Array(const Array &a)
	{
		len = a.len;
		ptr = new int[len ];
		for (int i = 0; i < len; i++)
		{
			ptr[i] = a.ptr[i];
		}

	}
	friend istream& operator >> (istream &cin, Array &a);
	friend ostream& operator<<(ostream &cout, Array a);
};
istream& operator >> (istream &cin, Array &a)
{
	for (int i = 0; i < a.len; i++)
	{
		cout << "enter the" << i << "th value of array";
		cin >> a.ptr[i];
	}
	return cin;
}
ostream& operator<<(ostream &cout, Array a)
{
	cout << "the array values are" << endl;
	for (int i = 0; i < a.len; i++)
	{
		cout << a.ptr[i];
	}
	return cout;
}
int main()
{
	int a[] = { 1,2,3,4,5 };
	Array a1(5, a);
	Array a2(a1);
	cout << a2;
	system("pause");
}
