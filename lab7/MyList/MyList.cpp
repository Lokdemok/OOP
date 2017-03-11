#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	CList<string> strList;
	strList.PushBack("one");
	strList.PushBack("two");
	strList.PushBack("three");
	cout << "List of strings: ";
	for (auto it = strList.begin(); it != strList.end(); ++it)
	{
		cout << *it;
	}
	cout << endl;

	CList<int> intList;
	intList.PushBack(1);
	intList.PushBack(2);
	intList.PushBack(3);
	cout << "List of integers: ";
	for (auto it = intList.rbegin(); it != intList.rend(); ++it)
	{
		cout << *it;
	}
	cout << endl;
	
	return 0;
}