#include "stdafx.h"
#include "string"
#include "FindAndReplace.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Error arguments!" << endl;
		return 1;
	}

	cout << "Input string: ";
	string subject;
	string search = argv[1];
	string replace = argv[2];
	getline(cin, subject);
	cout << FindAndReplace(subject, search, replace) << endl;

	return 0;
}

