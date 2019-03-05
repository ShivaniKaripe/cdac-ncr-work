/*Write a generic function template to carry out linear search with the following
a. Demonstrate it for int, double and float data types
b. Use default arguments in the template function
c. Write an explicit specialization of the generic template for char* data type
d. Demonstrate it for complex data type*/
#include<iostream>
#include<string.h>
using namespace std;
template <class T>
int linear_search(T a[], int l, int x)
{
	int flag = 0;
	for (int i = 0; i < l; i++)
	{
		if (a[i] == x)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int linear_search(int real[], int img[],int l,int r,int i)
{
	int flag = 0;
	for (int i = 0; i < l; i++)
	{
		if ( real[i]==r)
		{
			if (img[i] == i)
			{
				flag = 1;
				break;
			}
		}
	}
	return flag;
}
int linear_search(char *str[], int l, char *x)
{
	int flag = 0;
	for (int i = 0; i < l; i++)
	{
		if (strcmp(str[i], x) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int main()
{
	char* ele=NULL;
	int arrInt[] = { 1,2,3,4,5,6,7,8,9,10 };
	double arrDouble[] = { 1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,1.10 };
	int arrImg[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arrReal[] = { 2,3,4,5,6,7,8,9,10,11 };
	char*arrStr[] = { "shivani","shiva","lasya","shagun","keerthana","cherry","lotus","raja","maza","ranga" };
	cout<<"\n enter the value you want to search";
	cin >> ele;
	int flag=linear_search(arrStr, 10, ele);
	if (flag == 1)
		cout<<"\n the elemenet found";
	else
		cout<<"\n the element not found";
	system("pause");
	
	return 0;
}