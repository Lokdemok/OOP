#include "stdafx.h"
#include "FindAndReplace.h"

using namespace std;

namespace
{
	const int NUMBER_OF_ARGUMENTS = 3;
}

int main(int argc, char *argv[])
{
	if (argc != NUMBER_OF_ARGUMENTS)
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

