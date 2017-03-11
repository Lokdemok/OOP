#pragma once
#include "CBody.h"

class CSphere : public CBody
{
public:
	CSphere();
	CSphere(double density, double raduis);
	~CSphere();
	std::string GetInfo() override;
private:
	void SetVolume() override;
	double m_radius;
};
