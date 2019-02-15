/*Define polar class where each object represents a point in polar coordinates (angle
and radius). Include static data member which keeps tracking the number of active
objects of the class.*/
#define PI 3.14159265
#include<iostream>
#include<math.h>

using namespace std;
class Polar
{
	float angle;
	float radius;
	float x,y;
	float val = PI / 180.0;
public:
	void set_data(float r,float a)
	{
		angle = a;
		radius = r;
	}
	void coordinates()
	{
		x = radius * cos(angle*PI);
		y = radius * sin(angle*PI);
	}
	void get_data()
	{
		cout << "the x coordinate of the polar coordinate is" << x << endl;
		
		cout <<  "the y coordinate of the polar coordinate is"<<fixed << floor(100 * y) / 100<< endl;
	}
};
int main()
{
	float radius, angle;
	Polar p1;
	cout << "enter values for radius and angle" << endl;
	cout << "Note:enter tha value of angle in degrees" << endl;
	cin >> radius >> angle;
	p1.set_data(radius,angle);
	p1.coordinates();
	p1.get_data();
	system("pause");

}