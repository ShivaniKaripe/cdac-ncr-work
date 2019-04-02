#include"Statistics.h"
void statistics()
{
	Statistics statObj("drstrace.singleLinkedList.exe.08560.0000.log");
	statObj.putSequenceOfCalls();
	int choice = 0;
	string name = "";
	while (true)
	{
		cout << "choose an option" << endl;
		cout << "1.Get sequence of API calls" << endl;
		cout << "2.count number of API calls" << endl;
		cout << "3.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			statObj.getSequenceOfAPICalls();
			break;
		case 2:
			int count;
			cout << "enter the api name" << endl;
			cin >> name;
			count = statObj.countAPI(name);
			cout << name << "   " << count << endl;
			break;
		case 3:
			return;
			break;
		default:
			cout << "choose a valid option" << endl;
			break;
		}
	}
}
