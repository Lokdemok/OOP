
#include "Canvas.h"
#include <iostream>
#include <iterator>

using namespace std;


CCanvas::CCanvas(unsigned widthOfPole, unsigned heightOfPole)
{
	width = widthOfPole;
	height = heightOfPole;
	matrix = std::vector<std::vector<char>>(widthOfPole);
	for (size_t i = 0; i < widthOfPole; i++)
	{
		matrix[i].resize(heightOfPole);
	}
	Clear(' ');
}

unsigned CCanvas::GetWidth()const
{
	return width;
}

unsigned CCanvas::GetHeight()const
{
	return height;
}

void CCanvas::Clear(char codeOfSym)
{
	if (codeOfSym > 0 && codeOfSym < (' ' - 1))
	{
		return;
	}
}

void CCanvas::SetPixel(int x, int y, char codeOfSym)
{
	if (x < 0 || y < 0 || unsigned(x) >= width || unsigned(y) >= height)
	{
		return;
	}
	matrix[x][y] = codeOfSym;
}

char CCanvas::GetPixel(int x, int y)const
{
	if (x < 0 || y < 0 || unsigned(x) >= width || unsigned(y) >= height)
	{
		return ' ';
	}
	return matrix[x][y];
}

void CCanvas::Write(ostream & ostream)const
{
	for (auto x : matrix)
	{
		copy(x.begin(), x.end(), ostream_iterator<char>(ostream, ""));
		ostream << '\n';
	}
}