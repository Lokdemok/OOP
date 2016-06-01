// task1tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

BOOST_AUTO_TEST_CASE(everything_is_ok)
{
	BOOST_CHECK_EQUAL(2 * 2, 4);
}