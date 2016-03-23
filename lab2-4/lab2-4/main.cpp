#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <windows.h>



using namespace std;

map<string, string> FillDictionary(ifstream &inFile)
{
	string key;
	string value;
	map<string, string> dictionary;
	while (!inFile.eof())
	{
		getline(inFile, key, '\n');
		getline(inFile, value, '\n');
		dictionary.insert(pair<string, string>(key, value));
	}
	inFile.close();
	return dictionary;
}


void FinishProgramm(vector <string> &keys, map<string, string> &dictionary, ofstream &outputFile)
{
	string value;
	cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";
	cin.ignore();
	getline(cin, value, '\n');
	if (value == "Y" || value == "y")
	{
		for (int i = 0; i < keys.size(); i++)
		{
			outputFile << keys[i] << '\n' << dictionary[keys[i]] << '\n';
		}
		cout << "��������� ���������. �� ��������";
	}
}

int main(int argc, char *argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	if (argc != 2)
	{
		cout << "Not enough parameters. The correct command line format:\ndictionary.exe <file name>" << "\n";
		return 1;
	}
	else
	{
		ifstream inputFile(argv[1]);
		string key;
		string value;
		vector <string> newKeys;
		map<string, string> dictionary;
		if (inputFile.is_open())
		{
			dictionary = FillDictionary(inputFile);
		}
		ofstream outputFile;
		outputFile.open(argv[1], ios::app);
		cin >> key;
		while (key != "...")
		{
			if (dictionary.count(key))
			{
				cout << dictionary[key] << "\n";
			}
			else
			{
				cout << "����������� ����� �" << key << "�.������� ������ �������� ��� ������ ������ ��� ������.\n";
				cin.ignore();
				getline(cin, value, '\n');
				if (!value.empty())
				{
					dictionary[key] = value;
					cout << "����� �" << key << "� ��������� � ������� ��� �" << dictionary[key] << "�.\n";
					newKeys.push_back(key);
				}
				else
				{
					cout << "����� �" << key << "� ���������������.\n";
				}

			}
			cin >> key;
		}
		if (!newKeys.empty())
		{
			FinishProgramm(newKeys, dictionary, outputFile);
		}
	}
	return 0;

}