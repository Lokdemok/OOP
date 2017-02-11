#include "stdafx.h"
#include "../task1/FindAndReplace.h"
#include <boost/test/unit_test.hpp>
using namespace std;

BOOST_AUTO_TEST_SUITE(FindAndReplace_function)

BOOST_AUTO_TEST_CASE(replaces_substring_in_string)
{
	BOOST_CHECK(FindAndReplace("good day", "day", "night") == "good night");
}

BOOST_AUTO_TEST_CASE(replaces_substring_in_string_without_looping)
{
	BOOST_CHECK(FindAndReplace("lala", "la", "lala") == "lalalala");
}

BOOST_AUTO_TEST_CASE(replaces_substring_in_string_with_repeated_words)
{
	BOOST_CHECK(FindAndReplace("hello hello hi hello", "hi", "hello") == "hello hello hello hello");
}

BOOST_AUTO_TEST_CASE(empty_subject_string_is_OK)
{
	BOOST_CHECK(FindAndReplace("", "empty", "string") == "");
}

BOOST_AUTO_TEST_CASE(empty_search_string_is_OK)
{
	BOOST_CHECK(FindAndReplace("word", "", "letter") == "word");
}

BOOST_AUTO_TEST_CASE(empty_replace_string_is_OK)
{
	BOOST_CHECK(FindAndReplace("book", "film", "") == "book");
}

BOOST_AUTO_TEST_SUITE_END()

