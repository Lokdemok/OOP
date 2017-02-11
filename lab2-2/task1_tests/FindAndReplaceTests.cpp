#include "stdafx.h"
#include "../task1/FindAndReplace.h"
#include <boost/test/unit_test.hpp>
using namespace std;

BOOST_AUTO_TEST_SUITE(FindAndReplace_function)

BOOST_AUTO_TEST_CASE(replaces_substring_in_string)
{
	BOOST_CHECK(FindAndReplace("nice morning", "morning", "day") == "nice day");
}

BOOST_AUTO_TEST_CASE(replaces_substring_in_string_without_looping)
{
	BOOST_CHECK(FindAndReplace("lala", "la", "lala") == "lalalala");
}

BOOST_AUTO_TEST_CASE(replaces_substring_in_string_with_repeated_words)
{
	BOOST_CHECK(FindAndReplace("hi hi hello hi", "hello", "hi") == "hi hi hi hi");
}

BOOST_AUTO_TEST_CASE(empty_subject_string_is_OK)
{
	BOOST_CHECK(FindAndReplace("", "hey", "apple") == "");
}

BOOST_AUTO_TEST_CASE(empty_search_string_is_OK)
{
	BOOST_CHECK(FindAndReplace("apple", "", "hey") == "apple");
}

BOOST_AUTO_TEST_CASE(empty_replace_string_is_OK)
{
	BOOST_CHECK(FindAndReplace("apple", "hey", "") == "apple");
}

BOOST_AUTO_TEST_SUITE_END()

