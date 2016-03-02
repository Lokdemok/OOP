#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> FindStringOccurrences(ifstream &inFile, const string &searchStr)
{
	string line;
	vector<int> numStr;
	int counterNumString = 0;
	while (getline(inFile, line))
	{
		++counterNumString;
		if (line.find(searchStr) != string::npos)
		{
			numStr.push_back(counterNumString);
		}
	}
	return numStr;
}

int main(int argc, char *argv[])
{
	bool textIsFound = false;
	if (argc != 3)
	{
		cout << "Not enough parameters. The correct command line format:\nfindtext.exe <file name> <text to search>" << "\n";
	}
	else
	{
		ifstream inputFile(argv[1]);
		string searchStr = argv[2];
		vector<int> foundLineNumbers;
		if (inputFile.is_open())
		{
			foundLineNumbers = FindStringOccurrences(inputFile, searchStr);
			if (!foundLineNumbers.empty())
			{
				textIsFound = true;
				copy(foundLineNumbers.begin(), foundLineNumbers.end(), ostream_iterator<int>(cout, "\n"));
				cout << endl;
			}
			else
			{
				cout << "Text not found" << "\n";
			}
		}
		else
		{
			cout << "Unable to open file " << argv[1] << "\n";
		}
	}
	if (textIsFound)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}