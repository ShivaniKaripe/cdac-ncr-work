/*Write a program to modify shared variable between two threads
guarded by critical section. Use InitializeCriticalSection or 
InitializeCriticalSectionAndSpinCount, DeleteCriticalSection, EnterCriticalSection,
LeaveCriticalSection. Wait for both the threads to exit before exiting process primary thread.
*/
#include <windows.h>
#include <process.h>
#include <stdio.h>

CRITICAL_SECTION cs;
long int a = 0;
DWORD WINAPI thread_func1(LPVOID lppar)
{
	EnterCriticalSection(&cs);
	a++;
	Sleep(1000);
	LeaveCriticalSection(&cs);
	return 0;
}
DWORD WINAPI thread_func2(LPVOID lppar)
{
	EnterCriticalSection(&cs);
	a++;
	Sleep(1000);
	LeaveCriticalSection(&cs);
	return 0;
}
int main()

{
	HANDLE hThread1, hThread2;
	DWORD dwThId1, dwThId2;
	HANDLE hArray[2];
	InitializeCriticalSection(&cs);
	hThread1 = CreateThread(NULL, 0, thread_func1, NULL, 0, &dwThId1);
	if (NULL == hThread1)
	{
		printf("\n the thread1 creation error ");
		printf("\n for more information look into error look up");
		printf("the error number %d", GetLastError());
		getchar();
		return 0;
	}
	hThread2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &dwThId2);
	if (NULL == hThread2)
	{
		printf("\n the thread2 creation error ");
		printf("\n for more information look into error look up");
		printf("the error number %d", GetLastError());
		getchar();
		return 0;
	}
	hArray[0] = hThread1;
	hArray[1] = hThread2;
	WaitForMultipleObjects(2, hArray, TRUE, INFINITE);
	printf("\n aftre the two threads done their job the value of the global variblae is %d", a);
	DeleteCriticalSection(&cs);
	getchar();
	return 0;
}

 