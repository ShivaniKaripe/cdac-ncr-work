/* Write a program to create a secondary thread and wait in the process’s
primary thread for the secondary thread to return using WaitForSingleObject.
Terminate the secondary thread using TerminateThread API from within process’s primary thread. 
Print the exit code of the secondary thread using GetExitCodeThread API in process’s primary thread.
*/
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

DWORD WINAPI thread_func2(LPVOID lpPar)
{
	printf(" the control entered into second thread");
	 
	Sleep(8000);
	return 0;
}
DWORD WINAPI thread_func1(LPVOID lpPar)
{
	printf("control entered into first thread");
	 
	DWORD  dwThId2;
	HANDLE  hThread2;

	DWORD exitCode;
	hThread2 = CreateThread(NULL, 0, thread_func2, NULL, CREATE_SUSPENDED, &dwThId2);
	ResumeThread(hThread2);
	
	//WaitForSingleObject(hThread2, INFINITE);
	Sleep(2000);

	TerminateThread(hThread2, 2);
	
	Sleep(2000);
	GetExitCodeThread(hThread2, &exitCode);

	printf("the exit code of the second thread is %d\n\n", exitCode);
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