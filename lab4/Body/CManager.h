#pragma once
#include "stdafx.h"
#include "CBody.h"
#include "CCompound.h"

static const double WATER_DENSITY = 1000;
static const double G = 9.78;

class CManager
{
public:
	void SetBody(std::string const & s);
	void DisplayInfo();
private:
	std::shared_ptr<CBody> MakeBody(std::string const & nameBody);
	CCompound MakeCompoundBody();
	std::vector <std::shared_ptr<CBody>> m_bodies;
	CBody *m_maxWeightBody;
	CBody *m_lessWeightInWaterBody;
	double InputValue(std::string const & typeValue);
};