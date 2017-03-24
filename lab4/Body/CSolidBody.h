#pragma once
#include "CBody.h"

class CSolidBody : public CBody
{
public:
	CSolidBody(double density);
	double GetMass() const override;
	double GetDensity() const override;
	//virtual std::string GetInfo() const = 0;
protected:
	double m_density;
};