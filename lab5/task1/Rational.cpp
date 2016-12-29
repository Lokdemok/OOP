#include "stdafx.h"
#include "Rational.h"
#include <utility>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////

double CRational::ToDouble()const
{
	return m_numerator / double(m_denominator);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////

CRational const CRational::operator+ () const
{
	return *this;
}

CRational const CRational::operator- () const
{
	return CRational(-m_numerator, m_denominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////

CRational operator + (CRational const & lhs, CRational const & rhs)
{
	return{ lhs.GetNumerator() * rhs.GetDenominator() + rhs.GetNumerator()*lhs.GetDenominator(),
		lhs.GetDenominator() * rhs.GetDenominator() };
}


//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////

CRational operator - (CRational const & lhs, CRational const & rhs)
{
	return lhs + -rhs;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////

CRational & CRational::operator += (CRational const & otherRational)
{
	*this = *this + otherRational;
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////

CRational & CRational::operator -= (CRational const & otherRational)
{
	return *this += -otherRational;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////

CRational operator*(CRational const & lhs, CRational const & rhs)
{
	return{ lhs.GetNumerator() * rhs.GetNumerator(),
		lhs.GetDenominator() * rhs.GetDenominator() };
}


//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////

CRational const operator / (CRational const & lhs, CRational const & rhs)
{
	return lhs * CRational(rhs.GetDenominator(), rhs.GetNumerator());
}


//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////

CRational & CRational::operator *= (CRational const & otherRational)
{
	m_numerator = m_numerator * otherRational.m_numerator;
	m_denominator = m_denominator * otherRational.m_denominator;
	Normalize();
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////

CRational & CRational::operator /= (CRational const & otherRational)
{
	return *this *= CRational(otherRational.GetDenominator(), otherRational.GetNumerator());
}


//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////

bool const operator == (CRational const & lhs, CRational const & rhs)
{
	return ((lhs.GetNumerator() == rhs.GetNumerator()) &&
		(lhs.GetDenominator() == rhs.GetDenominator()));
}

bool const operator != (CRational const & lhs, CRational const & rhs)
{
	return !(lhs == rhs);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////

bool const operator < (CRational const &lhs, CRational const &rhs)
{
	return lhs.GetNumerator() * rhs.GetDenominator() <
		rhs.GetNumerator() * lhs.GetDenominator();
}

bool const operator > (CRational const &lhs, CRational const &rhs)
{
	return !(lhs <= rhs);
}

bool const operator <= (CRational const &lhs, CRational const &rhs)
{
	return lhs == rhs || lhs < rhs;
}

bool const operator >= (CRational const &lhs, CRational const &rhs)
{
	return !(lhs < rhs);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////


std::ostream & operator << (std::ostream & stream, CRational const & rationalNumber)
{
	stream << rationalNumber.GetNumerator() << '/' << rationalNumber.GetDenominator();
	return stream;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////
std::istream & operator >> (std::istream & stream, CRational & rational)
{
	int numerator;
	int denominator;

	if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
	{
		rational = CRational(numerator, denominator);
	}
	else
	{
		stream.setstate(stream.rdstate() | std::ios_base::failbit);
	}
	return stream;
}