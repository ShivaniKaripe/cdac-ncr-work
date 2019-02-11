#include<stdio.h>
#include<string.h>
void deletechar(char *,char);
int main()
{
	char ch,s[10];
	printf_s("enter the string which you want to modify");
	gets(s);
	
	printf_s("enter the character you want to delete in '%s'", s);
	scanf_s("%c", &ch);
	deletechar(s,ch);
}
void deletechar(char *s,char ch)
{
	int c = 0;
	int len = strlen(s);
	while ((*s) != '\0')
	{
		if ((*s) == ch)
		{	
			c = 0;
			while ((*s) != '\0')
			{
				*s = *(s + 1);
				s = s + 1;
				c++;

			}
			*s = '\0';
			s = s - c;
		}
		
		s = s + 1;

	}
	s = s - len;
	
	printf_s("\n \n %s", s);
	scanf_s("%d", &c);
}