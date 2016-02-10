#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

int main(void)
{
	std::ifstream inputFile("input.txt");
	std::string current_str;
	std::string searchStr = "123";
	int counterNumString;
	bool isFindText;
	counterNumString = 0;
	isFindText = false;
	if (inputFile.is_open())
	{
		
		while (inputFile.good())
		{
			counterNumString++;
			getline(inputFile, current_str);
			if (current_str.find(searchStr) != std::string::npos)
			{
				std::cout << counterNumString << "\n";
				isFindText = true;
			}
		}
	}
	else
		std::cout << "Unable to open file" << "\n";
	system("pause");
	if (isFindText)
		return 0;
	else
	{
		return 1;
		std::cout << "Textnotfound" << "\n";
	}
}