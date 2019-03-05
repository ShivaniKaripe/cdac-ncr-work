/*Define a shape class. Derive Triangle, Square and Rectangle classes. Demonstrate the
use of virtual function by including display_area ( ) as a virtual function*/
#include<iostream>
using namespace std;
class Shape
{
public:
	Shape()
	{}
	virtual void  display_area()
	{
		cout << "in shape";
	}
};
class Triangle: public Shape
{
	int b, h;
public:
	Triangle(int b1, int h1)
	{
		b = b1;
		h = h1;
	}
	void display_area()
	{
		cout << "the area of the triangle is " <<(float) 0.5*b*h << endl;
	}
};
class Rectangle : public Shape
{
	int b, l;
public:
	Rectangle(int b1, int l1)
	{
		b = b1;
		l = l1;
	}
	void display_area()
	{
		cout << "the area of the triangle is " << b*l << endl;
	}
};
class Square : public Shape
{
	int a;
public:
	Square(int a1)
	{
		a = a1;
	}
	void display_area()
	{
		cout << "the area of the triangle is " << a*a << endl;
	}
};
int main()
{
	int a, b;
	Shape s;
	cout << "enter the breadth value" << endl;
	cin >> a;
	cout << "enter the height value" << endl;
	cin >> b;
	Triangle t(a, b);
	t.display_area();
	cout << "enter the breadth value" << endl;
	cin >> a;
	cout << "enter the lenght value" << endl;
	cin >> b;
	Rectangle r(a, b);
	r.display_area();
	cout << "enter the side value" << endl;
	cin >> a;
	 
	Square sq(a);
	sq.display_area();
	system("pause");
}