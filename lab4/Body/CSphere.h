#pragma once
#include "CSolidBody.h"

class CSphere final : public CSolidBody
{
public:
	CSphere(double density, double radius);
	double GetVolume() const override;
	double GetRadius() const;
	std::string GetInfo() const override;
private:
	double m_radius = 0;
};
