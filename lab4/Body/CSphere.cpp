#include "stdafx.h"
#include "CSphere.h"

CSphere::CSphere(double density, double radius)
	: CSolidBody(density),
	m_radius(radius)
{
}


double CSphere::GetVolume()const
{
	return (pow(GetRadius(), 3) * M_PI) * 4 / 3;
}

double CSphere::GetRadius()const
{
	return m_radius;
}

std::string CSphere::GetInfo() const
{
	std::string info;
	info = "Type = sphere\n";
	info.append("Density = " + std::to_string(GetDensity()) + "\n");
	info.append("Volume = " + std::to_string(GetVolume()) + "\n");
	info.append("Weight = " + std::to_string(GetMass()) + "\n");
	info.append("Radius = " + std::to_string(GetRadius()) + "\n");
	return info;
}