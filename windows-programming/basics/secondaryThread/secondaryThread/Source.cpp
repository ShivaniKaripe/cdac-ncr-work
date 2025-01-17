/*Write a program to create a secondary thread and wait in the processís primary
thread for the secondary thread to return using WaitForSingleObject.
Terminate secondary thread by using ExitThread API from within secondary thread.
Print the exit code of the secondary thread using GetExitCodeThread API in processís primary thread.
*/
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<iostream>
DWORD WINAPI thread_func2(LPVOID lpPar)
{
	printf("entred the control into second thread");
	getchar();
	ExitThread(10);
	return 0;
}
DWORD WINAPI thread_func1(LPVOID lpPar)
{
	printf("control entered into first thread");
	getchar();
	DWORD  dwThId2;
	HANDLE  hThread2;

	DWORD exitCode;
	hThread2 = CreateThread(NULL, 0, thread_func2, NULL, CREATE_SUSPENDED, &dwThId2);
	ResumeThread(hThread2);
	WaitForSingleObject(hThread2, INFINITE);
	GetExitCodeThread(hThread2, &exitCode);

	printf("the exit code of the second thread is %d", exitCode);
	return 0;
}

int main()
{
	DWORD dwThId1;
	HANDLE hThread1;
	//HANDLE hDummy1 ;
	hThread1 = CreateThread(NULL, 0, thread_func1, NULL, CREATE_SUSPENDED, &dwThId1);

	ResumeThread(hThread1);

	WaitForSingleObject(hThread1, INFINITE);

	getchar();
	return 0;
}