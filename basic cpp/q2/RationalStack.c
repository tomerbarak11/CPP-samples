#include <iostream>
#include <stdio.h>
#include "RationalStack.h"

RationalStack::RationalStack()
:m_top(0)
{
	for(size_t i=0;i<STACK_CAPACITY;i++)
	{
		m_items[i]=0;
	}
}

bool Rational::push(Rational a_item)
{
	if(isFull()==true)
	{
		return false;
	}
	m_items[m_top+1]=a_item;
	m_top++;
	return true;
}

size_t Rational::push(Rational a_items[], size_t a_size)
{
	if(isFull()==true||RATIONAL_STACK_SIZE-a_size<m_top)
	{
		return false;
	}
	for(int i=0;i<a_size;i++)
	{
		m_items[i+m_top+1]=a_item;
		m_top++;
	}
	return true;
}

Rational Rational::pop()
{
	Rational r;
	if(isFull()==0)
	{
		return false;
	}
	r=m_items[m_top];
	m_top--;
	return r;
}

Rational Rational::top()
{
	/*if(isEmpty()==1)
	{
		return false;
	}*/
	return m_items[m_top];
}

bool Rational::isFull() const
{
	if(m_top==m_capacity)
	{
		return true;
	}
	return false;
}

bool Rational::isEmpty() const
{
	if(m_top==0)
	{
		return true;
	}
	return false;
}

size_t Rational::size() const
{
	return m_top;
}

void Rational::print() const
{
	for(size_t i=0;i<m_top;i++)
	{
		std::cout<<"Rational number number "
					<<i
					<<" = "
					<<m_items[i].m_numer
					<<"/"
					<<m_items[i].m_denom;					
	}
}

void Rational::trace() const
{
	for(size_t i=0;i<STACK_CAPACITY;i++)
	{
		std::cout<<"Rational number number "
					<<i
					<<" = "
					<<m_items[i].m_numer
					<<"/"
					<<m_items[i].m_denom;					
	}
}
