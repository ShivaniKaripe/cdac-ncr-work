/*Write a program to create two threads and print the reason for WaitForMultipleObjects return. Print results with.
bWaitAll = TRUE and timeout interval INFINITE
bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(4000) and thread2 Sleep(3000)  
bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(2000) and thread2 Sleep(3000)  
bWaitAll = FALSE and timeout interval 2000, thread1 Sleep(4000) and thread2 Sleep(3000)
*/
 

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<stdlib.h>
DWORD WINAPI thread_func1(LPVOID lpPar)
{
	printf("\n IN THREAD 1");
	return 0;
}
DWORD WINAPI thread_func2(LPVOID lpPar)
{
	printf("\n IN THREAD 2");
	return 0;
}
DWORD WINAPI thread_func3(LPVOID lpPar)
{
	printf("\n IN THREAD 3");
	Sleep(4000);
	return 0;
}
DWORD WINAPI thread_func4(LPVOID lpPar)
{
	printf("\n IN THREAD 4");
	Sleep(3000);
	return 0;
}
DWORD WINAPI thread_func5(LPVOID lpPar)
{
	printf("\n IN THREAD 5");
	Sleep(2000);
	return 0;
}
DWORD WINAPI thread_func6(LPVOID lpPar)
{
	printf("\n IN THREAD 6");
	Sleep(3000);
	return 0;
}
DWORD WINAPI thread_func7(LPVOID lpPar)
{
	printf("\n IN THREAD 7");
	Sleep(40000);
	return 0;
}
DWORD WINAPI thread_func8(LPVOID lpPar)
{
	printf("\n IN THREAD 8");
	Sleep(30000);
	return 0;
}
int main()
{
	DWORD dwRet;
	DWORD thId1, thId2, thId3, thId4, thId5, thId6, thId7, thId8;
	HANDLE hTh1, hTh2, hTh3,hTh4, hTh5, hTh6, hTh7, hTh8;
	HANDLE hArr1[2], hArr2[2], hArr3[2],hArr4[2];
	hTh1 = CreateThread(NULL, 0, thread_func1, NULL, 0, &thId1);
	hTh2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &thId2);
	hTh3 = CreateThread(NULL, 0, thread_func3, NULL, 0, &thId3);
	hTh4 = CreateThread(NULL, 0, thread_func4, NULL, 0, &thId4);
	hTh5 = CreateThread(NULL, 0, thread_func5, NULL, 0, &thId5);
	hTh6 = CreateThread(NULL, 0, thread_func6, NULL, 0, &thId6);
	hTh7 = CreateThread(NULL, 0, thread_func7, NULL, 0, &thId7);
	hTh8 = CreateThread(NULL, 0, thread_func8, NULL, 0, &thId8);
	if (NULL == hTh1)
	{
		printf("unable to create the thread");
		getchar();
		return FALSE;
	}
	if (NULL == hTh2)
	{
		printf("unable to create the thread");
		getchar();
		return FALSE;
	}
	if (NULL == hTh3)
	{
		printf("unable to create the thread");
		getchar();
		return FALSE;
	}
	if (NULL == hTh4)
	{
		printf("unable to create the thread");
		getchar();
		return FALSE;
	}
	if (NULL == hTh5)
	{
		printf("unable to create the thread");
		getchar();
		return FALSE;
	}
	if (NULL == hTh6)
	{
		printf("unable to create the thread");
		getchar();
		return FALSE;
	}
	if (NULL == hTh7)
	{
		printf("unable to create the thread");
		getchar();
		return FALSE;
	}
	if (NULL == hTh8)
	{
		printf("unable to create the thread");
		getchar();
		return FALSE;
	}
	 
	hArr1[0] = hTh1;
	hArr1[1] = hTh2;
	hArr2[0] = hTh3;
	hArr2[1] = hTh4;
	hArr3[0] = hTh5;
	hArr3[1] = hTh6;
	hArr4[0] = hTh7;
	hArr4[1] = hTh8;
	dwRet = WaitForMultipleObjects(2, hArr1, TRUE, INFINITE);
	switch (dwRet)
	{
	case WAIT_FAILED:
		printf("\n wait failed ");
		break;
	case WAIT_TIMEOUT:
		printf("\n timeout ");
		break;
	case WAIT_OBJECT_0 + 0:
		printf("\n the thraed1 is terminated");
		break;
	case WAIT_OBJECT_0 + 1:
		printf("\n the thraed1 is terminated");
		break;
	
	}
	printf("\n entering into scenario 2");
	dwRet = WaitForMultipleObjects(2, hArr2, FALSE, INFINITE);
	switch (dwRet)
	{
	case WAIT_FAILED:
		printf("\n wait failed ");
		break;
	case WAIT_TIMEOUT:
		printf("\n timeout ");
		break;
	
	case WAIT_OBJECT_0 + 0:
		printf("\n the thraed3 is terminated");
		break;
	case WAIT_OBJECT_0 + 1:
		printf("\n the thraed4 is terminated");
		break;
	}
	printf("\n entering into scenario 3");
	dwRet = WaitForMultipleObjects(2, hArr3, FALSE, INFINITE);
	switch (dwRet)
	{
	case WAIT_FAILED:
		printf("\n wait failed ");
		break;
	case WAIT_TIMEOUT:
		printf("\n timeout ");
		break;
	
	case WAIT_OBJECT_0 + 0:
		printf("\n the thraed5 is terminated");
		break;
	case WAIT_OBJECT_0 + 1:
		printf("\n the thraed6 is terminated");
		break;
	}
	printf("\n entering into scenario 4");
	dwRet = WaitForMultipleObjects(2, hArr4, FALSE, 2000);
	switch (dwRet)
	{
	case WAIT_FAILED:
		printf("\n wait failed ");
		break;
	case WAIT_TIMEOUT:
		printf("\n timeout ");
		break;
	case WAIT_OBJECT_0 + 0:
		printf("\n the thraed7 is terminated");
		break;
	case WAIT_OBJECT_0 + 1:
		printf("\n the thraed8 is terminated");
		break;
	}
	CloseHandle(hTh1);
	CloseHandle(hTh2);
	CloseHandle(hTh3);
	CloseHandle(hTh4);
	CloseHandle(hTh5);
	CloseHandle(hTh6);
	CloseHandle(hTh7);
	CloseHandle(hTh8);
	getchar();
	return 0;
}