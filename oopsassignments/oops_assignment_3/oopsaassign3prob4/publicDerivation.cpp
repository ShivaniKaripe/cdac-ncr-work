
#include <iostream>

using namespace std;
//defination of parent class
class Parent{
public:
	//parentMethod is a public defined method
	 
  void parentMethod( void )
  {
   cout<<"Inside parent method"<<endl;
  }
};
//defination of childclass
class Child : public Parent{
public:
	//defination of child method
  void childMethod( void)
  {
    cout<<"Inside child method"<<endl;
    //parentMethod();
  }
};
//main function
int main( void ){
	//creating an object to child class
  Child C;
  try
  {
  //calling the childMethod 
  	C.childMethod();
  	
  }
  catch(...)
  {
  	cout<<"childMethod is inaccessible"<<endl;
  }
  try
  {
  //calling parent method
  	C.parentMethod();
  }
  catch(...)
  {
  	cout<<"parentMethod is inaccessible"<<endl;
  }
  return 0;
}
