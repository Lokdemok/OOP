#include "stdafx.h"
#include "Rectangle.h"



CRectangle::CRectangle()
{
	left = 0;
	top = 0;
	width = 0;
	height = 0;
}

CRectangle::CRectangle(int Left, int Top, int Width, int Height)
{
	left = Left;
	top = Top;
	width = GetPositiveValue(Width);
	height = GetPositiveValue(Height);
}

CRectangle::~CRectangle()
{}

void CRectangle::Scale(int sx, int sy)
{
	if (sx >= 0 && sy >= 0)
	{
		width = width * sx;
		height = height * sy;
	}
}

void CRectangle::Move(int dx, int dy)
{
	left += dx;
	top += dy;
}

int CRectangle::GetArea()
{
	return width * height;
}

int CRectangle::GetPerimeter()
{
	return 2 * (width + height);
}

int CRectangle::GetRight()
{
	return (left + width);
}

int CRectangle::GetBottom()
{
	return (top + height);
}

Vector2i CRectangle::GetPos()
{
	return { left, top };
}

Vector2i CRectangle::GetSize()
{
	return { width, height };
}

int CRectangle::GetPositiveValue(int value)
{
	if (value < 0)
		return 0;
	else
		return value;
}

bool CRectangle::HaveIntersect(const CRectangle & other)
{
	if (left < (other.left + other.width) && 
		(left + width) > other.left && 
		top < (other.top + other.height) && 
		(top + height) > other.top)
	{
		return true;
	}
	return false;
}