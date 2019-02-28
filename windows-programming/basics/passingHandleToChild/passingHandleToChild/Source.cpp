/*creating a process and pssing that handle to the child process*/
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1,si2;
	PROCESS_INFORMATION pi1,pi2;
	SECURITY_ATTRIBUTES sa;
	HANDLE hProc1, hProc2;
	if (argc != 2)
	{
		_tprintf(TEXT("no of argumnets passed are less"));
		_tprintf(TEXT("\n for more information refer error number %d"),GetLastError());
		getchar();
		return FALSE;
	}
	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));
	ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);
	ZeroMemory(&pi2, sizeof(pi2));
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if (!CreateProcess(NULL, argv[1], &sa, NULL, TRUE, 0, NULL, NULL, &si1, &pi1))
	{
		_tprintf(TEXT("process creation error"));
		_tprintf(TEXT("\n for more information refer error number %d"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(TEXT("the process id is %d \n"),pi1.dwProcessId);
	getchar();
	return TRUE;
}


 