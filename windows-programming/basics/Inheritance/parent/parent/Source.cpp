/*It is the parent process which creates the file and passes that handle to the child process*/
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	HANDLE hFile;
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	if (argc != 2)
	{
		_tprintf(_T("less number of arguments to main function \n sample argumnets: filename.exe filename"));
		getchar();
		return FALSE;
	}
	struct _SECURITY_ATTRIBUTES secAtt;
	secAtt.nLength = 0;
	secAtt.lpSecurityDescriptor = NULL;
	secAtt.bInheritHandle = TRUE;
	hFile = CreateFile(argv[1], GENERIC_ALL, 0, &secAtt, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		_tprintf(_T("cannot open the file error number:%d"), GetLastError());
		_tprintf(_T("for more info refer ERROR LOOKUP"));
		getchar();
		return FALSE;
	}
	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	if (!CreateProcess(_TEXT("C:/Users/cdac/Source/Repos/ShivaniKaripe/cdac-ncr-work/windows-programming/basics/Inheritance/Child/Debug/child.exe"), (LPTSTR)&hFile, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		_tprintf(_T("cannot create process error number:%d"), GetLastError());
		_tprintf(_T("for more info refer ERROR LOOKUP"));
		getchar();
		return FALSE;
	}
	printf("\n process created succesfully");
	getchar();
	return 0;
}