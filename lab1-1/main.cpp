#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void findNumberString(ifstream &inFile, string searchStr, vector<int> &numStr)
{
	string stringFile;
	int counterNumString = 0;
	while (getline(inFile, stringFile))
	{
		++counterNumString;
		if (stringFile.find(searchStr) != string::npos)
		{
			numStr.push_back(counterNumString);
		}
	}
}

int main(int argc, char *argv[])
{
	ifstream inputFile(argv[1]);
	string searchStr = argv[2];
	vector<int> numFindStr;
	bool isFindText = false;
	if (argc != 3) {
		cout << "\nNot enough parameters. The correct command line format:\nfindtext.exe <file name><text to search>"<< "\n";
	}
	else
	{

		if (inputFile.is_open())
		{
			findNumberString(inputFile, searchStr, numFindStr);
			if (numFindStr.empty() != true)
			{
				isFindText = true;
				for (int i = 0; i < (int)numFindStr.size(); ++i)
				{
					printf("%d\n", numFindStr[i]);
				}
			}
			else
			{
				cout << "Textnotfound" << "\n";
			}
		}
		else
		{
			cout << "Unable to open file " << argv[1] << "\n";
		}
	}
	system("pause");
	if (isFindText)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}