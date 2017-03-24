#include "stdafx.h"
#include "CCompound.h"


CCompound::CCompound()
	: CBody(0)
{
}

void CCompound::AddBody(std::shared_ptr<CBody> && shape)
{
	const CBody *body = this;
	const CBody *otherBody = shape.get();
	if (body != otherBody)
	{
		m_bodies.push_back(move(shape));
	}
}

double CCompound::CalculateVolume() const
{
	double volume = 0;
	for (auto const & body : m_bodies)
	{
		volume += (body)->GetVolume();
	}
	return volume;
}

double CCompound::CalculateDensity() const
{
	double sumBodiesDensity = 0;
	for (auto const & body : m_bodies)
	{
		sumBodiesDensity += (body)->GetDensity();
	}
	return sumBodiesDensity / m_bodies.size();
}

double CCompound::GetMass() const
{
	return GetVolume() * GetDensity();
}

double CCompound::GetVolume() const
{
	return CalculateVolume();
}

double CCompound::GetDensity() const
{
	return CalculateDensity();
}

std::string CCompound::ToString() const
{
	std::string info;
	for (auto const & body : m_bodies)
	{
		info += (body)->GetInfo();
	}
	return info;
}

std::string CCompound::GetInfo() const
{
	std::string info;
	info = "Type = compound\n";
	info.append("Density = " + std::to_string(GetDensity()) + "\n");
	info.append("Volume = " + std::to_string(GetVolume()) + "\n");
	info.append("Weight = " + std::to_string(GetMass()) + "\n");
	info.append(ToString());
	return info;
}

int CCompound::GetBodiesCount() const
{
	return m_bodies.size();
}