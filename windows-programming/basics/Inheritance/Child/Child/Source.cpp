/*this is a child which takes the handle from the parent and writes into the file*/
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	printf("\n In child process");
	HANDLE hFile = (HANDLE)*argv[0];
	TCHAR buffer[] = TEXT("Hi the control is in child process");
	DWORD nbw;
	BOOL ret = WriteFile(hFile, buffer, sizeof(buffer), &nbw, NULL);
	if (ret == 0)
	{
		printf("cannot write into the file");
		getchar();
		return FALSE;
	}
	printf("written succesfully");
	system("pause");
	return 0;
}