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
	return double(m_numerator) / double(m_denominator);
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

CRational const operator + (CRational const & firstRational, CRational const & secondRational)
{
	CRational result(firstRational.m_numerator * secondRational.m_denominator + secondRational.m_numerator*firstRational.m_denominator,
		firstRational.m_denominator * secondRational.m_denominator);
	result.Normalize();
	return result;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////

CRational const operator - (CRational const & firstRational, CRational const & secondRational)
{
	CRational result(firstRational.m_numerator * secondRational.m_denominator - secondRational.m_numerator*firstRational.m_denominator,
		firstRational.m_denominator * secondRational.m_denominator);
	result.Normalize();
	return result;
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
	*this = *this - otherRational;
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////

CRational operator*(CRational const & firstRational, CRational const & secondRational)
{
	return{ firstRational.GetNumerator() * secondRational.GetNumerator(),
		firstRational.GetDenominator() * secondRational.GetDenominator() };
}


//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////

CRational const operator / (CRational const & firstRational, CRational const & secondRational)
{
	return{ firstRational.GetNumerator() * secondRational.GetDenominator(),
		firstRational.GetDenominator() * secondRational.GetNumerator() };
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
	m_numerator = m_numerator * otherRational.m_denominator;
	m_denominator = m_denominator * otherRational.m_numerator;
	Normalize();
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////

bool const operator == (CRational const & firstRational, CRational const & secondRational)
{
	return ((firstRational.GetNumerator() == secondRational.GetNumerator()) &&
		(firstRational.GetDenominator() == secondRational.GetDenominator()));
}

bool const operator != (CRational const & firstRational, CRational const & secondRational)
{
	return (firstRational.GetNumerator() != secondRational.GetNumerator() ||
		firstRational.GetDenominator() != secondRational.GetDenominator());
}

//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////

bool const operator < (CRational const &firstRational, CRational const &secondRational)
{
	return firstRational.GetNumerator() * secondRational.GetDenominator() <
		secondRational.GetNumerator() * firstRational.GetDenominator();
}

bool const operator > (CRational const &firstRational, CRational const &secondRational)
{
	return firstRational.GetNumerator() * secondRational.GetDenominator() >
		secondRational.GetNumerator() * firstRational.GetDenominator();
}

bool const operator <= (CRational const &firstRational, CRational const &secondRational)
{
	return firstRational == secondRational || firstRational < secondRational;
}

bool const operator >= (CRational const &firstRational, CRational const &secondRational)
{
	return firstRational == secondRational || firstRational > secondRational;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////


std::ostream & operator<<(std::ostream & stream, CRational const & rationalNumber)
{
	stream << rationalNumber.GetNumerator() << '/' << rationalNumber.GetDenominator();
	return stream;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////
