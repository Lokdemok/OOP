#include "stdafx.h"
#include "../Body/CSphere.h"
#include "../Body/CBody.h"
#include "../Body/CParallelepiped.h"
#include "../Body/CCylinder.h"
#include "../Body/CCone.h"
#include "../Body/CCompound.h"

namespace
{
	CSphere sphere(10, 2);
	CParallelepiped parallelepiped(10, 2, 3, 4);
	CCylinder cylinder(10, 2, 3);
	CCone cone(5, 3, 5);
	CCompound compound;
}
BOOST_AUTO_TEST_SUITE(Sphere)

BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(float(sphere.GetDensity()), 10);
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(sphere.GetMass()), float(335.10321));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(sphere.GetVolume()), float(33.5103226));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Type = sphere\nDensity = 10.000000\nVolume = 33.510322\nWeight = 335.103216\nRadius = 2.000000\n";
	BOOST_CHECK_EQUAL(sphere.GetInfo(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(Parallelepiped)

BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(float(parallelepiped.GetDensity()), 10);
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(parallelepiped.GetMass()), float(240));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(parallelepiped.GetVolume()), float(24));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Type = parallelepiped\nDensity = 10.000000\nVolume = 24.000000\n\
Weight = 240.000000\nHeight = 2.000000\nWidth = 3.000000\nDepth = 4.000000\n";
	BOOST_CHECK_EQUAL(parallelepiped.GetInfo(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(Cylinder)

BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(float(cylinder.GetDensity()), 10);
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(cylinder.GetMass()), float(565.486694));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(cylinder.GetVolume()), float(56.5486679));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Type = cylinder\nDensity = 10.000000\nVolume = 56.548668\n\
Weight = 565.486678\nHeight = 2.000000\nRadius = 3.000000\n";
	BOOST_CHECK_EQUAL(cylinder.GetInfo(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(Cone)

BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(float(cone.GetDensity()), 5);
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(cone.GetMass()), float(392.699097));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(cone.GetVolume()), float(78.5398178));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Type = cone\nDensity = 5.000000\nVolume = 78.539816\n\
Weight = 392.699082\nHeight = 3.000000\nRadius = 5.000000\n";
	BOOST_CHECK_EQUAL(cone.GetInfo(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(Compound_with_one_body)

BOOST_AUTO_TEST_CASE(has_a_density)
{
	compound.AddBody(std::make_shared<CParallelepiped>(parallelepiped));
	BOOST_CHECK_EQUAL(float(compound.GetDensity()), 10);
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(compound.GetMass()), float(240));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(compound.GetVolume()), float(24));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Type = compound\nDensity = 10.000000\nVolume = 24.000000\nWeight = 240.000000\n\
Type = parallelepiped\nDensity = 10.000000\nVolume = 24.000000\nWeight = 240.000000\nHeight = 2.000000\nWidth = 3.000000\nDepth = 4.000000\n";
	BOOST_CHECK_EQUAL(compound.GetInfo(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(Compound_with_few_body)

BOOST_AUTO_TEST_CASE(has_a_density)
{
	compound.AddBody(std::make_shared<CCone>(cone));
	BOOST_CHECK_EQUAL(float(compound.GetDensity()), 7.5);
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(compound.GetMass()), float(769.048645));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(compound.GetVolume()), float(102.539818));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Type = compound\nDensity = 7.500000\nVolume = 102.539816\nWeight = 769.048623\n\
Type = parallelepiped\nDensity = 10.000000\nVolume = 24.000000\nWeight = 240.000000\nHeight = 2.000000\nWidth = 3.000000\nDepth = 4.000000\n\
Type = cone\nDensity = 5.000000\nVolume = 78.539816\nWeight = 392.699082\nHeight = 3.000000\nRadius = 5.000000\n";
	BOOST_CHECK_EQUAL(compound.GetInfo(), expectedString);
}

BOOST_AUTO_TEST_CASE(can_not_take_itself)
{
	std::shared_ptr<CCompound> pCompound = std::make_shared<CCompound>();
	BOOST_CHECK_EQUAL(pCompound->GetBodiesCount(), 0);
	pCompound->AddBody(pCompound);
	BOOST_CHECK_EQUAL(pCompound->GetBodiesCount(), 0);
}
BOOST_AUTO_TEST_SUITE_END();