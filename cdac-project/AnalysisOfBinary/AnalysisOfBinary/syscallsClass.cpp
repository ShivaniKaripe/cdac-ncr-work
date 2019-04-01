#include<string>
using namespace std;
 class sysCalls
{

	string name;
	int noOfArg;
	int noOfArgSuc;
	char typeOfAPI;
public:
	sysCalls()
	{
		name = "";
		noOfArg = 0;
		noOfArgSuc = 0;
		typeOfAPI = ' ';
	}
	void put_data(string sysname, int n, int noa, char type)
	{
		name = sysname;
		noOfArg = n;
		noOfArgSuc = noa;
		typeOfAPI = type;

	}
	/*void get_data()
	{
		cout << name << " ";
		cout << noOfArg << " ";
		cout << noOfArgSuc << " ";
		cout << typeOfAPI << endl;
	}*/
	string getAPIName()
	{
		return name;
	}
	int getNoOfArguments()
	{
		return noOfArg;
	}
	int getNoOfArgsOnSuccess()
	{
		return noOfArgSuc;
	}
	char getAPIType()
	{
		return typeOfAPI;
	}
};
