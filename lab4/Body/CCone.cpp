#include "stdafx.h"
#include "CCone.h"


CCone::CCone(double density, double height, double radius)
	: CSolidBody(density), 
	m_height(height),
	m_radius(radius)
{
}

double CCone::GetVolume() const
{
	return (M_PI * GetHeight() * std::pow(GetRadius(), 2)) / 3;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetRadius() const
{
	return m_radius;
}

std::string CCone::GetInfo() const
{
	std::string info;
	info = "Type = cone\n";
	info.append("Density = " + std::to_string(GetDensity()) + "\n");
	info.append("Volume = " + std::to_string(GetVolume()) + "\n");
	info.append("Weight = " + std::to_string(GetMass()) + "\n");
	info.append("Height = " + std::to_string(GetHeight()) + "\n");
	info.append("Radius = " + std::to_string(GetRadius()) + "\n");
	return info;
}