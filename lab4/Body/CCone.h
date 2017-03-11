#pragma once
#include "CBody.h"

class CCone : public CBody
{
public:
	CCone();
	CCone(double density, double height, double radius);
	~CCone();
	std::string GetInfo();
private:
	void SetVolume() override;
	double m_height;
	double m_radius;
};