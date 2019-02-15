/*Define a complex class, define default constructor, parameterized constructors, copy
constructor, destructor. Overload +, -, unary -, ++ (prefix, postfix), =, comma (,), ->,
<< and >> operators.*/
#include<iostream>
using namespace std;
class Complex
{
	int real;
	int img;
public:
	Complex()
	{
		real = img = 0;

	}
	Complex(int r, int i)
	{
		real = r;
		img = i;
	}
	Complex(const Complex &c)
	{
		real = c.real;
		img = c.img;
	}
	~Complex()
	{
		 
	}
	Complex operator+(Complex c)
	{
		Complex temp;
		temp.real = real + c.real;
		temp.img = img + c.img;
		return temp;
	}
	Complex operator-(Complex c)
	{
		Complex temp;
		temp.real = real - c.real;
		temp.img = img - c.img;
		return temp;
	}
	Complex operator++()
	{
		++real;
		++img;
		return(*this);
	}
	Complex operator++(int i)
	{
		Complex temp;
		temp.real = real++;
		temp.img = img++;
		return temp;


	}
	void operator=(Complex c)
	{
		real = c.real;
		img = c.img;

	}
	Complex operator,(Complex c)
	{
		return c;
	}
	void printcomplex()
	{
		cout << "the vreal and img parts are"<<real<<"         "<<img<<endl;
	}
	Complex* operator->()
	{
		return this;
	}
	Complex operator-()
	{
		Complex res;
		res.real = -real;
		res.img = -img;
		return res;
	}
	friend istream& operator>> (istream &cin, Complex &c);
	friend ostream& operator<<(ostream& cout, Complex c);


};
istream& operator >> (istream &cin, Complex &c)
{
	std::cout << "enter the values of the imaginary number" << endl;
	cin >> c.real;
	cin >> c.img;
	return cin;
}
ostream& operator<<(ostream& cout, Complex c)
{
	cout << "the real part is  " << c.real<<endl;
	cout << "imaginary part is   " << c.img<<endl;
	return cout;
}
int main()
{
	Complex c1(2, 3), c2(4, 5), c3,c4(5,5);
	c3 = c1 + c2;
	cout << "addition of two complex numbers is" << endl<<c3 << endl;
	cout << "----------------------------------------" << endl;
	c3 = c1 - c2;
	cout << "subtraction of two complex numbers is" << endl << c3 << endl;
	cout << "----------------------------------------" << endl;
	c3 = -c1;
	cout << "unary - operation of the complex number is" << endl << c3 << endl;
	cout << "----------------------------------------" << endl;
	c3 = c2;
	cout << "the c3=c2 is" << c3;
	cout << "----------------------------------------" << endl;
	c3 = (c1, c2, c4);
	cout << "the output of c3 = (c1, c2, c3) is   " << c3 << endl;
	cout << "----------------------------------------" << endl;
	c3 = c1, c2, c4;
	cout << "the output of c3 = c1, c2, c4;" << c3;
	cout << "----------------------------------------" << endl;
	c1->printcomplex();
	cout << "----------------------------------------" << endl;
	system("pause");

}
