/*Define STUDENT class with data members rollno, name, marks of subjects, total
marks, and grade. Overload >> for reading the STUDENT details, Overload << for
displaying the STUDENT details, include a friend function generate_results
(STUDENT [], int n); which takes an array of STUDENT objects corresponding to n
students and generates total marks and grade for each of the student. Please display
the results of all students using overloaded << operator*/
#include<iostream>
#include<string.h>
using namespace std;
class Student
{
	int rollno;
	char name[50];
	int sub1, sub2, sub3;
	int total;
	char grade;
public:
	Student()
	{
		rollno = 0;
		name[50] ="";

	}
	Student(int r , char n[], int s1 = 0, int s2 = 0, int s3 = 0)
	{
		rollno = r;
		strcpy(name,n);
		sub1 = s1;
		sub2 = s2;
		sub3 = s3;

		
	}
	friend ostream& operator<<(ostream &cout, Student s);
	friend istream& operator<<(istream &cin, Student &s);
	friend void generate_results(Student[], int n);
};
ostream& operator<<(ostream &cout, Student s)
{
	cout << "student roll no is"<<s.rollno <<endl;
	cout << "student name is"<<s.name <<endl;
	cout << "subject 1 marks"<<s.sub1 <<endl;
	cout << "subject 2 marks"<<s.sub2 <<endl;
	cout << "subject 3 marks"<<s.sub3 <<endl;
	cout << "total marks are"<<s.total <<endl;
	cout << "grade of the student is" << s.grade << endl;
	return cout;
}
istream& operator>>(istream& cin, Student &s)
{
	cin >> s.rollno;
	cin >> s.name;
	return cin;

}
void generate_results(Student s[], int n)
{
	for (int i = 0; i<n; i++)
	{
		cout << s[i];
	}
}
int main()
{
	Student s1;
	cin >> s1;
}