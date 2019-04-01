///*Write a C++ program to define two different namespaces in two different files. Define two
//methods Add() and Subtract () in both the namespaces with different functionality. In one
//namespace, perform normal addition and subtraction. In another namespace, perform
//the addition and subtraction after taking the absolute values of the arguments. Now, call
//these functions from the main program which is in a different file in order to demonstrate
//the concept of namespaces*/
//#include<iostream>
namespace File1namespace
{
	class Namespace1
	{
	public:
		int add(int number1, int number2)
		{
			return number1 + number2;
		}
		int subtract(int number1, int number2)
		{
			return number1 - number2;
		}
	};
}
// 
