/*this is the child process where the thraed is created*/
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
DWORD WINAPI thread_func(LPVOID lppar)
{
	printf("entered into the thraed");
	return 0;
}
int main()
{
	DWORD dwThId;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, thread_func,NULL, 0 , &dwThId);
	SetThreadPriority(hThread, THREAD_PRIORITY_LOWEST);
	if (NULL == hThread)
	{
		printf("Thread creation error");
		printf("\n the error number is: %d", GetLastError());
		getchar();
		return FALSE;
	}
	WaitForSingleObject(hThread, INFINITE);
	getchar();
	return 0;
}