#include"HeaderFiles.h"
using namespace std;
//the apis below are s
std::vector<sysCalls> syscallData()
{
	std::vector<sysCalls> syscallList(20);

	syscallList[0].put_data("NtWriteFile", 9, 2, 'f');
	syscallList[1].put_data("NtCreateSemaphore", 5, 2, 'f');
	syscallList[2].put_data("NtClose", 1, 1, 'b');
	syscallList[3].put_data("NtQueryVirtualMemory", 6, 3, 'f');
	syscallList[4].put_data("NtQueryInformationProcess", 5, 3, 'p');
	syscallList[5].put_data("NtOpenProcessToken", 3, 2, 'f');
	syscallList[6].put_data("NtAllocateVirtualMemory", 6, 3, 'f');
	syscallList[7].put_data("NtQueryVolumeInformationFile.FileFsDeviceInformation", 5, 3, 'f');
	syscallList[8].put_data("NtOpenKey", 3, 2, 'f');
	syscallList[9].put_data("NtQueryValueKey", 6, 3, 'f');
	syscallList[10].put_data("NtOpenKey", 3, 2, 'f');
	syscallList[11].put_data("NtDeviceIoControlFile", 10, 3, 'f');
	syscallList[12].put_data("NtReadFile", 9, 3, 'f');
	syscallList[13].put_data("NtQueryInformationThread", 5, 3, 'p');
	syscallList[14].put_data("NtOpenSection", 3, 2, 'f');
	syscallList[15].put_data("NtMapViewOfSection", 10, 4, 'f');
	syscallList[16].put_data("NtProtectVirtualMemory", 5, 4, 'p');
	syscallList[17].put_data("NtQueryPerformanceCounter", 2, 3, 'f');
	syscallList[18].put_data("NtApphelpCacheControl", 2, 1, 'f');
	syscallList[19].put_data("NtOpenFile", 6, 3, 'f');



	return syscallList;
}
 