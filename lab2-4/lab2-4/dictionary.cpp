#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

map<string, string> CDictionary::FillDictionary(ifstream &inFile)
{
	string word;
	string translation;
	while (!inFile.eof())
	{
		getline(inFile, word);
		getline(inFile, translation);
		if (!word.empty())
		{
			dictionary.emplace(word, translation);
		}
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