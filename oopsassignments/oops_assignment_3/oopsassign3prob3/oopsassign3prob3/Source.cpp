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
		cout << "the area of the Rectangle is " << b*l << endl;
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
		cout << "the area of the square is " << a*a << endl;
	}
};
int main()
{
	char choice[10]="";
	int a, b;
	Shape *s;
	while (*choice != '4')
	{
		cout << "choose any of the following" << endl;
		cout << "find the area of triangle" << endl;
		cout << "find the area of rectangle" << endl;
		cout << "find the area of square" << endl;
		cout << "exit" << endl;
		cout << "enter your choice" << endl;
		cin >> choice;
		if (*choice != '4')
		{
			switch (*choice)
			{
			case '1':
			{
				cout << "enter the breadth value" << endl;
				cin >> a;
				cout << "enter the height value" << endl;
				cin >> b;
				Triangle t(a, b);
				s = &t;
				s->display_area();
				break;
			}
			case '2':
			{
				cout << "enter the breadth value" << endl;
				cin >> a;
				cout << "enter the lenght value" << endl;
				cin >> b;
				Rectangle r(a, b);
				s = &r;
				s->display_area();
				break;
			}
			case '3':
			{
				cout << "enter the side value" << endl;
				cin >> a;
				Square sq(a);
				s = &sq;
				s->display_area();
				break;
			}
			default:
			{	cout << "enter a valid choice" << endl;
			break;
			}
			}
		}
	} 
	
	system("pause");
}