#include<iostream>
#include "NameSpace1.h"
//
using namespace std;

//#include "Namespace2.cpp"
using namespace File1namespace;

 

//void  File2namespaceX:: addx(int, int);

int main()
{
	int input1, input2;
	Namespace1 ns1;
	
	//cout << "addition of 23 and 2 is" << File1namespace::add(23, 2) << endl;
	cout << "enter first number" << endl;
	cin >> input1;
	cout << "enter second number" << endl;
	cin >> input2;
	cout << ns1.add(5, 2);// ::add(input1, input2);
	
}
 
