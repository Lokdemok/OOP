#include "stdafx.h"
#include "Rectangle.h"
#include "Canvas.h"

using namespace std;

struct Vector4i
{
	int left;
	int top;
	int height;
	int width;
};

Vector4i GetArgsIntersectRect(vector<CRectangle> & rectangles)
{
	int left;
	int top;
	int height;
	int width;
	left = max(rectangles[0].GetPos().x, rectangles[1].GetPos().x);
	top = max(rectangles[0].GetPos().y, rectangles[1].GetPos().y);
	height = min(rectangles[0].GetBottom(), rectangles[1].GetBottom()) - top;
	width = min(rectangles[0].GetRight(), rectangles[1].GetRight()) - left;
	return{ left, top, height, width };
}

vector<string> SplitLine(const string & command)
{
	vector<string> result;
	istringstream iss(command);
	string argument;
	while (getline(iss, argument, ' '))
	{
		result.push_back(argument);
	}

	return result;
}
void PerformCommand(const string & line, vector<CRectangle> & rectangles)
{
	vector <string> arguments;
	arguments = SplitLine(line);
	if (arguments[0] == "Rectangle")
	{
		rectangles.push_back(CRectangle(
			atoi(arguments[1].c_str()), 
			atoi(arguments[2].c_str()), 
			atoi(arguments[3].c_str()), 
			atoi(arguments[4].c_str())));
	}
	else if (arguments[0] == "Move")
	{
		(rectangles.begin(), rectangles.end())->Move(
			atoi(arguments[1].c_str()),
			atoi(arguments[2].c_str()));
	}
	else if (arguments[0] == "Scale")
	{
		(rectangles.begin(), rectangles.end())->Scale(
			atoi(arguments[1].c_str()),
			atoi(arguments[2].c_str()));
	}
}

void OutputRectanglesInformation(vector<CRectangle> & rectangles)
{
	for (auto rect : rectangles)
	{
		cout << "Rectangle " << endl;
		cout << "\tLeft Top: (" << rect.GetPos().x << "; " << rect.GetPos().y << ")" << endl;
		cout << "\tSize: " << rect.GetSize().x << "*" << rect.GetSize().y << endl;
		cout << "\tRight Bottom: (" << rect.GetRight() << "; " << rect.GetBottom() << ")" << endl;
		cout << "\tArea: " << rect.GetArea() << endl;
		cout << "\tPerimeter: " << rect.GetPerimeter() << endl;
	}
}

void FillRectangle(CRectangle & rect, char symForDraw, CCanvas & canvas)
{
	for (int x = rect.GetPos().x; x < rect.GetPos().x + rect.GetSize().x; x++)
	{
		for (int y = rect.GetPos().y; y < rect.GetSize().y + rect.GetPos().y; y++)
		{
			canvas.SetPixel(y, x, symForDraw);
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc < 3 || argc > 4)
	{
		cout << "Uncorrect format of arguments, right format: <lab3-1> <file1.txt> <file2.txt> <outputFile.txt>" << endl;
		return 1;
	}
	else
	{
		ifstream fileOfRectangle1(argv[1]);
		ifstream fileOfRectangle2(argv[2]);
		vector<CRectangle> rectangles;
		if (fileOfRectangle1.is_open() && fileOfRectangle2.is_open())
		{
			string line;
			while ((getline(fileOfRectangle1, line)) || (getline(fileOfRectangle2, line)))
			{
				PerformCommand(line, rectangles);
			}

		}
		OutputRectanglesInformation(rectangles);
		CCanvas canvas(20, 20);
		FillRectangle(rectangles[1], '-', canvas);
		FillRectangle(rectangles[0], '+', canvas);
		if (rectangles[0].HaveIntersect(rectangles[1]))
		{
			int left = GetArgsIntersectRect(rectangles).left;
			int top = GetArgsIntersectRect(rectangles).top;
			int height = GetArgsIntersectRect(rectangles).height;
			int width = GetArgsIntersectRect(rectangles).width;
			CRectangle intersectRect(left, top, width, height);
			FillRectangle(intersectRect, '#', canvas);
		}
		if (argc == 4)
		{
			ofstream output(argv[3]);
			canvas.Write(output);
		}
		else
		{
			canvas.Write(cout);
		}
		system("pause");
	}
}