/*basics
explorig  the basic functions mentioned below
1.isTextUnicode
2.MultiByteToWideChar
3.WideCharToMultiByte*/
#include<string.h>
#include<Windows.h>
#include<stdio.h>
int main()
{
	CHAR c = 'A';
	WCHAR wc = L'A';
	CHAR ansi[] = "ANSI";
	WCHAR wchar[] = L"WCHAR";
	printf_s(" the value of char is %s", c);
	printf_s("the value of wchar is  %S", wc);

	system("pause");

}