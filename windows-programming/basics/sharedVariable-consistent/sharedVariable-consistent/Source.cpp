/*Write a program to increment a shared integer via Interlocked* 
functions by two threads of the same process. Print the final value of shared integer. 
Verify if final value of shared integer is inconsistent.
*/
 
#include<stdio.h>
#include<Windows.h>
long g_x = 0;
DWORD WINAPI thread_func1(LPVOID lpPar)
{
	InterlockedAdd(&g_x, 1);
	printf("control entered into thread1 \n");
	return 0;
}
DWORD WINAPI thread_func2(LPVOID lpPar)
{
	InterlockedAdd(&g_x, 1);
	printf("control entered into thread2 \n");
	return 0;
}
int main()
{
	HANDLE hThread1, hThread2;
	DWORD dw1, dw2;
	HANDLE harr[2];
	hThread1 = CreateThread(NULL, 0, thread_func1, NULL, 0, &dw1);
	hThread2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &dw1);
	if (hThread1 == NULL)
	{
		printf("cannot create the thread 1 \n");
		printf("for more information look into error lookup error number %d \n", GetLastError());
		getchar();
		return 0;
	}
	if (hThread2 == NULL)
	{
		printf("cannot create the thread 2 \n");
		printf("for more information look into error lookup error number %d", GetLastError());
		getchar();
		return 0;
	}
	harr[0] = hThread1;
	harr[1] = hThread2;
	WaitForMultipleObjects(2, harr, TRUE, INFINITE);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	printf("the value of the global variables %d", g_x);
	getchar();
	return 0;
}