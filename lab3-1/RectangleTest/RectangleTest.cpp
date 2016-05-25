// RectangleTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../lab3-1/Rectangle.h"


BOOST_AUTO_TEST_SUITE(rectangles_test)
	BOOST_AUTO_TEST_CASE(width_and_height_cannot_be_negative)
	{
		CRectangle rect(-1, -1, -1, -1);
		BOOST_CHECK_EQUAL(rect.GetSize().x, 0);
		BOOST_CHECK_EQUAL(rect.GetSize().y, 0);
	}
	BOOST_AUTO_TEST_CASE(check_values_after_creating_rectangle)
	{
		CRectangle rect(-1, -2, 2, 3);
		BOOST_CHECK_EQUAL(rect.GetPos().x, -1);
		BOOST_CHECK_EQUAL(rect.GetPos().y, -2);
		BOOST_CHECK_EQUAL(rect.GetSize().x, 2);
		BOOST_CHECK_EQUAL(rect.GetSize().y, 3);
	}
	BOOST_AUTO_TEST_CASE(check_coordinates)
	{
		CRectangle rect(2, 5, 1, 3);
		BOOST_CHECK_EQUAL(rect.GetRight(), 3);
		BOOST_CHECK_EQUAL(rect.GetBottom(), 8);
		BOOST_CHECK_EQUAL(rect.GetPos().x, 2);
		BOOST_CHECK_EQUAL(rect.GetPos().y, 5); 
	}
	BOOST_AUTO_TEST_CASE(check_size)
	{
		CRectangle rect(2, 5, 1, 3);
		BOOST_CHECK_EQUAL(rect.GetSize().x, 1);
		BOOST_CHECK_EQUAL(rect.GetSize().y, 3);
		BOOST_CHECK_EQUAL(rect.GetArea(), 3);
		BOOST_CHECK_EQUAL(rect.GetPerimeter(), 8);
	}
	BOOST_AUTO_TEST_CASE(check_move)
	{
		CRectangle rect(2, 5, 1, 3);
		rect.Move(1, 1);
		BOOST_CHECK_EQUAL(rect.GetPos().x, 3);
		BOOST_CHECK_EQUAL(rect.GetPos().y, 6);
		rect.Move(-2, -2);
		BOOST_CHECK_EQUAL(rect.GetPos().x, 1);
		BOOST_CHECK_EQUAL(rect.GetPos().y, 4); 
	}
	BOOST_AUTO_TEST_CASE(check_scale)
	{
		CRectangle rect(2, 5, 1, 3);
		rect.Scale(3, 3);
		BOOST_CHECK_EQUAL(rect.GetSize().x, 3);
		BOOST_CHECK_EQUAL(rect.GetSize().y, 9);
	}
	BOOST_AUTO_TEST_CASE(scale_with_negative_arguments_is_impossible)
	{
		CRectangle rect(2, 5, 1, 3);
		rect.Scale(-3, -3);
		BOOST_CHECK_EQUAL(rect.GetSize().x, 1);
		BOOST_CHECK_EQUAL(rect.GetSize().y, 3);
	}
	BOOST_AUTO_TEST_CASE(check_intersect_rectangles)
	{
		CRectangle rect1(2, 5, 1, 3);
		CRectangle rect2(1, 5, 3, 3);
		BOOST_CHECK(rect1.HaveIntersect(rect2));
	}
	BOOST_AUTO_TEST_CASE(check_not_intersect_rectangles)
	{
		CRectangle rect3(2, 5, 1, 1);
		CRectangle rect4(5, 7, 3, 3);
		BOOST_CHECK(!rect3.HaveIntersect(rect4));
	}
BOOST_AUTO_TEST_SUITE_END()



