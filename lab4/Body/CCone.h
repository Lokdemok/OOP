#pragma once
#include "CSolidBody.h"

class CCone : public CSolidBody
{
public:
	CCone(double density, double height, double radius);
	double GetVolume() const override;
	double GetRadius() const;
	double GetHeight() const;
	std::string GetInfo() const override;
private:
	double m_height;
	double m_radius;
};