/*Write a program to create a thread and print the reason for WaitForSingleObject return. Print results with.
a. timeout interval INFINITE 
b. timeout interval 1000
c. timeout interval 1000 with Sleep(2000) inside thread
*/

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<stdlib.h>
DWORD WINAPI thread_func1(LPVOID lpPar)
{
	for (int i = 0; i < 10; i++)
	{
		printf("\n 1.i=  %d \n", i);
		
	}
	return 0;
}
DWORD WINAPI thread_func2(LPVOID lpPar)
{
	for (int i = 0; i < 10; i++)
	{
		printf("2.i=  %d \n", i);
		Sleep(500);
	}
	return 0;
}
DWORD WINAPI thread_func3(LPVOID lpPar)
{
	Sleep(2000);
	for (int i = 0; i < 10; i++)
	{
		printf("3.i=  %d \n", i);
		Sleep(2000);
	}
	return 0;
}
int main()
{
	DWORD dwRet;
	DWORD thId1, thId2,thId3;
	HANDLE hTh1, hTh2,hTh3;
	HANDLE hArr[3];
	hTh1 = CreateThread(NULL, 0, thread_func1, NULL, 0, &thId1);
	hTh2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &thId2);
	hTh3 = CreateThread(NULL, 0, thread_func3, NULL, 0, &thId3);
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
	hArr[0] = hTh1;
	hArr[1] = hTh2;
	hArr[2] = hTh3;
	dwRet= WaitForSingleObject(hTh1,INFINITE);
	switch (dwRet)
	{
	case WAIT_OBJECT_0:
		printf("\n the thraed1 is terminated");
		break;
	case WAIT_TIMEOUT:
		printf("\n 1.timeout ");
		break;
	case WAIT_FAILED:
		printf("\n 1. wait failed");
		break;
	}
	dwRet = WaitForSingleObject(hTh2, 1000);
	switch (dwRet)
	{
	case WAIT_OBJECT_0:
		printf("\n the thraed2 is terminated");
		break;
	case WAIT_TIMEOUT:
		printf("\n 2.timeout ");
		break;
	case WAIT_FAILED:
		printf("\n 2.wait failed ");
		break;
	}
	dwRet = WaitForSingleObject(hTh3, 1000);
	switch (dwRet)
	{
	case WAIT_OBJECT_0:
		printf("\n the thraed3 is terminated");
		break;
	case WAIT_TIMEOUT:
		printf("\n 3.timeout ");
		break;
	case WAIT_FAILED:
		printf("\n 3.wait failed ");
		break;
	}
	CloseHandle(hTh1);
	CloseHandle(hTh2);
	CloseHandle(hTh3);
	getchar();
	return 0;
}