/*Define matrix class. Include following member functions
a.	Default, parameterized and copy constructors (allocate memory dynamically)
b.	Destructor
c.	Overload +,=, << and >> operators
*/
#include<iostream>
using namespace std;
//declaration of class matrix
 
class Matrix
{
	int noOfRows;
	int noOfColumns;
	int  **matrix;
public:
	Matrix()  //default constructor
	{
		noOfRows = 0;
		noOfColumns = 0;
	}
	Matrix(int noOfRows, int noOfColumns)   // Parameterized constructor
	{
		this->noOfRows = noOfRows;
		this->noOfColumns = noOfColumns;
		matrix = new int*[noOfRows];
		for (int iterator = 0; iterator < noOfRows; iterator++)
		{
			matrix[iterator] = new int[noOfColumns];
		}
		for (int row = 0; row < noOfRows; row++)
		{
			for (int column = 0; column < noOfColumns; column++)
			{
				matrix[row][column] = 0;
			}
		}
	}
	/*Matrix(const Matrix &matrixObj)  // copy constructor
	{
		noOfRows = matrixObj.noOfRows;
		noOfColumns = matrixObj.noOfColumns;
		matrix = new int*[noOfRows];
		for (int iterator = 0; iterator < noOfRows; iterator++)
		{
			matrix[iterator] = new int[noOfColumns];
		}
		for (int row = 0; row < noOfRows; row++)
		{
			for (int column = 0; column < noOfColumns; column++)
			{
				matrix[row][column] = matrixObj.matrix[row][column];
			}
		}
	}*/
	~Matrix() //destructor
	{
		//cout << "in destrucotr" << endl;
		for (int iterator = 0; iterator < noOfColumns; iterator++)
		{
			delete matrix[iterator];
		}
		delete matrix;
	}
	Matrix operator+(Matrix);
	Matrix operator=(Matrix);
	friend istream& operator>>(istream&, Matrix&);
	friend ostream& operator<<(ostream&, Matrix);
};
//overloading operator +
Matrix Matrix::operator+(Matrix matrixObj)
{
	if (noOfRows == matrixObj.noOfRows&&noOfColumns == matrixObj.noOfColumns)
	{
		Matrix temp(noOfRows, noOfColumns);
		for (int rowNo = 0; rowNo < noOfRows; rowNo++)
		{
			for (int columnNo = 0; columnNo < noOfColumns; columnNo++)
			{
				temp.matrix[rowNo][columnNo] = matrix[rowNo][columnNo] + matrixObj.matrix[rowNo][columnNo];
			}
		}
		return temp;
	}
	 
}
//overloading operator =
Matrix Matrix::operator=(Matrix matrixObj)
{
	noOfRows = matrixObj.noOfRows;
	noOfColumns = matrixObj.noOfColumns;
	matrix = new int*[noOfRows];
	for (int iterator = 0; iterator < noOfRows; iterator++)
	{
		matrix[iterator] = new int[noOfColumns];
	}
	for (int row = 0; row < noOfRows; row++)
	{
		for (int column = 0; column < noOfColumns; column++)
		{
			matrix[row][column] = matrixObj.matrix[row][column];
		}
	}
	return (*this);
}
//overloading cin(operator >>)
istream& operator>>(istream& cin, Matrix& matrixObj)
{
	for (int row = 0; row < matrixObj.noOfRows; row++)
	{
		for (int column = 0; column < matrixObj.noOfColumns; column++)
		{
			cout << "enter  [ " << row << "][" << column << "]  element";
			cin >> matrixObj.matrix[row][column];
		}
	}
	return cin;
}
//overloading cout(operator <<)
ostream& operator<<(ostream& cout, Matrix matrixObj)
{

	for (int row = 0; row < matrixObj.noOfRows; row++)
	{
		for (int column = 0; column < matrixObj.noOfColumns; column++)
		{
			cout << matrixObj.matrix[row][column];
			cout << "      ";
		}
		cout << endl;
	}
	return cout;
}
 
int main()
{
	 
	int noOfRows=0, noOfcolumns = 0;
	int choice = 0;
	cout << "enter the  matrix on which you want to perform operation" << endl;
	cout << "enter the no of rows " << endl;
	cin >> noOfRows;
	cout << "enter the no of columns" << endl;
	cin >> noOfcolumns;
	Matrix matrixObject1(noOfRows, noOfcolumns);
	cin >> matrixObject1;

	while (true)
	{
		cout << "please choose the option from the below list" << endl;
		cout << "1.matrix addition" << endl;
		cout << "2.matrix assignment using copy constructor" << endl;
		cout << "3.matrix assignment using assignment operator" << endl;
		cout << "4.exit" << endl;
		cout << "enter your choice" << endl;
		cin >> choice;
		while (std::cin.fail())
		{
			cout << "error" << endl;
			cout << "please enter a valid input" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			cout << "enetr the  matrix to perform addition " << endl;
			cout << "enter the no of rows " << endl;
			cin >> noOfRows;
			cout << "enter the no of columns" << endl;
			cin >> noOfcolumns;
			Matrix matrixObject2(noOfRows, noOfcolumns);
			cin >> matrixObject2;
			cout << matrixObject1 + matrixObject2;
			break;
		}
		case 2:
		{
			 
			Matrix matrixObject3(matrixObject1);
			cout << "after copying the values" << endl;
			cout << matrixObject3;
			break;
		}
		case 3:
		{
			 
			Matrix matrixObject2=matrixObject1;
			cout << "after copying the values" << endl;
			cout << matrixObject2;
			break;
		}
		case 4:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "please provide a valid input" << endl;
		}
			break;
		}
	}
	system("pause");
}