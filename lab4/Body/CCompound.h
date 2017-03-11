#pragma once
#include "CBody.h"

class CCompound : public CBody
{
public:
	CCompound();
	~CCompound();
	void AddBody(CBody const& otherbody);
	std::string GetInfo() override;
protected:
	void SetDensity(double density) override;
	void SetVolume(double volume) override;
};