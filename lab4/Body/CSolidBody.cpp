#include "stdafx.h"
#include "CSolidBody.h"


CSolidBody::CSolidBody(double density)
	:CBody(density)
	, m_density(density)
{
}
double CSolidBody::GetMass() const
{
	return GetDensity() * GetVolume();
}

double CSolidBody::GetDensity() const
{
	return m_density;
}
