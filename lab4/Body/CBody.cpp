#include "stdafx.h"
#include "CBody.h"


CBody::CBody()
	: m_density(0)
	, m_weight(0)
	, m_volume(0)
{
}


CBody::~CBody()
{
}

double CBody::GetWeight() const
{
	return m_weight;
}

double CBody::GetVolume() const
{
	return m_volume;
}

double CBody::GetDensity() const
{
	return m_density;
}

void CBody::SetWeight()
{
	m_weight = GetDensity() * GetVolume();
}

void CBody::SetDensity(double density)
{
	m_density = density;
}

void CBody::SetVolume()
{
}

void CBody::SetVolume(double volume)
{
	m_volume = volume;
}