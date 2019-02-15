/*Define a class named Employee with data members empno, name, & salary and
appropriate member functions for setting and reading the data, constructors and
destructor. Create an array of 5 Employee objects, populate it with data by
overloading >> operator*/
#include<iostream>
#include<string.h>
using namespace std;
class Employee
{
	int empno;
	char name[50];
	long int salary;

public:
	Employee()
	{
		empno = 0;
		strcpy_s(name, "");
		salary = 0;

	}
	~Employee()
	{
		std::cout << "destructor is initialized";
	}

	void set_data(int eno, char s[], long int sal)
	{
		empno = eno;
		strcpy_s(name, s);
		salary = sal;


	 }
	void get_data()
	{
		cout<< "employee number is" << empno <<endl;
		cout << "employee name is" << name << endl;
		cout << "employee salary is" << salary << endl;
		cout << "------------------------------------" << endl;

	}
	friend istream& operator >> (istream &cin, Employee &e);
	friend ostream& operator << (ostream &cout, Employee e);

};

istream& operator >> (istream &cin, Employee &e)
{
	std::cout << "enter the value of  employee in the form of employee number,name,salary" << endl;
	cin >> e.empno;
	cin >> e.name;
	cin >> e.salary;
	e.set_data(e.empno,e.name,e.salary);
	return cin;

}
ostream& operator << (ostream &cout, Employee e)
{
	e.get_data();
	return cout;

}
int main()
{
	Employee e[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> e[1];
		
	}
	for (int i = 0; i < 5; i++)
	{
		cout << e[1];
	}
	system("pause");
}
 
