#include "stdafx.h"
#include "FindAndReplace.h"

using namespace std;

string FindAndReplace(const string & subject, const string & search, const string & replace)
{
	if (search.length() == 0 || search.length() > subject.length())
	{
		return subject;
	}
	string newString;
	size_t startPos = 0;
	size_t endPos = 0;
	while ((startPos= subject.find(search, startPos)) != string::npos)
	{
		newString += subject.substr(endPos, startPos - endPos);
		startPos += search.length();
		endPos = startPos;
		newString += replace;
	}
	newString += subject.substr(endPos);
	return newString;
}
