// main.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "CManager.h"

void DisplayInputRule()
{
	std::cout << "Enter one name of body: <sphere> <cone> <cylinder> <parallelepiped> <compound>" << std::endl;
}

int main()
{
//	CComandHandler commandHandler;
	CManager managerBodies;
	std::string nameBody;
	DisplayInputRule();
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cin >> nameBody;
		if (!std::cin.fail())
		{
			managerBodies.SetBody(nameBody);
		}
	}
	managerBodies.DisplayInfo();
	return 0;
}