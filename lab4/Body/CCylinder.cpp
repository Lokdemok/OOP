#include "stdafx.h"
#include "CCylinder.h"

CCylinder::CCylinder()
{
}

CCylinder::CCylinder(double density, double height, double radius)
	: m_height(height),
	m_radius(radius)
{
	SetVolume();
	SetDensity(density);
	SetWeight();
}

CCylinder::~CCylinder()
{
}


void CCylinder::SetVolume()
{
	m_volume = M_PI * std::pow(m_radius, 2) * m_height;
}

std::string CCylinder::GetInfo()
{
	std::string info;
	info = "Type = cylinder\n";
	info.append("Density = " + std::to_string(m_density) + "\n");
	info.append("Volume = " + std::to_string(m_volume) + "\n");
	info.append("Weight = " + std::to_string(m_weight) + "\n");
	info.append("Height = " + std::to_string(m_height) + "\n");
	info.append("Radius = " + std::to_string(m_radius) + "\n");
	return info;
}