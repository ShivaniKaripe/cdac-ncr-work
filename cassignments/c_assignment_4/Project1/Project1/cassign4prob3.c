#include<stdio.h>
int main()
{	
	int n=0;
	char * s[] = { "we will teach you how to", "Move a mountain ", "Level a building ", "Erase the past ", "Make a million " };
	printf_s("%c", s[1][2]);
	int len = sizeof(s) / sizeof(s[0]);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; s[i][j] != '\0'; j++)
		{
			if (s[i][j] == 'e')
				n++;
		}
	}
	printf_s("number of e's are %d",n );

	scanf_s("%d", &n);
}