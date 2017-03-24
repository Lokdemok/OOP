#pragma once
#include "stdafx.h"

class CBody
{
public:
	CBody(double density);
	virtual ~CBody();
	virtual double GetDensity() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetMass() const = 0;
	virtual std::string GetInfo() const = 0;
protected:
	std::string m_info;
	double m_density = 0;
};
