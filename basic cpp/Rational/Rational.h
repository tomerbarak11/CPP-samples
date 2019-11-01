#ifndef RATIONAL_OPS_H
#define RATIONAL_OPS_H
/**
 * @file	Rational.h
 * @brief	Day 3 - Class Exercise 3B - add operators
 *
 * 		Add operators to Rational class
 *	member
 *		op+=, op-=, op*=, op/=
 *		op<, op>, op==, op!=
 *	global
 *		op+, op-, op*, op/
 *		op<<
 */

#include <iostream>

class Rational
{
public:
	Rational(int a_numer = 0, int a_denom = 1);

	int numerator() const;
	int denominator() const;
	
	void print() const;
	void print(std::ostream& a_os = std::cout) const;

	void reduce();
	// Math
	void mul(int a_numer);
	void mul(Rational const& a_rational);

	void div(int a_numer);
	void div(Rational const& a_rational);

	void add(int a_numer);
	void add(Rational const& a_rational);

	void sub(int a_numer);
	void sub(Rational const& a_rtional);

	// Operators: members, modifying the object
	Rational& operator+= (Rational const& a_rhs);
	Rational& operator-= (Rational const& a_rhs);
	Rational& operator*= (Rational const& a_rhs);
	Rational& operator/= (Rational const& a_rhs);

	// Comparators
	bool operator==(Rational const& a_rhs) const;
	bool operator!=(Rational const& a_rhs) const;
	bool operator< (Rational const& a_rhs) const;
	bool operator> (Rational const& a_rhs) const;

private:
	int		m_numer;
	int		m_denom;
};

// Operators: global, allow compiler-generated conversions
Rational operator+(Rational const& a_lhs, Rational const& a_rhs);
Rational operator-(Rational const& a_lhs, Rational const& a_rhs);
Rational operator*(Rational const& a_lhs, Rational const& a_rhs);
Rational operator/(Rational const& a_lhs, Rational const& a_rhs);

std::ostream& operator<<(std::ostream& a_os, Rational const& a_rational);

inline Rational& Rational::operator+= (Rational const& a_rhs)
{
	add(a_rhs);
	return *this;
}

inline Rational& Rational::operator-= (Rational const& a_rhs)
{
	sub(a_rhs);
	return *this;
}

inline Rational& Rational::operator*= (Rational const& a_rhs)
{
	mul(a_rhs);
	return *this;
}

inline Rational& Rational::operator/= (Rational const& a_rhs)
{
	div(a_rhs);
	return *this;
}

inline bool Rational::operator==(Rational const& a_rhs) const
{
	Rational temp=a_rhs;
	temp.reduce();
	temp.m_numer=temp.m_numer*m_denom;
	temp.m_denom=temp.m_denom*m_numer;
	std::cout<<"\n";
	if(temp.m_numer==temp.m_denom)
	{
		return true;
	}
	return false;
}	

inline bool Rational::operator!=(Rational const& a_rhs) const
{
	if(a_rhs.m_numer==m_numer&&a_rhs.m_denom==m_denom)
	{
		return false;
	}
	return true;
}

inline bool Rational::operator<(Rational const& a_rhs) const
{
	float x;
	float y;
	
	x=(float)m_numer/(float)m_denom;
	y=(float)a_rhs.numerator()/(float)a_rhs.denominator();
	
	if(x<y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool Rational::operator>(Rational const& a_rhs) const
{
	float x=(float)m_numer/(float)m_denom;
	float y=(float)a_rhs.numerator()/(float)a_rhs.denominator();
	if(x>y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline Rational operator+(Rational const& a_lhs, Rational const& a_rhs)
{
	Rational res=a_lhs;
	res.add(a_rhs);
	return res;
}

inline Rational operator-(Rational const& a_lhs, Rational const& a_rhs)
{
	Rational res=a_lhs;
	res.sub(a_rhs);
	return res;
}

inline Rational operator*(Rational const& a_lhs, Rational const& a_rhs)
{
	Rational res=a_lhs;
	res.mul(a_rhs);
	return res;
}

inline Rational operator/(Rational const& a_lhs, Rational const& a_rhs)
{
	Rational res=a_lhs;
	res.div(a_rhs);
	return res;
}

inline std::ostream& operator<<(std::ostream& a_os, Rational const& a_rational)
{
	a_rational.print(a_os);
	return a_os;
}


#endif // RATIONAL_OPS_H
