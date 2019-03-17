#include <iostream>

using namespace std;

class GrandParent{
public:
  void grandParentMethod( void )
  {
   cout<<"Method in the grand parent class"<<endl; 
  }
};

class Parent : protected GrandParent{
public:
  void parentMethod( void )
  { 
  cout<<"Method in the parent class"<<endl; 
  }
};

class Child: protected Parent{
public:
  void 
  childMethod( void ){
    cout<<"Method in the child class"<<endl;
    parentMethod();
    grandParentMethod();
  }
};

int main( void ){

  Child C;
  C.childMethod();
  return 0;

}
