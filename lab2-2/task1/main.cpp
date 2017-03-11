#include "stdafx.h"
#include <string>
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
	getline(cin, subject);
	cout << FindAndReplace(subject, argv[1], argv[2]) << endl;

	return 0;
}

