/*Write a program to create a child process with HIGH_PRIORITY_CLASS. 
Change the priority of child process to BELOW_NORMAL_PRIORITY_CLASS from within child process.
Also create a thread within the child process with THREAD_PRIORITY_LOWEST relative priority. 
Verify the results with Process Explorer from Sysinternals*/
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int _tmain(int argc,TCHAR *argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	 
	if (!CreateProcess(TEXT("C:/Users/cdac/Source/Repos/ShivaniKaripe/cdac-ncr-work/windows-programming/basics/Priority/child/Debug/child.exe"), (LPWSTR)(&pi.hProcess), NULL, NULL, TRUE, HIGH_PRIORITY_CLASS, NULL, NULL, &si, &pi))
	{

		printf(" \n process creation error");
		printf("\n the error number is: %d", GetLastError());
		getchar();
		return FALSE;
	}
	SetPriorityClass(pi.hProcess, BELOW_NORMAL_PRIORITY_CLASS);
	getchar();
	return 0;
}