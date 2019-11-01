#include <iostream>
#include "Rational.h"
#include <stdio.h>
Rational::Rational()
:m_numer(0)
,m_denom(1)
{
}

Rational::Rational(int n_num)
:m_numer(n_num)
,m_denom(1)
{
}

Rational::Rational(int n_num,int m_den)
:m_numer(n_num)
,m_denom(m_den)
{
}

int Rational::numerator() const
{
	return m_numer;
}

int Rational::denominator() const
{
	return m_denom;
}

void Rational::print() const
{
	std::cout << "Rational number="
			<<m_numer
			<<"/"
			<<m_denom;
}

void Rational::mul(int a_numer)
{
	m_numer=m_numer*a_numer;
}

void Rational::mul(Rational a_other)
{
	m_numer=m_numer * a_other.m_numer;
	m_denom=m_denom * a_other.m_denom;	
}

void Rational::div(int a_numer)
{
	m_numer=m_numer/a_numer;
}

void Rational::div(Rational a_other)
{
	m_numer=m_numer * a_other.m_denom;
	m_denom=m_denom * a_other.m_numer;	
}

void Rational::add(int a_numer)
{
	m_numer=m_numer*m_denom+a_numer;
}

void Rational::add(Rational a_other)
{
	m_numer=m_numer*a_other.m_denom + m_denom*a_other.m_numer;
	m_denom=m_denom*a_other.m_denom;	
}

void Rational::sub(int a_numer)
{
	m_numer=m_numer-a_numer*m_denom;
}

void Rational::sub(Rational a_other)
{
	m_numer=m_numer*a_other.m_denom - a_other.m_numer*m_denom;
	m_denom=m_denom*a_other.m_denom;	
}

void Rational::reduce()
{
	int max=m_numer;
	int i;
	if(m_numer<m_denom)
	{
		max=m_denom;
	}
	for(i=max;i>=2;i--)
	{
		if(m_numer%i==0 && m_denom%i==0)
		{
			m_numer=m_numer/i;
			m_denom=m_denom/i;
			break;
		}
	}
}

