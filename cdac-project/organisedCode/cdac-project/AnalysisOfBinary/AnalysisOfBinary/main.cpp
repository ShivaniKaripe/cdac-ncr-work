#include"SystemCallsClass.h"
using namespace std;
void statistics();
void AnalyseAPI();
std::vector<SystemCalls> syscallData();
int main()
{
	int choice = 0;
	string name = "";
	while (true)
	{
		cout << "1.Statistics" << endl;
		cout << "2.Analyse File API" << endl;
		cout << "3.Exit" << endl;
		cout << "enter your choice";
		cin >> choice;

		switch (choice)
		{
		case 1:
			statistics();
			break;
		case 2:
			AnalyseAPI();
			break;
		case 3:
			exit(0);
		default:
			cout << "choose a valid option" << endl;
			break;
		}

	}

	system("pause");
}
