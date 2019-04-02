#include "Statistics.h"
multimap<int, string> sequenceOfCalls;


Statistics::Statistics()
{
}
Statistics::~Statistics()
{
}
Statistics::Statistics(string pathName)
{
	this->pathName = pathName;
}
void Statistics::putSequenceOfCalls()
{
	int sequenceNo = 0;
	string systemCall;
	ifstream logFile(pathName);
	if (logFile.is_open())
	{
		while (getline(logFile, systemCall))
		{
			if (systemCall[0] == 'N'&&systemCall[1] == 't')
			{
				sequenceOfCalls.insert(pair<int, string>(++sequenceNo, systemCall));
			}
		}
		logFile.close();
	}
	else
	{
		cout << "Unable to open file";
	}
}
void Statistics::getSequenceOfAPICalls()
{
	multimap <int, string> ::iterator itr;
	cout << "\nThe multimap gquiz1 is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = sequenceOfCalls.begin(); itr != sequenceOfCalls.end(); ++itr)
	{
		cout << '\t' << itr->first << '\t' << itr->second << '\n';
	}
}
int Statistics::countAPI(string inputAPI)
{
	int count = 0;
	multimap<int, string>::iterator it;
	it = sequenceOfCalls.begin();

	while (it != sequenceOfCalls.end())
	{
		if (it->second == inputAPI)
		{
			count++;
		}
		*it++;
	}
	cout << "count of calls" << count << endl;
	return count;
}
