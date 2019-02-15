/*Write a program to find out difference in days between any two dates. It
must work regardless of the year, month and day. Consider Leap years
while calculating the difference.*/
#include<stdio.h>
int main()
{
	int year1, year2,mon1,mon2,day1,day2;
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int days = 0;
	int temp;
	printf_s("enter the date in the 'DD MM YYYY' format");
	scanf_s("%d %d %d", &day1, &mon1, &year1);
	printf_s("enter the date in the 'DD MM YYYY' format");
	scanf_s("%d %d %d", &day2, &mon2, &year2);
	
	int leap1 = (year1 / 4 - year1 / 100 + year1 / 400);
	int leap2 = (year2 / 4 - year2 / 100 + year2 / 400);

	int days2 = (year2 - 1) * 365;
	if((year2%4==0)||(year2%400==0))
	if (((mon2 == 1) && (day2 <= 31) || (mon2 == 2) && (day2 <= 28)))
		leap2--;
	printf_s("%d", leap2-leap1);

	system("pause");

}