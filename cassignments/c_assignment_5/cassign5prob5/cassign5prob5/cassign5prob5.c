#include<stdio.h>
int main()
{
	int day1, mon1, year1, day2, mon2, year2;
	printf_s("enter the first date in the order of day, month,year\n ");
	scanf_s("%d %d %d", &day1, &mon1, &year1);
	printf_s("enter the second date in the order of day, month,year\n ");
	scanf_s("%d %d %d", &day2, &mon2, &year2);
	if (mon1 > 12 || mon2 > 12 || day1 > 31 || day2 > 31)
	{
		printf_s("Invalid input");
		return -1;
	}

}