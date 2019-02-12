/*Write a program which reads a line of characters. Each character entered
from the keyboard is tested to determine its case, and is then written to
the data file in opposite case. Display the contents of the file. Also use
ftell and fseek to determine the current file position and to change the
file position*/
#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fp;
	fopen_s(&fp, "newfile.txt", "a+");
	char ch;
	printf_s("enter the charactes");
	while ((ch = getchar()) != '\n')
	{
		if ((ch >= 'A') && (ch <= 'Z'))
		{
			ch = ch + 32;
		}
		else if((ch>='a')&&(ch<='z'))
		{
			ch = ch - 32;
		}
		fputc(ch, fp);
	}
	rewind(fp);
	while (!feof)
	{
		ch=fgetc(fp);
		printf_s("%c", ch);
	}
	system("pause");
}