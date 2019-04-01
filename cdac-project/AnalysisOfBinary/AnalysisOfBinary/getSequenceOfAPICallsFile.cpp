#include"HeaderFiles.h"
using namespace std;
extern multimap<int, string> sequenceOfCalls;
void getSequenceOfAPICalls()
{
	multimap <int, string> ::iterator itr;
	cout << "\nThe multimap gquiz1 is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = sequenceOfCalls.begin(); itr != sequenceOfCalls.end(); ++itr)
	{
		cout << '\t' << itr->first<< '\t' << itr->second << '\n';
	}
}