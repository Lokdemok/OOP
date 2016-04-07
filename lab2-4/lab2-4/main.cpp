#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "dictionary.h"

using namespace std;

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
		cout << "Для перевода введите слово на английском. Для выхода введите '...'\n";
		ofstream outputFile;
		outputFile.open(argv[1], ios::app);
		getline(cin, inputWord);
		while (inputWord != "...")
		{
			if (dictionary.IsKnowWord(inputWord))
			{
				dictionary.PrintTranslation(inputWord);
			}
			else if (!inputWord.empty())
			{
				dictionary.SaveTranslationForNewWordOnUserDemand(inputWord);
			}
			getline(cin, inputWord);
		}
		dictionary.SaveNewWordsOnUserDemand(outputFile);
	}
	return 0;

}
