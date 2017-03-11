#include "stdafx.h"
#include "CCompound.h"


CCompound::CCompound()
{
}


CCompound::~CCompound()
{
}

void CCompound::AddBody(CBody const & otherBody)
{
	SetDensity(otherBody.GetDensity());
	SetVolume(otherBody.GetVolume());
	SetWeight();
}

void CCompound::SetDensity(double density)
{
	m_density += density;
}

void CCompound::SetVolume(double volume)
{
	m_volume += volume;
}

std::string CCompound::GetInfo()
{
	std::string info;
	info = "Type = compound\n";
	info.append("Density = " + std::to_string(m_density) + "\n");
	info.append("Volume = " + std::to_string(m_volume) + "\n");
	info.append("Weight = " + std::to_string(m_weight) + "\n");
	return info;
}