#include "stdafx.h"
#include "CBody.h"
#include "CSphere.h"
#include "CParallelepiped.h"
#include "CCylinder.h"
#include "CCone.h"
#include "CCompound.h"
#include "CManager.h"

void CManager::SetBody(std::string const & s)
{
	auto body = MakeBody(s);
	if (body != nullptr)
	{
		m_bodies.push_back(body);
	}
}



std::shared_ptr<CBody> CManager::MakeBody(std::string const & name)
{
	std::shared_ptr<CBody> body;
	if (name == "cone")
	{
		body = std::make_shared<CCone>(CCone(InputValue("density"), InputValue("radius"), InputValue("heigth")));
	}
	else if (name == "cylinder")
	{
		body = std::make_shared<CCylinder>(CCylinder(InputValue("density"), InputValue("radius"), InputValue("heigth")));
	}
	else if (name == "parallelepiped")
	{
		body = std::make_shared<CParallelepiped>(CParallelepiped(InputValue("density"), InputValue("width"), InputValue("heigth"), InputValue("depth")));
	}
	else if (name == "sphere")
	{
		body = std::make_shared<CSphere>(CSphere(InputValue("density"), InputValue("radius")));
	}
	else if (name == "compound")
	{
		body = std::make_shared<CCompound>(MakeCompoundBody());
	}
	else
	{
		std::cout << "Invalid shape" << std::endl;
		body = nullptr;
	}
	return body;
}

CCompound CManager::MakeCompoundBody()
{
	CCompound compound;
	std::string name;
	std::cout << "Enter name of body to compound or 'q' to exit: " << std::endl;
	for (;;)
	{
		std::cin >> name;
		if (name == "q")
		{
			break;
		}
		auto body = MakeBody(name);
		if (body != nullptr)
		{
			compound.AddBody(*body);
		}
	}
	std::cout << "Exit from create compound body: " << std::endl;
	return compound;
}

void CManager::DisplayInfo()
{
	double maxWeight = 0;
	double minWeigthInWater = std::numeric_limits<double>::infinity();
	double valueInWater = 0;
	for (auto & it : m_bodies)
	{
		if (maxWeight < it->GetWeight())
		{
			maxWeight = it->GetWeight();
			m_maxWeightBody = it.get();
		}
		maxWeight = (maxWeight < it->GetWeight()) ? it->GetWeight() : maxWeight;
		valueInWater = (it->GetDensity() - WATER_DENSITY) * G * it->GetVolume();
		if (minWeigthInWater > valueInWater)
		{
			minWeigthInWater = valueInWater;
			m_lessWeightInWaterBody = it.get();
		}
	}
	std::cout << "Body with maximum weight: " << std::endl;
	std::cout << m_maxWeightBody->GetInfo() << std::endl;
	std::cout << "Body with minimum weight in water: " << std::endl;
	std::cout << m_lessWeightInWaterBody->GetInfo() << std::endl;
}

double CManager::InputValue(std::string const & typeValue)
{
	double possibleNumber;
	std::cout << typeValue << " = ";
	while (!(std::cin >> possibleNumber) || (possibleNumber) <= 0)
	{
		std::cin.clear();
		std::cout << "Invalid value: less 0 or not a number" << std::endl;
		std::cout << typeValue << " = ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (possibleNumber);
}