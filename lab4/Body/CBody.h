#pragma once
#include "stdafx.h"

class CBody
{
public:
	CBody();
	~CBody();
	double GetDensity() const;
	double GetVolume() const;
	double GetWeight() const;
	virtual std::string GetInfo() = 0;
protected:
	virtual void SetWeight();
	virtual void SetDensity(double density);
	virtual void SetVolume();
	virtual void SetVolume(double volume);
	double m_weight;
	double m_density;
	double m_volume;
	std::string m_info;
};
