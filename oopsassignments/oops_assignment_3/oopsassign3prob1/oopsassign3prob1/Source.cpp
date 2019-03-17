/*Write a generic function template to carry out linear search with the following
a. Demonstrate it for int, double and float data types
b. Use default arguments in the template function
c. Write an explicit specialization of the generic template for char* data type
d. Demonstrate it for complex data type*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
template <class T>
//linear search function for integer,float,double
bool linear_search(T a[], int length, int searchInt)
{
	bool flag = 0;
	for (int iterator = 0; iterator < length; iterator++)
	{
		if (a[iterator] == searchInt)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
//linear search function to search a complex numbers
bool linear_search(int real[], int img[],int length,int realSearch,int imgSearch)
{
	bool flag = 0;
	for (int iterator = 0; iterator < length; iterator++)
	{
		
		if ( real[iterator]==realSearch)
		{
			if (img[iterator] == imgSearch)
			{
				 
				flag = 1;
				break;
			}
		}
	}
	return flag;
}
//linear search function to search a string
bool linear_search(char *strings[], int length, char *searchString)
{
	int flag = 0;
	for (int iterator = 0; iterator < length; iterator++)
	{
		if (strcmp(strings[iterator], searchString) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int main()
{
	char choice[10];
	bool flag;
	int searchInt=0;
	char searchString[10] ;
	int imgSearch, realSearch;
	int arrInt[] = { 1,2,3,4,5,6,7,8,9,10 };
	double arrDouble[] = { 1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,1.10 };
	int arrImg[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arrReal[] = { 2,3,4,5,6,7,8,9,10,11 };
	char*arrStr[] = { "shivani","shiva","lasya","shagun","keerthana","cherry","lotus","raja","maza","ranga" };

	while (true)
	{
		cout << "1.search an integer" << endl << "2.search a string" << endl << "3.search a complex number" << endl << "4.exit" << endl;
		cout << "enter your choice"<<endl;
		cin >> choice;
		switch (*choice)
		{
		case '1':
			cout << "\n enter the value you want to search" << endl;
			cin >> searchInt;
			flag = linear_search(arrInt, 10, searchInt);
			if (flag == 1)
				cout << "\n the elemenet found"<<endl;
			else
				cout << "\n the element not found"<<endl;
			break;
		case '2':
			cout << "\n enter the value you want to search"<<endl;
			cin >> searchString;
			flag = linear_search(arrStr, 10,  searchString);
			if (flag == 1)
				cout << "\n the elemenet found"<<endl;
			else
				cout << "\n the element not found"<<endl;
		break;
		case '3':
			cout << "enter the real part"<<endl;
			cin >> realSearch;
			cout << "enter the imaginary part"<<endl;
			cin >> imgSearch;
			flag = linear_search(arrReal, arrImg, 10, realSearch, imgSearch);
			if (flag == 1)
				cout << "\n the elemenet found"<<endl;
			else
				cout << "\n the element not found"<<endl;
		break;
		case 4:
			return -1;
			
		break;
		default:
			cout << "enter a correct choice"<<endl;
		}
		

			
	}

	system("pause");
	
	return 0;
}