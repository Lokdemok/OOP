#pragma once
#include "CBody.h"

class CCompound : public CBody
{
public:
	CCompound();
	double GetDensity()const override;
	double GetVolume()const override;
	double GetMass()const override;
	void AddBody(std::shared_ptr<CBody> && body);
	std::string GetInfo() const override;
	int GetBodiesCount() const;
private:
	double CalculateDensity() const;
	double CalculateVolume() const;
	std::string ToString() const;
	std::vector<std::shared_ptr<CBody>> m_bodies;
};