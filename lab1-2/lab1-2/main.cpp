// lab1-2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
namespace
{
	const int NUMBER_OF_ARGUMENTS = 4;
	const int NUMBER_OF_SIGNS_AFTER_DECIMAL_POINT = 4;
}

double CalculateDiscriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

vector <double> CalculateRoot(double discriminant, double a, double b, double c)
{
	vector <double> roots;
	if (a != 0)
	{
		if (discriminant == 0)
		{
			roots.push_back(- b / (2 * a));
		}
		else if (discriminant > 0)
		{
			roots.push_back((-b) + sqrt(discriminant) / (2 * a));
			roots.push_back((-b) - sqrt(discriminant) / (2 * a));
		}
	}
	return roots;
}

void PrintResult(const vector <double> & roots, double a)
{
	if (a == 0)
	{
		std::cout << "This equation is not square, a = 0\n";
	}
	else if (roots.empty())
	{
		std::cout << "There is no real root\n";
	}
	else if (roots.size() >= 1)
	{
		std::cout << setprecision(NUMBER_OF_SIGNS_AFTER_DECIMAL_POINT);
		copy(roots.begin(), roots.end(), ostream_iterator<double>(std::cout, " "));
	}
}

int main(int argc, char *argv[])
{
	if (argc != NUMBER_OF_ARGUMENTS)
	{
		std::cout << "Incorrect input. The correct command line format:\nlab1-2.exe <A> <B> <C>\n";
		return -1;
	}
	else
	{
		for (int i = 1; i < NUMBER_OF_ARGUMENTS; ++i)
		{
			if (!isdigit(*argv[i]) && *argv[i] != '-')
			{
				std::cout << "It's not a number: " << argv[i] << endl;
				return -1;
			}
		}
		double a = atof(argv[1]);
		double b = atof(argv[2]);
		double c = atof(argv[3]);
		double discriminant = CalculateDiscriminant(a, b, c);
		vector <double> roots = CalculateRoot(discriminant, a, b, c);
		PrintResult(roots, a);
		return 0;
	}
}

