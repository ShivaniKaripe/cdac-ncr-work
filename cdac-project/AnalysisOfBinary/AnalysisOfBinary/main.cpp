#include"HeaderFiles.h"
using namespace std;
void ResultParser();
void getSequenceOfAPICalls();
void putSequenceOfCalls();
int countAPI(string );
std::vector<sysCalls> syscallData();
std::vector<sysCalls> syscallData();
multimap<int, string> sequenceOfCalls;
int main()
{
	int choice = 0;
	string name = "";
	while (true)
	{
		cout << "1.result parser" << endl;
		cout << "2.sequence of APIcalls" << endl;
		cout << "3.count an api occurences" << endl;
		cout << "4.exit" << endl;
		cout << "enter your choice";
		cin >> choice;

		switch (choice)
		{
		case 1:
			ResultParser();
			break;
		case 2:
			putSequenceOfCalls();
			getSequenceOfAPICalls();
			break;
		case 3:
			cout << "enter the api name" << endl;
			cin >> name;
			countAPI(name);
			break;
		case 4:
			exit(0);
		default:
			cout << "choose a valid option" << endl;
			break;
		}

	}
	 
	system("pause");
}