#include "stdafx.h"
#include <string>
#include "../MyList/List.h"

using namespace std;


template<typename T>
void CheckList(CList<T> & list, vector<T> & expectedElements)
{
	size_t counter = 0;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		BOOST_CHECK_EQUAL(*it, expectedElements[counter]);
		++counter;
	}
}

template<typename T>
void CheckReverseList(CList<T> & list, vector<T> & expectedStrings)
{
	size_t counter = expectedStrings.size() - 1;
	for (auto it = list.rbegin(); it != list.rend(); ++it)
	{
		BOOST_CHECK_EQUAL(*it, expectedStrings[counter]);
		--counter;
	}
}

BOOST_AUTO_TEST_SUITE(my_list)

	BOOST_AUTO_TEST_CASE(check_empty_list)
	{
		CList<string> list;
		BOOST_CHECK(list.IsEmpty());
		BOOST_CHECK_EQUAL(list.GetSize(), 0);
	}

	BOOST_AUTO_TEST_CASE(push_front_in_empty_list)
	{
		CList<string> list;
		list.PushFront("oop");
		BOOST_CHECK_EQUAL(list.GetSize(), 1);
		BOOST_CHECK_EQUAL(*list.begin(), "oop");
	}

	BOOST_AUTO_TEST_CASE(push_back_in_empty_list)
	{
		CList<string> list;
		list.PushBack("oop");
		BOOST_CHECK_EQUAL(list.GetSize(), 1);
		BOOST_CHECK_EQUAL(*list.rbegin(), "oop");
	}

	BOOST_AUTO_TEST_CASE(push_front_in_not_empty_list)
	{
		CList<string> list;
		list.PushFront("one");
		list.PushFront("two");
		BOOST_CHECK_EQUAL(list.GetSize(), 2);
		BOOST_CHECK_EQUAL(*list.begin(), "two");
	}

	BOOST_AUTO_TEST_CASE(push_back_in_not_empty_list)
	{
		CList<string> list;
		list.PushBack("one");
		list.PushBack("two");
		BOOST_CHECK_EQUAL(list.GetSize(), 2);
		BOOST_CHECK_EQUAL(*list.rbegin(), "two");
	}
	
	BOOST_AUTO_TEST_CASE(check_begin_and_end_iterators)
	{
		CList<string> list;
		list.PushBack("one");
		list.PushBack("two");
		list.PushBack("three");
		vector<string> expectedStrings = { "one", "two", "three" };
		CheckList(list, expectedStrings);
	}

	BOOST_AUTO_TEST_CASE(check_rbegin_and_rend_iterators)
	{
		CList<string> list;
		list.PushBack("one");
		list.PushBack("two");
		list.PushBack("three");
		vector<string> expectedStrings = { "one", "two", "three" };
		CheckReverseList(list, expectedStrings);
	}

	BOOST_AUTO_TEST_CASE(insert_in_iterator_position)
	{
		CList<string> list;
		list.PushBack("one");
		list.PushBack("two");

		list.Insert(++list.begin(), "middle");
		BOOST_CHECK_EQUAL(list.GetSize(), 3);
		vector<string> expectedStrings = { "one", "middle", "two" };
		CheckList(list, expectedStrings);
	}

	BOOST_AUTO_TEST_CASE(check_delete_in_list_with_one_element)
	{
		CList<string> list;
		list.PushBack("one");

		list.Delete(list.begin());
		BOOST_CHECK(list.IsEmpty());
		BOOST_CHECK_EQUAL(list.GetSize(), 0);
	}

	BOOST_AUTO_TEST_CASE(delete_in_first_position)
	{
		CList<string> list;
		list.PushBack("one");
		list.PushBack("two");
		list.PushBack("three");

		list.Delete(list.begin());
		BOOST_CHECK_EQUAL(list.GetSize(), 2);
		vector<string> expectedStrings = { "two", "three" };
		CheckList(list, expectedStrings);

	}

	BOOST_AUTO_TEST_CASE(delete_element_in_iterator_position)
	{
		CList<string> list;
		list.PushBack("one");
		list.PushBack("two");
		list.PushBack("three");

		list.Delete(++list.begin());
		BOOST_CHECK_EQUAL(list.GetSize(), 2);
		vector<string> expectedStrings = { "one", "three" };
		CheckList(list, expectedStrings);
	}

	BOOST_AUTO_TEST_CASE(delete_element_in_last_position)
	{
		CList<string> list;
		list.PushBack("one");
		list.PushBack("two");
		list.PushBack("three");

		list.Delete(list.last());
		BOOST_CHECK_EQUAL(list.GetSize(), 2);
		vector<string> expectedStrings = { "one", "two" };
		CheckList(list, expectedStrings);
	}
		
	BOOST_AUTO_TEST_CASE(check_copy_constructor)
	{
		CList<string> list;
		list.PushBack("first");
		list.PushBack("second");
		list.PushBack("third");

		CList<string> copy(list);
		vector<string> expectedStrings = { "first", "second", "third" };
		CheckList(list, expectedStrings);
		CheckList(copy, expectedStrings);

		list.Insert(++list.begin(), "extra");
		BOOST_CHECK_EQUAL(*++list.begin(), "extra");
		BOOST_CHECK_EQUAL(*++copy.begin(), "second");
	}

	BOOST_AUTO_TEST_CASE(can_be_correctly_assigned)
	{
		CList<string> list;
		list.PushBack("first");
		list.PushBack("second");
		list.PushBack("third");

		CList<string> copy;
		copy = list;
		vector<string> expectedStrings = { "first", "second", "third" };
		CheckList(list, expectedStrings);
		CheckList(copy, expectedStrings);

		list.Insert(++list.begin(), "extra");
		BOOST_CHECK_EQUAL(*++list.begin(), "extra");
		BOOST_CHECK_EQUAL(*++copy.begin(), "second");
	}

BOOST_AUTO_TEST_SUITE_END()
