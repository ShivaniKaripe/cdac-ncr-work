/*Write a program to create a thread in suspended state. Resume the thread after 5 seconds wait. 
The thread should print integers from 1 to 1000 and return normally. 
Use getchar() in process’s primary thread to wait for user input and allow time for thread to return.
*/
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
DWORD WINAPI thread_func(LPVOID threadPar)
{
	for (int i = 1; i <= 1000; i++)
	{
		printf("the value of i is:: %d \n", i);

	}
	return 0;
}
int _tmain()
{
	DWORD dwThId;
	HANDLE hThread;
	HANDLE hDummy;
	hThread = CreateThread(NULL, 0, thread_func, NULL, CREATE_SUSPENDED, &dwThId);
	Sleep(5000);
	ResumeThread(hThread);
	hDummy = hThread;
	WaitForMultipleObjects(1, &hDummy, TRUE, INFINITE);
	CloseHandle(hThread);
	getchar();
	return 0;
}