#include "stdafx.h"
#include "CSphere.h"

CSphere::CSphere()
{
}

CSphere::CSphere(double density, double radius)
	: m_radius(radius)
{
	SetVolume();
	SetDensity(density);
	SetWeight();
}

CSphere::~CSphere()
{
}


void CSphere::SetVolume()
{
	m_volume = (4.0 * M_PI * std::pow(m_radius, 3)) / 3;
}

std::string CSphere::GetInfo()
{
	std::string info;
	info = "Type = sphere\n";
	info.append("Density = " + std::to_string(m_density) + "\n");
	info.append("Volume = " + std::to_string(m_volume) + "\n");
	info.append("Weight = " + std::to_string(m_weight) + "\n");
	info.append("Radius = " + std::to_string(m_radius) + "\n");
	return info;
}