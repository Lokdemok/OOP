#include "stdafx.h"
#include "CCylinder.h"


CCylinder::CCylinder(double density, double height, double radius)
	: CSolidBody(density), 
	m_height(height),
	m_radius(radius)
{
}

double CCylinder::GetVolume() const
{
	return M_PI * std::pow(GetRadius(), 2) * GetHeight();
}

double CCylinder::GetRadius() const
{
	return m_radius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

std::string CCylinder::GetInfo() const
{
	std::string info;
	info = "Type = cylinder\n";
	info.append("Density = " + std::to_string(GetDensity()) + "\n");
	info.append("Volume = " + std::to_string(GetVolume()) + "\n");
	info.append("Weight = " + std::to_string(GetMass()) + "\n");
	info.append("Height = " + std::to_string(GetHeight()) + "\n");
	info.append("Radius = " + std::to_string(GetRadius()) + "\n");
	return info;
}