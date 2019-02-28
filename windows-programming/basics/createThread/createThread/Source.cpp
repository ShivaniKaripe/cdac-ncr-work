/*Write a program to create a thread via CreateThread API. Print some msg in the thread function.*/
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<stdlib.h>
DWORD WINAPI thread_func(LPVOID lpPar)
{
	for (int i = 0; i < 10; i++)
	{
		printf("i=  %d \n", i);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD thId1,thId2;
	HANDLE hTh1,hTh2;
	HANDLE hArr[2];
	hTh1 = CreateThread(NULL, 0, thread_func, NULL, 0, &thId1);
	hTh2 = CreateThread(NULL, 0, thread_func, NULL, 0, &thId2);
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
	hArr[0] = hTh1;
	hArr[1] = hTh2;
	WaitForMultipleObjects(2, hArr, TRUE, INFINITE);
	CloseHandle(hTh1);
	CloseHandle(hTh2);
}