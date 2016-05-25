#include "stdafx.h"

struct Vector2i
{
	int x;
	int y;
};

class CRectangle
{
public:
	CRectangle();
	CRectangle(int left, int top, int width, int height);
	~CRectangle();
	void Move(int dx, int dy);
	void Scale(int sx, int sy);
	int GetArea();
	int GetPerimeter();
	int GetRight();
	int GetBottom();
	Vector2i GetPos();
	Vector2i GetSize();
	bool HaveIntersect(const CRectangle & other);

private:
	int GetPositiveValue(int value);
	int left;
	int top;
	int right;
	int bottom;
	int width;
	int height;
};