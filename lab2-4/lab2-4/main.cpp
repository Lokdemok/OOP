#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <windows.h>



using namespace std;

class CDictionary
{
public:
	void SaveNewWordsOnUserDemand(ofstream &outputFile);
	void SaveTranslationForNewWordOnUserDemand(const string & newWord);
	map<string, string> FillDictionary(ifstream &inFile);
	bool IsKnowWord(const string & inputWord);
	void PrintTranslation(const string & word);
	vector <string> newWords;
	map<string, string> dictionary;
};

map<string, string> CDictionary::FillDictionary(ifstream &inFile)
{
	string key;
	string value;
	while (!inFile.eof())
	{
		getline(inFile, key);
		getline(inFile, value);
		dictionary.emplace(key, value);
	}
	inFile.close();
	return dictionary;
}

void CDictionary::SaveTranslationForNewWordOnUserDemand(const string & newWord)
{
	string translation;
	cout << "����������� ����� �" << newWord << "�.������� ������ �������� ��� ������ ������ ��� ������.\n";
	getline(cin, translation);
	if (!translation.empty())
	{
		dictionary[newWord] = translation;
		cout << "����� �" << newWord << "� ��������� � ������� ��� �" << dictionary[newWord] << "�.\n";
		newWords.push_back(newWord);
	}
	else
	{
		cout << "����� �" << newWord << "� ���������������.\n";
	}
}

void CDictionary::SaveNewWordsOnUserDemand(ofstream &outputFile)
{
	if (!newWords.empty())
	{
		string value;
		cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";
		getline(cin, value);
		if (value == "Y" || value == "y")
		{
			for (auto word : newWords)
			{
				outputFile << word << '\n' << dictionary.at(word) << '\n';
			}
			cout << "��������� ���������. �� ��������";
		}
	}
}

bool CDictionary::IsKnowWord(const string & inputWord)
{
	if (dictionary.count(inputWord))
		return true;
	else
		return false;
}

void CDictionary::PrintTranslation(const string & word)
{
	cout << dictionary.at(word) << "\n";
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
		string inputWord;
		CDictionary dictionary;
		if (inputFile.is_open())
		{
			dictionary.FillDictionary(inputFile);
		}
		cout << "��� �������� ������� ����� �� ����������. ��� ������ ������� '...'\n";
		ofstream outputFile;
		outputFile.open(argv[1], ios::app);
		getline(cin, inputWord);
		while (inputWord != "...")
		{
			if (dictionary.IsKnowWord(inputWord))
			{
				dictionary.PrintTranslation(inputWord);
			}
			else
			{
				dictionary.SaveTranslationForNewWordOnUserDemand(inputWord);
			}
			getline(cin, inputWord);
		}
		dictionary.SaveNewWordsOnUserDemand(outputFile);
	}
	return 0;

}