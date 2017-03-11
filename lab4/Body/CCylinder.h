#pragma once
#include "CBody.h"

class CCylinder : public CBody
{
public:
	CCylinder();
	CCylinder(double density, double height, double radius);
	~CCylinder();
	std::string GetInfo() override;
private:
	void SetVolume() override;
	double m_radius;
	double m_height;
};