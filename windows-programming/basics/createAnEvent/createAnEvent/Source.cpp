/*create an event program*/
#include<stdio.h>
#include<Windows.h>
int main()
{
	HANDLE hEvent = CreateEvent(NULL,
		FALSE,
		FALSE,
		TEXT("dummyevent"));
	getchar();
	return 0;
}