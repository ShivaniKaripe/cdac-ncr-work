#include"HeaderFiles.h"
using namespace std;
extern multimap<int, string> sequenceOfCalls;
int countAPI(string inputAPI)
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