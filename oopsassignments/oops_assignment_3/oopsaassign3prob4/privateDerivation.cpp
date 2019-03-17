
#include <iostream>

using namespace std;

class Parent{
public:
  void parentMethod( void )
  {
   cout<<"Inside parent method"<<endl;
  }
};

class Child : private Parent{
public:
  void childMethod( void)
  {
    cout<<"Inside child method"<<endl;
    parentMethod();
  }
};

int main( void ){
  Child C;
  try
  {
  
  	C.childMethod();
  	
  }
  catch(...)
  {
  	cout<<"childMethod is inaccessible"<<endl;
  }
  try
  {
  
  	//C.parentMethod();
  }
  catch(...)
  {
  	cout<<"parentMethod is inaccessible"<<endl;
  }
  return 0;
}
