#include "stdafx.h"
#include "../Body/CSphere.h"
#include "../Body/CBody.h"

BOOST_AUTO_TEST_SUITE(test_sphere)

BOOST_AUTO_TEST_CASE(has_a_density)
{
	CSphere sphere2(10, 2);
	BOOST_CHECK_EQUAL(float(sphere2.GetDensity()), 10);
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	CSphere sphere3(10, 2);
	BOOST_CHECK_EQUAL(float(sphere3.GetWeight()), float(335.10321));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	CSphere sphere4(10, 2);
	BOOST_CHECK_EQUAL(float(sphere4.GetVolume()), float(33.5103226));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	CSphere sphere5(10, 2);
	auto expectedString = "Type = sphere\nDensity = 10.000000\nVolume = 33.510322\nWeight = 335.103216\nRadius = 2.000000\n";
	BOOST_CHECK_EQUAL(sphere5.GetInfo(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END();
