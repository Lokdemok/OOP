#include "stdafx.h"
#include "CParallelepiped.h"

CParallelepiped::CParallelepiped()
{
}

CParallelepiped::CParallelepiped(double density, double height, double width, double depth)
	: m_height(height),
	m_width(width),
	m_depth(depth)
{
	SetVolume();
	SetDensity(density);
	SetWeight();
}

CParallelepiped::~CParallelepiped()
{
}


void CParallelepiped::SetVolume()
{
	m_volume = m_height * m_width * m_depth;
}

std::string CParallelepiped::GetInfo()
{
	std::string info;
	info = "Type = parallelepiped\n";
	info.append("Density = " + std::to_string(m_density) + "\n");
	info.append("Volume = " + std::to_string(m_volume) + "\n");
	info.append("Weight = " + std::to_string(m_weight) + "\n");
	info.append("Height = " + std::to_string(m_height) + "\n");
	info.append("Width = " + std::to_string(m_width) + "\n");
	info.append("Depth = " + std::to_string(m_depth) + "\n");
	return info;
}