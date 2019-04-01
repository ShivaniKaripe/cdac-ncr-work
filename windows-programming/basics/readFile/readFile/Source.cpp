using namespace std;
#include<iostream>
#include<fstream> 
#include<string>
// driver code 
int main()
{
	// filestream variable file 
	ifstream file;
	string line, t, q, filename;

	// filename of the file 
	filename = "drstrace.Complex.exe.04708.0000.log";

	// opening file 
	file.open(filename.c_str());
	 
	// extracting words form the file 
	while (!file.eof())
	{
		getline(file, line);
		cout << line << endl;
	}
	getchar();
	return 0;
}