// task1tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <boost/test/output/compiler_log_formatter.hpp>

BOOST_AUTO_TEST_CASE(everything_is_ok)
{
	BOOST_CHECK_EQUAL(2 * 2, 4);
}


