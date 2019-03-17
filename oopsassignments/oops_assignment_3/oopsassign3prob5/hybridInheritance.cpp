/*Write a program to demonstrate hybrid inheritance with virtual classes using the
following classes,
class person: base class
data members: name, age
class physique: derived virtually from person
data members: height, weight
class family: derived virtually from person:
data members:numChildren, religion
class employee derived from physique & family
data members: empno, salary.*/
#include<iostream>
#include<string>
using namespace std;
class person
{
public:
	string name;
	int age;
	person()
	{
		name = "shivani";
		age = 20;
	}
	void display()
	{
		cout << "name: " <<name << " " << "age:" << age << endl;
	}
};

class physique : virtual public person
{
public:
	float height;
	float weight;
	physique()
	{
		height = 5.5;
		weight = 49.5;
	}
	void display()
	{

		cout << "the person height and weight are " << height << " feet " << weight <<" kgs"<< endl;
	}
};
class family : virtual public person
{
public:
	int numChildren;
	string religion;
	family()
	{
		numChildren = 2;
		religion = "hindu";
	}
	void display()
	{
		cout << "the number of children are " << numChildren << " and religion is " << religion << endl;    	
	}
};
class employee : public physique, public family
{
public:
	int empno;
	float salary;
	employee()
	{
		empno = 4041;
		salary = 50000.00;
	}
	void display()
	{
		 
		cout << "the employee number is " << empno << " salary is " << salary << endl;
	}
};
int main()
{
	person *personObject;
	family familyObject;
	personObject=&familyObject;
	personObject->display();
	physique physiqueObject;
	personObject= &physiqueObject
	personObject->display();
	employee employObject;
	
	employObject.display();
	system("pause");
	return 0;
}
