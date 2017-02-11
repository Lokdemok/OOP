#include "stdafx.h"
#include "FindAndReplace.h"
#include "string"
using namespace std;

string FindAndReplace(const string & subject, const string & search, const string & replace)
{
	if (search.length() == 0 || search.length() > subject.length())
	{
		return subject;
	}

	string newString;
	size_t startingPosition = 0;
	size_t endPosition = 0;
	while ((startingPosition = subject.find(search, startingPosition)) != string::npos)
	{
		newString.append(subject, endPosition, startingPosition - endPosition);
		newString += replace;
		startingPosition += search.length();
		endPosition = startingPosition;
	}
	newString.append(subject, endPosition);

	return newString;
}
