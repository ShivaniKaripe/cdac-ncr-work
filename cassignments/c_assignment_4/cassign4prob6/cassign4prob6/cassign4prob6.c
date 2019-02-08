#include<stdio.h>
#include<string.h>
void reverse(char ,char );
int main()
{
char s[10];
	printf_s("enter the string");
	gets(s);
	int len = strlen(s);
	reverse(s,s+(len-1));
	printf_s("%s", s);
	scanf_s("%d", &len);

}
void reverse(char *a, char *b)
{
	char temp;
	if (a >= b)
	{
		return;
	}
	else
	{
		temp = *a;
		*a = *b;
		*b = temp;
		a = a + 1;
		b = b - 1;
		reverse(a, b);

	}
	
}


