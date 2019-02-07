#include<stdio.h>
int main()
{
	int n=0;
	int a[100];
	printf_s("enter the elements when you want to stop press 0 or any negative number");
	for (int i = 0; i < 100; i++)
	{
		scanf_s("%d", &a[i]);
		n++;
		if (a[i] <= 0)
			break;
	}
	n--;
	printf_s(" no of positive values enetered %d", n);
		
	scanf_s("%d", n);
}