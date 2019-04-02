#include "SystemCallsClass.h"
SystemCalls::SystemCalls()
{
	noOfArgs = 0;
}
SystemCalls::~SystemCalls()
{}
void SystemCalls::putAPIInfo(string APIname, int noOfArgs, int noOfArgsAfterSuc, char typeOfFile)
{
	this->APIname = APIname;
	this->noOfArgs = noOfArgs;
	this->noOfArgsAfterSuc = noOfArgsAfterSuc;
	this->typeOfFile = typeOfFile;
}
string SystemCalls::getAPIName()
{
	return APIname;
}
int SystemCalls::getNoOfArg()
{
	return noOfArgs;
}
int SystemCalls::getNoOfArgSuc()
{
	return noOfArgsAfterSuc;
}
char SystemCalls::getTypeOfFile()
{
	return typeOfFile;
}
