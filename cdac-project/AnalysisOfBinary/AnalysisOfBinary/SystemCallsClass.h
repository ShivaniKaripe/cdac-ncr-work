#pragma once
#include"HeaderFiles.h"
using namespace std;
class SystemCalls
{
		string APIname;
		int noOfArgs;
		int noOfArgsAfterSuc;
		char typeOfFile;
	public:
		SystemCalls();
		~SystemCalls();
		void putAPIInfo(string, int, int, char);
		string getAPIName();
		int getNoOfArg();
		int getNoOfArgSuc();
		char getTypeOfFile();
};

