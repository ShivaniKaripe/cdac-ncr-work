/*Write a C program to open a file and store text (character type data) in
one’s complement form. Read the contents from the file and display as it
is as well in one’s complement form. Use command line arguments to
pass file name to your C program*/
#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
	unsigned char ch[100];
	FILE *fp;
	if (argc <= 1)
	{
		printf_s("please pass the correct input ");
		return -1;
	}
	fopen_s(&fp,argv[1], "a+");
	printf("enter the text you want to store it in the file");
	gets(ch);
	for (int i = 0; i < strlen(ch); i++)
	{
		fputc(~ch[i], fp);
	}
	
	 
	rewind(fp);
	fgets(ch, 100, (FILE*)fp);
	printf("2: %s\n", ch);


}
