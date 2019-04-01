/////*reading a file*/
////#define bufferSize 1000
////#include<stdio.h>
////#include<Windows.h>
////#include<tchar.h>
////int _tmain(int argc, LPTSTR argv[])
////{
////	HANDLE hFile;
////	TCHAR buffer[bufferSize];
////	 
////	hFile = CreateFile(TEXT("C:/Users/Friends/source/repos/ShivaniKaripe/cdac-ncr-work/windows-programming/basics/readFile/readFile/drstrace.Complex.exe.04708.0000.log"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
////	if ( INVALID_HANDLE_VALUE == hFile)
////	{
////		_tprintf(_T("cannot open the file error number:%d"), GetLastError());
////		_tprintf(_T("for more info refer ERROR LOOKUP"));
////		getchar();
////		return FALSE;
////	}
////	_tprintf(_T("file opened  successfully"));
////	DWORD dwNbr;
////	ZeroMemory(buffer, bufferSize);
////	
////	BOOL ret = ReadFile(hFile, buffer, bufferSize, &dwNbr, NULL);
////	if (0 == ret)
////	{
////		_tprintf(_T("cannot read the file error number:%d"), GetLastError());
////		_tprintf(_T("for more info refer ERROR LOOKUP"));
////		getchar();
////		return FALSE;
////	}
////	CloseHandle(hFile);
////	_tprintf(_T("text from the file [%s] is ....: \n %S"), argv[1], buffer);
////
////	getchar();
////	return TRUE;
////}