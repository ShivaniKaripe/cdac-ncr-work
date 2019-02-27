/*basics
explorig  the basic functions mentioned below
1.isTextUnicode
2.MultiByteToWideChar
3.*/
#include<string.h>
#include<Windows.h>
#include<stdio.h>
void main()
{
 
	CHAR c = 'A';
	WCHAR wc = L'A';
	CHAR ansi[] = "ANSI";
	WCHAR wchar[] = L"WCHAR";
	printf_s("\n the length of wchar is %d ", wcslen(wchar));
	printf_s(" \n the value of char is %c", c);
	printf_s("\n the value of wchar is  %C ", wc);
	printf_s(" \n the value of char is %s", ansi);
	printf_s("\n the value of wchar is  %S ", wchar);
	int ret = IsTextUnicode(ansi, strlen(ansi), NULL);
	if (0 == ret)
		printf_s("\n the input string ansi is not in unicode format");
	else if (1 == ret)
		printf_s("\n the input tring ansi is in unicode format");
	else
	{
		printf("some error occured");
		GetLastError();
		return;

	}

	
		ret = IsTextUnicode(wchar, sizeof(wchar), NULL);
	if (0 == ret)
		printf_s("\n the input string wchar is not in unicode format");
	else if (1 == ret)
		printf_s("\n the input tring wchar is in unicode format");
	else
	{
		printf("some error occured");
		GetLastError();
		return;

	}
	int res = MultiByteToWideChar(CP_UTF8, 0, ansi, -1, NULL, 0);
	if (0 == res)
	{

		printf("some error occured");
		GetLastError();
		return;
	}
	printf_s("\n the required size of the buffer is %d\n", res);
	WCHAR* op;
		op = new WCHAR[res];
		ret = MultiByteToWideChar(CP_UTF8, 0, ansi, strlen(ansi), op, wcslen(op));
		if (0 == ret)
		{

			printf("some error occured");
			GetLastError();
			return;
		}
		printf_s("the ansi is converted to	WCHAR type \n");
		printf_s("\n the string converted is %ls", op);
		printf_s("\n the string converted is %S", op);
		printf_s("\n -----now converting the wchar to multibyte format");
		int x = WideCharToMultiByte(CP_UTF8, 0, wchar, -1, NULL, 0,NULL,NULL);
		if (0 == x)
		{

			printf("some error occured");
			GetLastError();
			return;
		}
		printf_s("\n the op of 1st ......... %d", x);
		CHAR * an = new CHAR[x];
		x = WideCharToMultiByte(CP_UTF8, 0, wchar, wcslen(wchar), an, strlen(an), NULL, NULL);
		if (0 == x)
		{

			printf("some error occured");
			GetLastError();
			return;
		}
		printf_s("\n the wchar is converted to	MULTIBYTE format \n");
		printf_s("\n the string converted is %s \n ", an);
		GetLastError();
		

		printf_s("\n");
	system("pause");

}