#include<stdio.h>
#include<string.h>
//void strtok(char *, char);
int main()
{
	char s[50];
	char ch;
	printf_s("enter the string you want to tokenize");
	gets(s);
	printf_s("\n enter the tokenizer using which you want to tokenize");
	scanf_s("%[^\n]c", &ch);
	 
	
	int count = 0;
	char *temp;
	temp = s;
	for (; (*s) != '\0'; s++)
	{
		if ((*s) == ch)
		{
			*s = '\0';
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf_s("%s", temp);
	}
}
 
