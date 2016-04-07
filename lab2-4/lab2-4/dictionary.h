#pragma once
#include <vector>
#include <map>


using namespace std;

class CDictionary
{
public:
	void SaveNewWordsOnUserDemand(ofstream &outputFile);
	void SaveTranslationForNewWordOnUserDemand(const string & newWord);
	map<string, string> FillDictionary(ifstream &inFile);
	bool IsKnowWord(const string & inputWord);
	void PrintTranslation(const string & word);
private:
	map<string, string> dictionary;
	vector <string> newWords;
};