#include"HeaderFiles.h"
std::vector<sysCalls> syscallData();
extern multimap<int, string> sequenceOfCalls;
using namespace std;
void putSequenceOfCalls()
{
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
			 
		}
	}
	myfile.close();
}

else
{
	cout << "Unable to open file";
}
}