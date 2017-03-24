#pragma once
#include "CSolidBody.h"

class CCylinder : public CSolidBody
{
public:
	CCylinder(double density, double height, double radius);
	double GetVolume() const override;
	double GetRadius() const;
	double GetHeight() const;
	std::string GetInfo() const override;
private:
	double m_radius;
	double m_height;
};