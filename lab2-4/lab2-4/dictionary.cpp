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
	cout << "Ќеизвестное слово У" << newWord << "Ф.¬ведите строку перевода или пустую строку дл€ отказа.\n";
	getline(cin, translation);
	if (!translation.empty())
	{
		dictionary[newWord] = translation;
		cout << "—лово У" << newWord << "Ф сохранено в словаре как У" << dictionary[newWord] << "Ф.\n";
		newWords.push_back(newWord);
	}
	else
	{
		cout << "—лово У" << newWord << "Ф проигнорировано.\n";
	}
}

void CDictionary::SaveNewWordsOnUserDemand(ofstream &outputFile)
{
	if (!newWords.empty())
	{
		string value;
		cout << "¬ словарь были внесены изменени€. ¬ведите Y или y дл€ сохранени€ перед выходом.\n";
		getline(cin, value);
		if (value == "Y" || value == "y")
		{
			for (auto word : newWords)
			{
				outputFile << word << '\n' << dictionary.at(word) << '\n';
			}
			cout << "»зменени€ сохранены. ƒо свидани€";
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