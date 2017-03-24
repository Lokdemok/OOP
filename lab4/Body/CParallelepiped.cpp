#include "stdafx.h"
#include "CParallelepiped.h"

CParallelepiped::CParallelepiped(double density, double height, double width, double depth)
	: CSolidBody(density), 
	m_height(height),
	m_width(width),
	m_depth(depth)
{
}


double CParallelepiped::GetVolume() const
{
	return GetHeight() * GetWidth() * GetDepth();
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

std::string CParallelepiped::GetInfo() const
{
	std::string info;
	info = "Type = parallelepiped\n";
	info.append("Density = " + std::to_string(GetDensity()) + "\n");
	info.append("Volume = " + std::to_string(GetVolume()) + "\n");
	info.append("Weight = " + std::to_string(GetMass()) + "\n");
	info.append("Height = " + std::to_string(GetHeight()) + "\n");
	info.append("Width = " + std::to_string(GetWidth()) + "\n");
	info.append("Depth = " + std::to_string(GetDepth()) + "\n");
	return info;
}