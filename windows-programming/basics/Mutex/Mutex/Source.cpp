/*Write a program where 8 threads execute to get exclusive access to shared data via mutex.
Make sure mutex object is initially not owned. Use the shared resource for 1 sec with Sleep(1000). 
Use WaitForSingleObject to get the ownership of mutex in threads.
*/
#include<Windows.h>
#include<stdio.h>

#define THREAD_COUNT 8
HANDLE ghMutex;
DWORD WINAPI ThreadProc(LPVOID);
int main()
{
	HANDLE aThread[THREAD_COUNT];
	DWORD dwThID;

	ghMutex = CreateMutex(NULL, FALSE, NULL);
	if (NULL == ghMutex)
	{
		printf("\n Mutex creation error %d", GetLastError());
		getchar();
		return FALSE;
	}
	for (int i = 0; i < THREAD_COUNT; i++)
	{
		aThread[i] = CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwThID);
		if (NULL == aThread[i])
		{
			printf("\n thread %d creation error %d", i, GetLastError());
			getchar();
			return FALSE;
		}
	}
	WaitForMultipleObjects(THREAD_COUNT, aThread, TRUE, INFINITE);
	for (int i = 0; i < THREAD_COUNT; i++)
	{
		CloseHandle(aThread[i]);
	}
	CloseHandle(ghMutex);
	getchar();
	return 0;
}
DWORD WINAPI ThreadProc(LPVOID lppar)
{
	UNREFERENCED_PARAMETER(lppar);
	DWORD dwRes,dwCount=0;
	while (dwCount<5)
	{
		dwRes = WaitForSingleObject(ghMutex, INFINITE);
		switch (dwRes)
		{
		case WAIT_OBJECT_0:
			printf("\n the thread %d wait is sucessful", GetCurrentThreadId());
			dwCount++;
			Sleep(1000);
			if (!ReleaseMutex(ghMutex))
			{
				printf("\n release mutex error");

			}
			break;
		case WAIT_ABANDONED:
			printf("\n thread %d wait timeout ", GetCurrentThreadId());
			return FALSE;
			break;

		}
	}
	return TRUE;
}