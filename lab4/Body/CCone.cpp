#include "stdafx.h"
#include "CCone.h"

CCone::CCone()
{
}

CCone::CCone(double density, double height, double radius)
	: m_height(height),
	m_radius(radius)
{
	SetVolume();
	SetDensity(density);
	SetWeight();
}

CCone::~CCone()
{
}


void CCone::SetVolume()
{
	m_volume = (M_PI * m_height * std::pow(m_radius, 2)) / 3;
}

std::string CCone::GetInfo()
{
	std::string info;
	info = "Type = cone\n";
	info.append("Density = " + std::to_string(m_density) + "\n");
	info.append("Volume = " + std::to_string(m_volume) + "\n");
	info.append("Weight = " + std::to_string(m_weight) + "\n");
	info.append("Height = " + std::to_string(m_height) + "\n");
	info.append("Radius = " + std::to_string(m_radius) + "\n");
	return info;
}