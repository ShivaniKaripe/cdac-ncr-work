#include "SystemCallsClass.h"
using namespace std;
std::vector<SystemCalls> syscallData()
{
	std::vector<SystemCalls> syscallList(20);

	syscallList[0].putAPIInfo("NtWriteFile", 9, 2, 'f');
	syscallList[1].putAPIInfo("NtCreateSemaphore", 5, 2, 'f');
	syscallList[2].putAPIInfo("NtClose", 1, 1, 'b');
	syscallList[3].putAPIInfo("NtQueryVirtualMemory", 6, 3, 'f');
	syscallList[4].putAPIInfo("NtQueryInformationProcess", 5, 3, 'p');
	syscallList[5].putAPIInfo("NtOpenProcessToken", 3, 2, 'f');
	syscallList[6].putAPIInfo("NtAllocateVirtualMemory", 6, 3, 'f');
	syscallList[7].putAPIInfo("NtQueryVolumeInformationFile.FileFsDeviceInformation", 5, 3, 'f');
	syscallList[8].putAPIInfo("NtOpenKey", 3, 2, 'f');
	syscallList[9].putAPIInfo("NtQueryValueKey", 6, 3, 'f');
	syscallList[10].putAPIInfo("NtOpenKey", 3, 2, 'f');
	syscallList[11].putAPIInfo("NtDeviceIoControlFile", 10, 3, 'f');
	syscallList[12].putAPIInfo("NtReadFile", 9, 3, 'f');
	syscallList[13].putAPIInfo("NtQueryInformationThread", 5, 3, 'p');
	syscallList[14].putAPIInfo("NtOpenSection", 3, 2, 'f');
	syscallList[15].putAPIInfo("NtMapViewOfSection", 10, 4, 'f');
	syscallList[16].putAPIInfo("NtProtectVirtualMemory", 5, 4, 'p');
	syscallList[17].putAPIInfo("NtQueryPerformanceCounter", 2, 3, 'f');
	syscallList[18].putAPIInfo("NtApphelpCacheControl", 2, 1, 'f');
	syscallList[19].putAPIInfo("NtOpenFile", 6, 3, 'f');
	return syscallList;
}
