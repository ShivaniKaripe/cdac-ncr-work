/*command line arguments programs*/
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<shellapi.h>
int main()
{
	LPWSTR *argList;
	int nArgs;
	int i;
	
	argList = CommandLineToArgvW(GetCommandLine(), &nArgs);
	
	if (NULL == argList)
	{
		wprintf(L"no arguments passed");
		system("pause");
		return -1;
	}
	else
	{
		for (i = 0; i < nArgs; i++)
		{
			printf_s("%d :  %ws \n", i, argList[i]);
			
		}
		system("pause");
		return 0;
	}
}