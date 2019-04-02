#pragma once
#include"HeaderFiles.h"
using namespace std;
class Statistics
{
	string pathName;
public:
	Statistics();
	~Statistics();
	Statistics(string path);
	void putSequenceOfCalls();
	void getSequenceOfAPICalls();
	int countAPI(string);
};

