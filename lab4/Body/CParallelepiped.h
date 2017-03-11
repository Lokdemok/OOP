#pragma once
#include "CBody.h"

class CParallelepiped : public CBody
{
public:
	CParallelepiped();
	CParallelepiped(double density, double height, double width, double depth);
	~CParallelepiped();
	std::string GetInfo() override;
private:
	void SetVolume() override;
	double m_height;
	double m_width;
	double m_depth;
};