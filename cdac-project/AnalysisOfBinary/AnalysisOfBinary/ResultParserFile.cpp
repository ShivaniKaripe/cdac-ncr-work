/*result parser function defination*/
#include"HeaderFiles.h"
using namespace std;
std::vector<sysCalls> syscallData();
extern multimap<int, string> sequenceOfCalls;
 void ResultParser()
{
	string arg1, arg2, returnValue;
	int skip;
	int sequenceNo = 0;
	string systemCall;
	ifstream myfile("drstrace.singleLinkedList.exe.08560.0000.log");
	if (myfile.is_open())
	{
		while (getline(myfile, systemCall))
		{
			if (systemCall[0] == 'N'&&systemCall[1] == 't')
			{
				sequenceOfCalls.insert(pair<int, string>(++sequenceNo, systemCall));
				std::vector<sysCalls> syscallsList = syscallData();
				for (auto i = syscallsList.begin(); i != syscallsList.end(); ++i)
				{
					if (systemCall == i->getAPIName())
					{
						getline(myfile, arg1);
						getline(myfile, arg2);
						skip = i->getNoOfArgsOnSuccess() + i->getNoOfArguments() - 2;
						for (int i = 0; i < skip; i++)
							getline(myfile, returnValue);
						getline(myfile, returnValue);
						if (systemCall == "NtWriteFile")
						{
							//NtWriteFileParse(arg1,arg2,returnValue);
 						}
						else if(systemCall == "NtReadFile")
						{
							//NtReadFile(arg1,arg2,returnValue);
						}
						else if (systemCall == "NtCreateFile")
						{
							//NtCreateFile(arg1,arg2,returnValue);
						}
						else if (systemCall == "NtOpenFile")
						{
							//NtOpenFile(arg1,arg2,returnValue);
						}
					}
				}
			}
		}
		myfile.close();
	}

	else
		cout << "Unable to open file";
	 
	return ;
}