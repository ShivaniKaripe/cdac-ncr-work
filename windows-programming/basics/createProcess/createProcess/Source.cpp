/*create process */
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
int _tmain(int argc,TCHAR *argv[],TCHAR *env[])
{
	STARTUPINFO si1,si2;
	PROCESS_INFORMATION pi1,pi2;
	//HANDLE hProcess;
	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));
	ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);
	ZeroMemory(&pi2, sizeof(pi2));
	if (argc != 3)
	{
		printf("no of arguments are not enough");
		printf("\n the error number is: %d", GetLastError());
		getchar();
		return FALSE;
	}
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1))
	{
		printf("process1 creation error");
		printf("\n the error number is: %d", GetLastError());
		getchar();
		return FALSE;

	}
	printf_s("Handle of the process is %d \n ", pi1.hProcess);
	printf_s("process ID of the process is %d \n ", pi1.dwProcessId);
	DWORD dwRet = WaitForSingleObject(pi1.hProcess, INFINITE);
	printf_s("wait for single object output %d \n", dwRet);
	 
	if (!CreateProcess(NULL, argv[2], NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2))
	{
		printf("process1 creation error");
		printf("\n the error number is: %d", GetLastError());
		getchar();
		return FALSE;

	}
	printf_s("Handle of the process is %d \n ", pi2.hProcess);
	printf_s("process ID of the process is %d \n ", pi2.dwProcessId);
	dwRet = WaitForSingleObject(pi2.hProcess, INFINITE);
	printf_s("wait for single object output %d \n", dwRet);
	getchar();
	return TRUE;
}