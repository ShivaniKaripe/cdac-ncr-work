#include<stdio.h>
#include<string.h>
void replace(char*);
int main()
{
	char str[20];
	printf_s("Enter a string");
	gets( str);  
	printf_s("%s", str);
	replace(str);

	int len;
	//= strlen(str);
	//printf_s("%d", len);
	 
	scanf_s("%d", &len);

}
void replace(char *s)
{
	int n = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == "")
		{
			s[i] = '-';
			n++;
		}
	}
	printf_s("%s", s);
	printf_s("%d", n);

}