#include<stdio.h>
#include<string.h>
int main()
{
	char s[10];
	printf_s("enter the sring ");
	gets(s);
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
		{
			s[i] = s[i] + 32;
		}
	}
	printf_s("\n the string in lower case is %s", s);
	
	for (int i = 0; i < len; i++)
	{
		if ((s[i] >= 'a') && (s[i] <= 'z'))
		{
			s[i] = s[i] - 32;
		}
	}
	printf_s("\n the string in upper case is %s", s);
	scanf_s("%d", &len);
}